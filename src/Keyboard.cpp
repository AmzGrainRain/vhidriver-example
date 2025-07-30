#include "Keyboard.h"

#include <stdexcept>

Keyboard::Keyboard() : VirtualHID{L"\\\\?\\HID#VHIDriver&Col04#1"}
{
}

void Keyboard::Initialize()
{
    if (IsInitialized())
        throw std::runtime_error{"ERROR_DOUBLE_INITIALIZATION"};
    VirtualHID::Initialize();
}

void Keyboard::Type(BYTE keyCode)
{
    BYTE keyCodes[6] = {VHID_KEY_NONE};

    keyCodes[0] = keyCode;
    SendKeyboardReport(keyCodes);

    keyCodes[0] = VHID_KEY_NONE;
    SendKeyboardReport(keyCodes);
}

void Keyboard::Abort()
{
    VirtualHID::Abort();
}

void Keyboard::SendKeyboardReport(BYTE *keyCodes)
{
    Report report;
    report.reportId = REPORT_ID;
    report.modifiers = modifiers_;
    report._reserved = 0x00;
    std::memcpy(report.keyCodes, keyCodes, 6);

    SetOutputReport(&report, static_cast<DWORD>(sizeof(Report)));
}
