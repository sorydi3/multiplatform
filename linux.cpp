#include "linux.h"

Linux::Linux() : SystemInfo()
{

}

void Linux::init()
{
    cargaCpuUltimo = obtenerDatosCpu();
}

double Linux::cpuLoad()
{
    /*
    QVector<qulonglong>  datosViejos = cargaCpuUltimo;
    QVector<qulonglong>  datosnuevos = obtenerDatosCpu();
    cargaCpuUltimo = datosnuevos;

    qulonglong userActual = datosnuevos[0]-datosViejos[0];
    qulonglong userNiceActual = datosnuevos[1] -datosViejos[1];
    qulonglong systemActual = datosnuevos[2]-datosViejos[2];
    qulonglong idleActual = datosnuevos[3]-datosViejos[3];

    qulonglong sistema =userActual+userNiceActual+systemActual;

    double porcentaje = (sistema-idleActual) *100 / sistema;
    return qBound(0.0,porcentaje,100.0);
    */
    return 0.0;
}

double Linux::memoryUsed()
{

}

QVector<qulonglong> Linux::obtenerDatosCpu()
{
    /*
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);

    QByteArray primeraLinia = file.readLine();
    file.close();

    qulonglong user,userNice,system,idle;

    QTextStream texto(primeraLinia);

    texto>>user;
    texto>>userNice;
    texto>>system;
    texto>>idle;

    QVector<qulonglong> datos;

    datos.append(user);
    datos.append(userNice);
    datos.append(system);
    datos.append(idle);
    */

   // return datos;

     QVector<qulonglong> datos;


    return datos;

}
