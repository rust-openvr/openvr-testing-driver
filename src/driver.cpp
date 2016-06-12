#include <driver.h>

#include <log.h>
#include <hooks.h>
#include <factory.h>

vr::EVRInitError ServerProvider::Init(vr::IDriverLog *pDriverLog, vr::IServerDriverHost *pDriverHost,
                                      const char *pchUserDriverConfigDir, const char *pchDriverInstallDir) {

    // init
    Logger::getInstance()->registerLogInstance(pDriverLog);
    Logger::getInstance()->log("Init called");
    Logger::getInstance()->log(pchUserDriverConfigDir);
    Logger::getInstance()->log(pchDriverInstallDir);

    m_pHost = pDriverHost;

    // init service here


    return vr::EVRInitError::VRInitError_None;
}

void ServerProvider::Cleanup() {
    // stop serivce here

}

uint32_t ServerProvider::GetTrackedDeviceCount() {
    TestHooks::getInstance()->triggerHook(HOOK_ASKED_FOR_DEVICES);

    return TestFactory::getInstance()->getDevices()->size();
}

vr::ITrackedDeviceServerDriver *ServerProvider::GetTrackedDeviceDriver(uint32_t unWhich,
                                                                       const char *pchInterfaceVersion) {
    TestHooks::getInstance()->triggerHook(HOOK_ASKED_FOR_DEVICES);
    return nullptr;
}

vr::ITrackedDeviceServerDriver *ServerProvider::FindTrackedDeviceDriver(const char *pchId,
                                                                        const char *pchInterfaceVersion) {
    return nullptr;
}

void ServerProvider::RunFrame() {

}

bool ServerProvider::ShouldBlockStandbyMode() {
    return false;
}

void ServerProvider::EnterStandby() {

}

void ServerProvider::LeaveStandby() {

}
