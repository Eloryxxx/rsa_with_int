/********************************************************************************
** Form generated from reading UI file 'tcptest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPTEST_H
#define UI_TCPTEST_H

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

class Ui_TCPTest
{
public:
    QTextEdit *Recvdata_textEdit;
    QTextEdit *Senddata_textEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *SendBtn;
    QPushButton *InitBtn;
    QLineEdit *IPlineEdit;
    QLineEdit *PortlineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *DecrytionBtn;

    void setupUi(QWidget *TCPTest)
    {
        if (TCPTest->objectName().isEmpty())
            TCPTest->setObjectName(QStringLiteral("TCPTest"));
        TCPTest->resize(435, 330);
        Recvdata_textEdit = new QTextEdit(TCPTest);
        Recvdata_textEdit->setObjectName(QStringLiteral("Recvdata_textEdit"));
        Recvdata_textEdit->setGeometry(QRect(70, 80, 131, 111));
        Senddata_textEdit = new QTextEdit(TCPTest);
        Senddata_textEdit->setObjectName(QStringLiteral("Senddata_textEdit"));
        Senddata_textEdit->setGeometry(QRect(73, 200, 131, 121));
        label = new QLabel(TCPTest);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 140, 54, 12));
        label_2 = new QLabel(TCPTest);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 250, 54, 12));
        SendBtn = new QPushButton(TCPTest);
        SendBtn->setObjectName(QStringLiteral("SendBtn"));
        SendBtn->setGeometry(QRect(280, 240, 75, 23));
        InitBtn = new QPushButton(TCPTest);
        InitBtn->setObjectName(QStringLiteral("InitBtn"));
        InitBtn->setGeometry(QRect(270, 20, 75, 23));
        IPlineEdit = new QLineEdit(TCPTest);
        IPlineEdit->setObjectName(QStringLiteral("IPlineEdit"));
        IPlineEdit->setGeometry(QRect(80, 10, 113, 20));
        PortlineEdit = new QLineEdit(TCPTest);
        PortlineEdit->setObjectName(QStringLiteral("PortlineEdit"));
        PortlineEdit->setGeometry(QRect(80, 40, 113, 20));
        label_3 = new QLabel(TCPTest);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 10, 31, 16));
        label_4 = new QLabel(TCPTest);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 54, 12));
        DecrytionBtn = new QPushButton(TCPTest);
        DecrytionBtn->setObjectName(QStringLiteral("DecrytionBtn"));
        DecrytionBtn->setGeometry(QRect(270, 70, 75, 23));

        retranslateUi(TCPTest);

        QMetaObject::connectSlotsByName(TCPTest);
    } // setupUi

    void retranslateUi(QWidget *TCPTest)
    {
        TCPTest->setWindowTitle(QApplication::translate("TCPTest", "TCPTest", Q_NULLPTR));
        label->setText(QApplication::translate("TCPTest", "\346\216\245\346\224\266\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("TCPTest", "\345\217\221\351\200\201\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        SendBtn->setText(QApplication::translate("TCPTest", "\345\217\221\351\200\201", Q_NULLPTR));
        InitBtn->setText(QApplication::translate("TCPTest", "\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        label_3->setText(QApplication::translate("TCPTest", "IP\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("TCPTest", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        DecrytionBtn->setText(QApplication::translate("TCPTest", "\350\247\243\345\257\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TCPTest: public Ui_TCPTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPTEST_H
