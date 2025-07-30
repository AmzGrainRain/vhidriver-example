#pragma once

#include <Windows.h>

class VirtualHID
{

  public:
    explicit VirtualHID(PCWSTR deviceInterface);
    VirtualHID(const VirtualHID &) = delete;
    VirtualHID(VirtualHID &&) = delete;
    void operator=(const VirtualHID &) = delete;
    virtual ~VirtualHID() = default;

    virtual void Initialize();
    virtual void Abort();

    bool IsInitialized() const;
    bool IsAborted() const;

  protected:
    void SetOutputReport(PVOID data, DWORD size);

  private:
    PCWSTR device_interface_{NULL};
    HANDLE device_handle_{NULL};
    bool is_initialized_{false};
    bool is_aborted_{false};
};
