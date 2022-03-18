#include "Logger.hpp"
#include "ClassFactory.hpp"
#include "coreclrhelper/peloader_helper.h"

BOOL STDMETHODCALLTYPE DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    // LOG_INFO("hello, world");
    (void)hModule;
    (void)ul_reason_for_call;
    (void)lpReserved;
    return TRUE;
}

extern "C"
{
    HRESULT STDMETHODCALLTYPE DllGetClassObject(REFCLSID /* rclsid */, REFIID riid, void** ppv)
    {
        LOG_INFO("factory");
        auto result = hellocoreclr();
        LOG_INFO("result[%d]", result);
#if 0
        return S_OK;
#else
        auto factory = new FeatLin::Profiler::ClassFactory();
        LOG_INFO("factory[%p]", factory);
        if (factory == nullptr)
        {
            return E_FAIL;
        }

        auto hrResult = factory->QueryInterface(riid, ppv);
        LOG_INFO("classObject[%p] hrResult[%d]", ppv, hrResult);
        return hrResult;
#endif
    }

    HRESULT STDMETHODCALLTYPE DllCanUnloadNow()
    {
        return S_OK;
    }
}
