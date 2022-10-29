#include "window.h"

Window::Window() : SystemInfo() // call the construstor of the super class
{

}

Window::~Window()
{

}

void Window::init()
{
    cargaCpuUltimo = obtenerDatosCpu();
}

double Window::cpuLoad()
{


    QVector<qulonglong>  datosViejos = cargaCpuUltimo;
   QVector<qulonglong>  datosnuevos = obtenerDatosCpu();
   cargaCpuUltimo = datosnuevos;

    qulonglong idleActual = datosnuevos[0]-datosViejos[0];
    qulonglong kernelActual = datosnuevos[1]-datosViejos[1];
    qulonglong userActual = datosnuevos[2]-datosViejos[2];

    qulonglong sistema = kernelActual + userActual;

    double porcentaje = (sistema-idleActual) *100 / sistema;
    return qBound(0.0,porcentaje,100.0);
}

double Window::memoryUsed()
{
    MEMORYSTATUSEX estadoMemoria;
    estadoMemoria.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&estadoMemoria);
    qulonglong memoriaUtilizada =  estadoMemoria.ullTotalPhys-estadoMemoria.ullAvailPhys;
    return (double) (memoriaUtilizada / estadoMemoria.ullTotalPhys) * 100;
}

QVector<qulonglong> Window::obtenerDatosCpu() const
{
    FILETIME idle,kernel,user;
    GetSystemTimes(&idle, &kernel, &user);

    QVector<qulonglong> datodevuelto;

    datodevuelto.append(convertirFileTime(idle));
    datodevuelto.append(convertirFileTime(kernel));
    datodevuelto.append(convertirFileTime(user));

    return datodevuelto;
}

qulonglong Window::convertirFileTime(const FILETIME &filetime) const
{
    ULARGE_INTEGER largeInteger;

    largeInteger.LowPart = filetime.dwLowDateTime;
    largeInteger.HighPart = filetime.dwHighDateTime;

    return largeInteger.QuadPart;
}
