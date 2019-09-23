#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <string>

namespace Ui {
class SocketClient;
}

class SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit SocketClient(QWidget *parent = 0);
    ~SocketClient();

private slots:

    void ClientRecvData();

    void ConnectSuccess();

    void DisConnect();

    void on_connectBtn_clicked();

    void on_sendBtn_clicked();

private:
    Ui::SocketClient *ui;
    QTcpSocket *m_clientSocket;
};

#endif // SOCKETCLIENT_H
