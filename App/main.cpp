#include <QCoreApplication>
#include "myserver.h"
#include "memory.h"
#include "cpu.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer Server;
    Memory memory;
    cpu cpu;


    double m;
    double v;
    m = memory.memoryRequest();
    v = cpu.cpuPcent();
    printf("LA memoire est de :  %F\n", m);
    printf("Le Pcentage CPU instantanne est %g\n", v);

    return a.exec();
}

