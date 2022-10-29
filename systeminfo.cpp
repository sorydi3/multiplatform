#include "systeminfo.h"
#include "window.h"
#include "linux.h"

#ifdef Q_OS_WIN
    #include "window.h"
#elif defined Q_OS_LINUX
    qDebug() << "Estamos en linux";
#endif

SystemInfo &SystemInfo::instancia(){
    #ifdef Q_OS_WIN
        static Window instancia;
    #elif defined Q_OS_LINUX
        static Linux instancia;
    #endif

    return instancia;
}

SystemInfo::SystemInfo(){

}

SystemInfo::~SystemInfo(){

}

SystemInfo &SystemInfo::operator=(const SystemInfo &otro)
{

}
