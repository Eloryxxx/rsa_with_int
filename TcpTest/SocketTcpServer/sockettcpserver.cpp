#include "sockettcpserver.h"



SocketTcpServer::SocketTcpServer(QWidget *parent):
    QWidget(parent)
{
    m_TCPServer = new QTcpServer();
    //连接
    connect(m_TCPServer, SIGNAL(newConnection()), this, SLOT(ServerConnection()));
}

SocketTcpServer::~SocketTcpServer()
{
    if(m_TCPServer != nullptr)
    {
        delete m_TCPServer;
        m_TCPServer = nullptr;
    }
    if(m_TCPSocket != nullptr)
    {
        delete m_TCPSocket;
        m_TCPSocket = nullptr;
    }
}


void SocketTcpServer::ServerConnection()
{
    m_TCPSocket = m_TCPServer->nextPendingConnection();
    if(!m_TCPSocket)
    {
        QMessageBox::information(this, QString::fromUtf8("Socket网络通信"), QString::fromUtf8("未正确获取客户端连接"));
        return;
    }
    else
    {
        QMessageBox::information(this, QString::fromUtf8("Socket网络通信"), QString::fromUtf8("成功接受客户端的连接"));
        connect(m_TCPSocket, SIGNAL(readyRead()), this, SLOT(ServerReadData()));
        connect(m_TCPSocket, SIGNAL(disconnected()), this, SLOT(ServerDisconnection()));
    }
}

void SocketTcpServer::ServerReadData()
{
    QByteArray tcpReadResult = m_TCPSocket->readAll();
    std::string strMsg = tcpReadResult.toStdString();

    if(strMsg.find(",") != std::string::npos)//RSA加密解密，发送的形式为(e,n)
    {
        QString tmp_ekey = QString(tcpReadResult).mid(1, tcpReadResult.size()-2).split(',').at(0);
        QString tmp_nkey = QString(tcpReadResult).mid(1, tcpReadResult.size()-2).split(',').at(1);
        m_iEKey = tmp_ekey.toInt();
        m_iNKey = tmp_nkey.toInt();

        RSA_Encrytion(m_vDefect, m_iEKey, m_iNKey);
        m_rsaCbk(m_strCiphertext);//回调显示密文信息
    }
}

void SocketTcpServer::ServerDisconnection()
{
    QMessageBox::information(this, QString::fromUtf8("Socket网络通信"), QString::fromUtf8("与客户端断开连接"));
    m_TCPServer->close();
}

void SocketTcpServer::ServerSendData(const std::string &sendMsg)
{
    if(sendMsg.empty())
    {
        QMessageBox::information(this, QString::fromUtf8("Socket网络通信"), QString::fromUtf8("发送数据为空，请输入数据"));
        return;
    }

    if(m_TCPSocket->isValid())
    {
        int iSendRecv = m_TCPSocket->write(sendMsg.c_str());

        if(-1 == iSendRecv)
        {
            QMessageBox::information(this, QString::fromUtf8("Socket网络通信"), QString::fromUtf8("服务端发送数据失败！"));
        }
    }
    else
    {
        QMessageBox::information(this, QString::fromUtf8("Socket网络通信"), QString::fromUtf8("套接字无效"));
    }
}

void SocketTcpServer::SetCallBackFun(std::function<void (const std::string &)> cbk)
{
    m_readCbk = cbk;
}

void SocketTcpServer::Init(std::string &strIP, int iPort)
{
    InitDefectItem();
    if(!m_TCPServer->listen(QHostAddress::Any, iPort))
    {
        QMessageBox::information(this, QString::fromUtf8("Socket网络通信"), QString::fromUtf8("服务器监听失败"));
        return;
    }
    else
    {
        QMessageBox::information(this, QString::fromUtf8("Socket网络通信"), QString::fromUtf8("服务器监听成功"));
    }
}

