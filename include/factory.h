#pragma once

#include <vector>

class TestFactory {

    // Singleton
public:
    static TestFactory* getInstance();
    static void releaseInstance();

private:
    static TestFactory* pGlobalInstance;

    // ------

public:
    TestFactory();
    ~TestFactory();

    std::vector<int>* getDevices();

    void registerTrackedDevice();
};