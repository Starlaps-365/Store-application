#include <QApplication>
#include "udplisten.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    UDPListen chat;
    chat.setWindowTitle("UDP Listen");
    chat.show();
    return app.exec();
}
