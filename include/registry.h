#pragma once

#include <vector>

#include <case.h>

class TestCaseRegistry {

    // Singleton
public:
    static TestCaseRegistry* getInstance();
    static void releaseInstance();

private:
    static TestCaseRegistry* pGlobalInstance;

    // ------

public:
    TestCaseRegistry();
    ~TestCaseRegistry()();

    template <class T>
    void registerTestCase<T>();

private:
    std::vector<TestCase*> m_Registry;

};