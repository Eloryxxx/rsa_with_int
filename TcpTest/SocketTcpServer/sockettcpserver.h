#ifndef SOCKETTCPSERVER_H
#define SOCKETTCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
#include <functional>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "sockettcpserver_global.h"


struct sDefectItem
{
//    std::string strType;
//    std::string strXpos;
//    std::string strYpos;
//    std::string strWidth;
//    std::string strHeight;
    int strType;
    double strXpos;
    double strYpos;
    int strWidth;
    double strHeight;
};



class SOCKETTCPSERVERSHARED_EXPORT SocketTcpServer : public QWidget
{
    Q_OBJECT

public:
    SocketTcpServer(QWidget *parent = 0);
    ~SocketTcpServer();

private:
    QTcpServer *m_TCPServer;    //服务端
    QTcpSocket *m_TCPSocket;    //通信Socket
    std::function<void (const std::string &)> m_readCbk;    //回调函数，传输服务端接收的数据给上层

    std::vector<sDefectItem> m_vDefect;       //缺陷
    std::string m_strCiphertext;    //密文
    std::string m_strPlaintext;     //明文
    std::function<void (const std::string &)> m_rsaCbk;    //回调函数，RSA传输服务端接收的数据给上层

    int m_iEKey;   //公钥部分
    int m_iBKey;   //私钥部分
    int m_iNKey;   //公钥、私钥的另一组成部分

    QJsonArray m_jsonArray;
private slots:
    void ServerConnection(); //与客户端开始通信
    void ServerReadData();      //读取客户端命令并解析
    void ServerDisconnection(); //与客户端断连
public:
    void ServerSendData(const std::string &sendMsg);    //服务端发送数据接口
    void SetCallBackFun(std::function<void(const std::string &)> cbk);  //服务端接收数据的回调函数接口
    void Init(std::string &strIP,  int iPort);  //初始化IP和Port

    //以下为RSA的代码函数
    void InitDefectItem();
    void StructToJSon(std::vector<sDefectItem> vDefect, QJsonArray& jsonArray);
    void RSA_Encrytion(std::vector<sDefectItem> vDefect, int iEKey, int iNKey);//加密，返回加密后的信息以供显示使用
    void RSA_Decrytion(int iBKey, int iNKey);//解密
    std::string Modular_Exponent(std::string strMsg, int iBKey, int iNKey);
    //二进制转换
    int BianaryTransform(int iBKey, int iBinary[]);
    void SetRSACallBackFun(std::function<void(const std::string &)> cbk);
};

#endif // SOCKETTCPSERVER_H