void SocketTcpServer::InitDefectItem()
{
    sDefectItem sItem;
    sItem.strType = 12;
    sItem.strXpos = 11.7;
    sItem.strYpos = 9.7;
    sItem.strHeight = 17;
    sItem.strWidth = 6;

    m_vDefect.push_back(sItem);

    sItem.strType = 2;
    sItem.strXpos = 1.1;
    sItem.strYpos = 22;
    sItem.strHeight = 5.8;
    sItem.strWidth = 61;
    m_vDefect.push_back(sItem);

    m_strCiphertext.reserve(m_vDefect.size());
    m_strPlaintext.reserve(m_vDefect.size());

    qDebug()<<"初始化明文为：";
    for(int i = 0; i < m_vDefect.size(); i++)
    {
        qDebug()<<m_vDefect.at(i).strType<<" "<<m_vDefect.at(i).strXpos<<" "<<m_vDefect.at(i).strYpos<<" "<<
                   m_vDefect.at(i).strHeight<<" "<<m_vDefect.at(i).strWidth;
    }
}

void SocketTcpServer::StructToJSon(std::vector<sDefectItem> vDefect, QJsonArray& jsonArray)
{
    QJsonObject jsonObj;
    for(int i = 0; i <vDefect.size(); i++)
    {
        jsonObj.insert("type", QJsonValue(vDefect.at(i).strType));
        jsonObj.insert("xpos", QJsonValue(vDefect.at(i).strXpos));
        jsonObj.insert("ypos", QJsonValue(vDefect.at(i).strYpos));
        jsonObj.insert("height", QJsonValue(vDefect.at(i).strHeight));
        jsonObj.insert("width", QJsonValue(vDefect.at(i).strWidth));

        jsonArray.append(jsonObj);
    }
}

void SocketTcpServer::RSA_Encrytion(std::vector<sDefectItem> vDefect, int iEKey, int iNKey)
{
    StructToJSon(vDefect, m_jsonArray);
    qDebug()<<m_jsonArray;
    std::string strJS = QJsonDocument(m_jsonArray).toJson().toStdString();
    m_strCiphertext = Modular_Exponent(strJS, iEKey, iNKey);
    m_TCPSocket->write(QString::fromStdString(m_strCiphertext).toUtf8());
    qDebug()<<strJS.c_str();
    qDebug()<<"加密后："<<QString::fromStdString(m_strCiphertext);
}

void SocketTcpServer::RSA_Decrytion(int iDKey, int iNKey)
{
    m_strPlaintext = Modular_Exponent(m_strCiphertext, iDKey, iNKey);
    qDebug()<<"解密后明文为：";
    qDebug()<<m_strPlaintext.c_str();
    m_rsaCbk(m_strPlaintext);
}

/*
 * 二进制平方-乘算法
1、iBKey表示成二进制，并从右侧开始处理
2、初始值strMsg在iBKey的第一位时不做任何处理，记lResult = strMsg
3、在以后iBKey的每位中求strMsg的平方并赋值给strMsg，可记为lResult = (lResult * lResult)
4、当iBKey的二进制中有1时，lResult = lResult*strMsg
5、strRes为最终结果
*/
std::string SocketTcpServer::Modular_Exponent(std::string strMsg, int iBKey, int iNkey)
{
    int iBinary[1000];
    std::string strRes;
    strRes.resize(strMsg.size());

    int iBinnum = BianaryTransform(iBKey, iBinary) - 1;

    for(int j = 0; j < strMsg.size(); j++)
    {
        long lResult = 1;
        for (int i = iBinnum; i >= 0; i--)
        {
            lResult = (lResult * lResult) % iNkey;
            if (iBinary[i] == 1)
            {
                lResult = (lResult * strMsg.at(j)) % iNkey;
            }
        }

        strRes.at(j) = lResult;
    }

    return strRes;
}

int SocketTcpServer::BianaryTransform(int iBKey, int iBinary[])
{
    int iBinnum = 0;
    int iMod = 0;

    //转换为二进制，逆向暂存temp[]数组中
    while (iBKey != 0)
    {
        iMod = iBKey % 2;
        iBinary[iBinnum] = iMod;
        iBKey = iBKey / 2;
        iBinnum++;
    }

    //返回二进制数的位数
    return iBinnum;
}

void SocketTcpServer::SetRSACallBackFun(std::function<void (const std::string &)> cbk)
{
    m_rsaCbk = cbk;
}


