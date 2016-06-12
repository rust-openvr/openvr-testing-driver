#pragma once

#define HOOK_ASKED_FOR_DEVICES 0

class TestHooks {

    // Singleton
public:
    static TestHooks* getInstance();
    static void releaseInstance();

private:
    static TestHooks* pGlobalInstance;

    // ------

public:
    void registerHook(int hook_id);
    void triggerHook(int hook_id);

};