#include "tcptest.h"
#include "ui_tcptest.h"

TCPTest::TCPTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TCPTest)
{
    ui->setupUi(this);
    m_Server = new SocketTcpServer();
    m_Server->SetCallBackFun(std::bind(&TCPTest::RecvData, this, std::placeholders::_1));
    m_Server->SetRSACallBackFun(std::bind(&TCPTest::RecvRSAData, this, std::placeholders::_1));
}

TCPTest::~TCPTest()
{
    delete ui;
    delete m_Server;
}

void TCPTest::RecvData(const std::string &res)
{
    ui->Recvdata_textEdit->setText(QString::fromStdString(res));
}

void TCPTest::RecvRSAData(const std::string &res)
{
    ui->Recvdata_textEdit->append(QString::fromStdString(res));
}


void TCPTest::on_SendBtn_clicked()
{
    QString strSendMsg = ui->Senddata_textEdit->toPlainText();
    m_Server->ServerSendData(strSendMsg.toStdString().c_str());
}

void TCPTest::on_InitBtn_clicked()
{
    std::string strIP = ui->IPlineEdit->text().toStdString();
    int iPort = ui->PortlineEdit->text().toInt();
    m_Server->Init(strIP, iPort);
}

void TCPTest::on_DecrytionBtn_clicked()
{
    int d = 97;//e 49
    int n = 133;
    m_Server->RSA_Decrytion(d, n);
}
