#include "socketclient.h"
#include "ui_socketclient.h"

SocketClient::SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocketClient)
{
    ui->setupUi(this);
    ui->PortlineEdit->setText("1122");
    ui->IPlineEdit->setText("127.0.0.1");
    m_clientSocket = new QTcpSocket();
}

SocketClient::~SocketClient()
{
    delete ui;

    if(m_clientSocket != nullptr)
    {
        delete m_clientSocket;
        m_clientSocket = nullptr;
    }
}

void SocketClient::ClientRecvData()
{
    QByteArray result = m_clientSocket->readAll();
    std::string strMsg = result.toStdString();
    qDebug()<<strMsg.c_str();
    ui->recvtextEdit->append(QString::fromStdString(strMsg));
}

void SocketClient::ConnectSuccess()
{
    ui->connectBtn->setEnabled(false);
}

void SocketClient::DisConnect()
{
    m_clientSocket->disconnectFromHost();
    m_clientSocket->close();    //释放socket
    ui->connectBtn->setEnabled(true);
}

void SocketClient::on_connectBtn_clicked()
{
    //检测链接成功信号关联槽函数
    connect(m_clientSocket, SIGNAL(connected()), this, SLOT(ConnectSuccess()));
    connect(m_clientSocket, SIGNAL(disconnected()), this, SLOT(DisConnect()));
    QString ip = ui->IPlineEdit->text();
    int port = ui->PortlineEdit->text().toInt();
    m_clientSocket->connectToHost(ip, port);

    if(!m_clientSocket->waitForConnected(30000))
    {
        QMessageBox::information(this, QString::fromLocal8Bit("QT网络通信"), QString::fromLocal8Bit("连接服务端失败"));
        return;
    }
    connect(m_clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));
}

//RSA加密解密，发送的形式为(e,n)
void SocketClient::on_sendBtn_clicked()
{
    QString strSendMsg = ui->sendtextEdit->toPlainText();
    int iSendRet = m_clientSocket->write(strSendMsg.toUtf8().data());
    if(iSendRet == -1)
    {
        QMessageBox::information(this, QString::fromLocal8Bit("QT网络通信"), QString::fromLocal8Bit("向服务端发送数据失败"));
        return;
    }
}

