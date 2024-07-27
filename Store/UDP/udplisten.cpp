#include "udplisten.h"
#include <QLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>

UDPListen::UDPListen(QWidget *parent) : QWidget(parent)
{
    socket = 0;

    QVBoxLayout* layout = new QVBoxLayout(this);
    QPushButton* listen = new QPushButton("&Listen");
    display = new QTextEdit();
    display->setReadOnly(true);
    layout->addWidget(listen);
    layout->addWidget(display);
    resize(300, 500);

    connect(listen, SIGNAL(clicked()), this, SLOT(startListening()));
}

void UDPListen::startListening()
{
    display->setText("Started listening...");
    socket = new QUdpSocket(this);
    socket->bind(34567);
    connect(socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

void UDPListen::processPendingDatagrams()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    socket->readDatagram(buffer.data(), buffer.size());

    QDataStream stream(buffer);
    stream.setVersion(QDataStream::Qt_4_0);
    stream >> line;
    display->append("");
    display->append(line);
}
