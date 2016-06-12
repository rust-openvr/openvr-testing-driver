#pragma once

#include <openvr_driver.h>
#include <string.h>

// ------------------------------------------------------------------------------------

#define HMD_DLL_EXPORT extern "C" __declspec( dllexport )

HMD_DLL_EXPORT
void *HmdDriverFactory( const char *pInterfaceName, int *pReturnCode )
{
    if( 0 == strcmp( IServerTrackedDeviceProvider_Version, pInterfaceName ) )
    {
        return new ServerProvider();
    }
    if( 0 == strcmp( IClientTrackedDeviceProvider_Version, pInterfaceName ) )
    {
        //return <global for client driver provider>;
    }

    if( pReturnCode )
        *pReturnCode = HmdError_Init_InterfaceNotFound;

    return NULL;
}

// ------------------------------------------------------------------------------------

class ServerProvider : vr::IServerTrackedDeviceProvider {
private:
    vr::IServerDriverHost* m_pHost;

public:
    virtual uint32_t GetTrackedDeviceCount();

    virtual void Cleanup();

    virtual vr::EVRInitError Init(vr::IDriverLog *pDriverLog, vr::IServerDriverHost *pDriverHost,
                                  const char *pchUserDriverConfigDir, const char *pchDriverInstallDir);

    virtual vr::ITrackedDeviceServerDriver *GetTrackedDeviceDriver(uint32_t unWhich, const char *pchInterfaceVersion);

    virtual vr::ITrackedDeviceServerDriver *FindTrackedDeviceDriver(const char *pchId, const char *pchInterfaceVersion);

    virtual void RunFrame();

    virtual bool ShouldBlockStandbyMode();

    virtual void EnterStandby();

    virtual void LeaveStandby();
};

// ------------------------------------------------------------------------------------
