#ifndef TCPTEST_H
#define TCPTEST_H

#include <QWidget>
#include <functional>
#include <iostream>
#include "sockettcpserver.h"
#include "sockettcpserver_global.h"

namespace Ui {
class TCPTest;
}

class TCPTest : public QWidget
{
    Q_OBJECT

public:
    explicit TCPTest(QWidget *parent = 0);
    ~TCPTest();
    void RecvData(const std::string &res);//接收数据

    void RecvRSAData(const std::string &res);

private slots:
    void on_SendBtn_clicked();//发送数据

    void on_InitBtn_clicked();//初始化端口号和IP

    void on_DecrytionBtn_clicked();


private:
    Ui::TCPTest *ui;
    SocketTcpServer *m_Server;
};

#endif // TCPTEST_H
