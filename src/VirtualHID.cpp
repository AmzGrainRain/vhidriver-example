#include "VirtualHID.h"

#include <cfgmgr32.h>
#include <hidsdi.h>
#include <stdexcept>

VirtualHID::VirtualHID(PCWSTR device_interface) : device_interface_{device_interface}
{
}

void VirtualHID::Initialize()
{
    if (IsInitialized())
        throw std::runtime_error{"ERROR_DOUBLE_INITIALIZATION"};

    GUID guid;
    HidD_GetHidGuid(&guid);

    ULONG device_interface_list_size = 0;
    CONFIGRET configret = CM_Get_Device_Interface_List_Size(&device_interface_list_size, &guid, nullptr,
                                                            CM_GET_DEVICE_INTERFACE_LIST_PRESENT);
    if (CR_SUCCESS != configret)
    {
        throw std::runtime_error{"ERROR_GETTING_DEVICE_INTERFACE_LIST_SIZE"};
    }

    if (device_interface_list_size <= 1)
    {
        throw std::runtime_error{"ERROR_EMPTY_DEVICE_INTERFACE_LIST"};
    }

    PWSTR device_interface_list = static_cast<PWSTR>(malloc(device_interface_list_size * sizeof(WCHAR)));
    if (device_interface_list == nullptr)
    {
        throw std::runtime_error{"ERROR_ALLOCATING_DEVICE_INTERFACE_LIST"};
    }
    ZeroMemory(device_interface_list, device_interface_list_size * sizeof(WCHAR));

    if (CM_Get_Device_Interface_List(&guid, nullptr, device_interface_list, device_interface_list_size,
                                     CM_GET_DEVICE_INTERFACE_LIST_PRESENT) != CR_SUCCESS)
    {
        free(device_interface_list);
        throw std::runtime_error{"ERROR_GETTING_DEVICE_INTERFACE_LIST"};
    }

    device_handle_ = INVALID_HANDLE_VALUE;
    size_t device_interface_length = wcslen(device_interface_);
    for (PWSTR current = device_interface_list; *current; current += wcslen(current) + 1)
    {
        if (wcsncmp(current, device_interface_, device_interface_length) != 0)
        {
            continue;
        }

        device_handle_ = CreateFile(current, GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
        if (device_handle_ == INVALID_HANDLE_VALUE)
        {
            continue;
        }

        break;
    }

    free(device_interface_list);
    if (device_handle_ == INVALID_HANDLE_VALUE)
    {
        throw std::runtime_error{"ERROR_INVALID_HANDLE_VALUE"};
    }
}

bool VirtualHID::IsInitialized() const
{
    return device_handle_ != INVALID_HANDLE_VALUE;
}

bool VirtualHID::IsAborted() const
{
    return device_handle_ == NULL;
}

void VirtualHID::Abort()
{
    if (device_handle_ != NULL && device_handle_ != INVALID_HANDLE_VALUE)
    {
        CloseHandle(device_handle_);
        device_handle_ = NULL;
    }
}

void VirtualHID::SetOutputReport(PVOID data, DWORD size)
{
    if (!HidD_SetOutputReport(device_handle_, data, size))
    {
        throw std::runtime_error{"ERROR_SET_OUTPUT_REPORT"};
    }
}
