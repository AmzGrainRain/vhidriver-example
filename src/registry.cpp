#include "registry.h"

RegistryService &RegistryService::GetInstance()
{
    static RegistryService instance;
    return instance;
}

int RegistryService::GetMouseSensivity() const
{
    DWORD size = 3;
    char buffer[3];

    LONG getValueResult = RegGetValueA(HKEY_CURRENT_USER, "Control Panel\\Mouse", "MouseSensitivity", RRF_RT_REG_SZ,
                                       nullptr, &buffer, &size);
    if (ERROR_SUCCESS != getValueResult)
    {
        return -1;
    }

    return atoi(buffer);
}

int RegistryService::GetMouseSpeed() const
{
    DWORD size = 2;
    char buffer[2];

    LONG getValueResult =
        RegGetValueA(HKEY_CURRENT_USER, "Control Panel\\Mouse", "MouseSpeed", RRF_RT_REG_SZ, nullptr, &buffer, &size);
    if (ERROR_SUCCESS != getValueResult)
    {
        return -1;
    }

    return atoi(buffer);
}
