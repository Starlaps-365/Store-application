#ifndef UDP_H
#define UDP_H

#include <QtWidgets>

class QLineEdit;
class QTextEdit;
class QUdpSocket;

class UDPListen : public QWidget
{
    Q_OBJECT
public:
    explicit UDPListen(QWidget *parent = 0);
signals:

public slots:
    void startListening();
    void processPendingDatagrams();
private:
    QTextEdit* display;
    QUdpSocket *socket;
    QString line;
};

#endif // UDP_H
