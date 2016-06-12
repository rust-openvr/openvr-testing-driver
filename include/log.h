#pragma once

#include <openvr_driver.h>

class Logger {
    // Singleton
public:
    static Logger* getInstance();
    static void releaseInstance();

private:
    static Logger* pGlobalInstance;

    // ------

private:
    vr::IDriverLog* m_pLog;

public:
    void registerLogInstance(vr::IDriverLog* pLog);

    void log(const char* message);
};
