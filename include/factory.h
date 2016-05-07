#pragma once

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

    void registerTrackedDevice();
};