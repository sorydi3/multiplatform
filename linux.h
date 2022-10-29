#ifndef LINUX_H
#define LINUX_H

#include "systeminfo.h"
#include <QtGlobal>
#include <QVector>
#include <QFile>
#include <QTextStream>

class Linux : public SystemInfo
{
public:
    Linux();
    ~Linux();
    // SystemInfo interface
public:
    void init() override;
    double cpuLoad() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cargaCpuUltimo;
    QVector<qulonglong> obtenerDatosCpu();
};

#endif // LINUX_H
