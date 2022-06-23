#include <QCoreApplication>
#include <QSerialPortInfo>
#include <QDebug>

#include "myport.h"

//http://tvaira.free.fr/projets/activites/activite-port-serie-qt.html

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QList<QSerialPortInfo> listePorts;
    QStringList listePortsDisponibles;

    listePorts = QSerialPortInfo::availablePorts();
    for (int i=0; i < listePorts.size();i++)
    {
      QSerialPortInfo info = listePorts.at(i);
      {
        if(!info.manufacturer().isEmpty())

        {
            listePortsDisponibles << info.description() + " (" + info.portName() + ")";
        }


        else
        {
            listePortsDisponibles << info.portName();

        }
      }
    }

    qDebug() << "listePortsDisponibles" << listePortsDisponibles;


    //MyPort port("COM6");

    return a.exec();
}
