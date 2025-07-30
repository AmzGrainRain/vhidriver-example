#pragma once

#include "VirtualHID.h"

#include <Windows.h>

#include "VHID_KEYS.h"

class Keyboard : public VirtualHID
{

  public:
    explicit Keyboard();
    Keyboard(const Keyboard &) = delete;
    void operator=(const Keyboard &) = delete;
    virtual ~Keyboard() override = default;

    virtual void Initialize() override;

    virtual void Type(BYTE keyCode);

    virtual void Abort() override;

  protected:
    BYTE modifiers_{VHID_KEY_NONE};
    static const BYTE REPORT_ID{0x04};

  private:
#pragma pack(1)
    struct Report
    {
        BYTE reportId;
        BYTE modifiers;
        BYTE _reserved;
        BYTE keyCodes[6];
    };
#pragma pack()

    virtual void SendKeyboardReport(BYTE *keyCodes);
};
