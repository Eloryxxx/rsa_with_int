#ifndef SOCKETTCPSERVER_H
#define SOCKETTCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include "sockettcpserver_global.h"
#include <functional>
#include <iostream>

class SOCKETTCPSERVERSHARED_EXPORT SocketTcpServer : public QObject
{
    Q_OBJECT

public:
    SocketTcpServer(QObject *parent = 0);
    ~SocketTcpServer();
    void Init();

private:
    QTcpServer *m_TCPServer;
    QTcpSocket *m_TCPSocket;
    std::string m_sReadData;
    bool m_bReadSuccess;
    std::function<void (const std::string &)> m_readCbk;

private slots:
    void ServerNewConnection(); //与客户端开始通信
    void ServerReadData();      //读取客户端命令并解析
    void ServerDisconnection(); //与客户端断连
public:
    void ServerSendData(const std::string &sendMsg);
    //std::string GetData();
    void SetCallBackFun(std::function<void(const std::string &)> cbk);
};

#endif // SOCKETTCPSERVER_H
