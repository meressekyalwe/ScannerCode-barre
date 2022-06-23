#ifndef MYPORT_H
#define MYPORT_H

#include <QSerialPort>
#include <QObject>

class MyPort : QObject
{
    Q_OBJECT

public:

    MyPort(QString portName);

    void openPort(QString portName);

    ~MyPort();

public slots:

    void receive();

private:

    QSerialPort* port;
};

#endif // MYPORT_H

