#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H



class SystemInfo
{

public:
    static SystemInfo& instancia();
    ~SystemInfo();
    virtual void init() = 0;
    virtual double cpuLoad() = 0;
    virtual double memoryUsed() = 0;
protected:
     explicit SystemInfo(); // does not allow assignation only subclases can see the constructor
private:
     SystemInfo (const SystemInfo &otro);
     SystemInfo &operator=(const SystemInfo &otro);
};

#endif // SYSTEMINFO_H
