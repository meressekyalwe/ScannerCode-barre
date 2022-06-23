#include "myport.h"
#include <QDebug>

MyPort::MyPort(QString portName)
{
    port = new QSerialPort(portName);

    // configuration
    port->setBaudRate(QSerialPort::Baud9600);
    //port->setDataBits(QSerialPort::Data8);
    //port->setParity(QSerialPort::NoParity);
    //port->setStopBits(QSerialPort::OneStop);
    //port->setFlowControl(QSerialPort::NoFlowControl);

     openPort(portName);
}

void MyPort::openPort(QString portName)
{

    // configuration du port ...
    if (port->open(QIODevice::ReadOnly))
    {
        // on connecte le signal readyRead() au slot recevoir()
        connect(port, SIGNAL(readyRead()), this, SLOT(receive()));

    }
    else
    {
        qDebug() << port->errorString();
    }
}

void MyPort::receive()
{
    QByteArray data = port->readAll();
    qDebug() << "data received:" << data;
}

MyPort::~MyPort()
{
    port->close();
    delete port;
}

