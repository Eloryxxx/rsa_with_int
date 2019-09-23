#include "tcptest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TCPTest w;
    w.show();

    return a.exec();
}
