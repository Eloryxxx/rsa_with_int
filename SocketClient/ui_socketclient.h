/********************************************************************************
** Form generated from reading UI file 'socketclient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKETCLIENT_H
#define UI_SOCKETCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocketClient
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *IPlineEdit;
    QLineEdit *PortlineEdit;
    QTextEdit *sendtextEdit;
    QTextEdit *recvtextEdit;
    QPushButton *connectBtn;
    QPushButton *sendBtn;

    void setupUi(QWidget *SocketClient)
    {
        if (SocketClient->objectName().isEmpty())
            SocketClient->setObjectName(QStringLiteral("SocketClient"));
        SocketClient->resize(400, 300);
        label = new QLabel(SocketClient);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 54, 12));
        label_2 = new QLabel(SocketClient);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(3, 70, 81, 20));
        label_3 = new QLabel(SocketClient);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 54, 12));
        label_4 = new QLabel(SocketClient);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 240, 54, 12));
        IPlineEdit = new QLineEdit(SocketClient);
        IPlineEdit->setObjectName(QStringLiteral("IPlineEdit"));
        IPlineEdit->setGeometry(QRect(100, 30, 113, 20));
        PortlineEdit = new QLineEdit(SocketClient);
        PortlineEdit->setObjectName(QStringLiteral("PortlineEdit"));
        PortlineEdit->setGeometry(QRect(100, 70, 113, 20));
        sendtextEdit = new QTextEdit(SocketClient);
        sendtextEdit->setObjectName(QStringLiteral("sendtextEdit"));
        sendtextEdit->setGeometry(QRect(90, 120, 141, 71));
        recvtextEdit = new QTextEdit(SocketClient);
        recvtextEdit->setObjectName(QStringLiteral("recvtextEdit"));
        recvtextEdit->setGeometry(QRect(90, 210, 141, 71));
        connectBtn = new QPushButton(SocketClient);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));
        connectBtn->setGeometry(QRect(290, 30, 75, 23));
        sendBtn = new QPushButton(SocketClient);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(290, 90, 75, 23));

        retranslateUi(SocketClient);

        QMetaObject::connectSlotsByName(SocketClient);
    } // setupUi

    void retranslateUi(QWidget *SocketClient)
    {
        SocketClient->setWindowTitle(QApplication::translate("SocketClient", "SocketClient", Q_NULLPTR));
        label->setText(QApplication::translate("SocketClient", "\346\234\215\345\212\241\347\253\257IP\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("SocketClient", "\346\234\215\345\212\241\347\253\257\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("SocketClient", "\345\217\221\351\200\201\345\206\205\345\256\271\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("SocketClient", "\346\216\245\346\224\266\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        connectBtn->setText(QApplication::translate("SocketClient", "\350\277\236\346\216\245\346\234\215\345\212\241\347\253\257", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("SocketClient", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SocketClient: public Ui_SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKETCLIENT_H
