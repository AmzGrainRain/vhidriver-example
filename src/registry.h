#pragma once

#include <Windows.h>

class RegistryService
{

  public:
    static RegistryService &GetInstance();

    int GetMouseSensivity() const;
    int GetMouseSpeed() const;

  private:
    explicit RegistryService() = default;
    RegistryService(const RegistryService &) = delete;
    void operator=(const RegistryService &) = delete;
    virtual ~RegistryService() = default;
};
