#ifndef WINDOW_H
#define WINDOW_H

#include "systeminfo.h"
#include <windows.h>
#include <QtGlobal>
#include <QVector>


class Window : public SystemInfo
{

public:
    Window();
    ~Window();
    // SystemInfo interface
public:
    void init();
    double cpuLoad();
    double memoryUsed();
private:
   QVector<qulonglong> cargaCpuUltimo;
   QVector<qulonglong> obtenerDatosCpu() const;

   qulonglong convertirFileTime(const FILETIME &filetime) const;
};

#endif // WINDOW_H
