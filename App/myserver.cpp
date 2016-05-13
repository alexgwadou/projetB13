#include "myserver.h"
#include "memory.h"
#include "cpu.h"
#include <QString>
#include <QLocale>

MyServer::MyServer(QObject *parent):
    QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,7595 ))
    {
        qDebug() << "Server coulnt start !";
    }
    else
    {
        qDebug() << "Server start !";
    }

}


void MyServer:: newConnection()
{

    Memory memory;
    cpu cpuu;

    QString messageMemoire;
    QString messageCpu;


    double mem = memory.memoryRequest();
    double cpu = cpuu.cpuPcent();

    QTcpSocket *socket = server->nextPendingConnection();
    messageMemoire = QString::number(mem, 'f', 6);
    messageCpu = QString::number(cpu, 'f', 6);


    socket->write("Hello cher client !\r\n");
    socket->write("Memory: " + messageMemoire.toLatin1() + "\r\n");
    socket->write("Taux de CPU: " + messageCpu.toLatin1() + "\r\n");

    socket->flush();

    socket->waitForBytesWritten(3000);
    socket->close();

}

