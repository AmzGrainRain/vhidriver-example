#pragma once

#include "VirtualHID.h"

#include <Windows.h>
#include <vector>

class Mouse : public VirtualHID
{

  public:
    explicit Mouse();
    Mouse(const Mouse &) = delete;
    Mouse(Mouse &&) = delete;
    void operator=(const Mouse &) = delete;
    virtual ~Mouse() override = default;

    virtual void Initialize() override;
    virtual void Abort() override;

    virtual void LeftButtonDown();
    virtual void LeftButtonUp();
    virtual void LeftButtonClick();

    virtual void RightButtonDown();
    virtual void RightButtonUp();
    virtual void RightButtonClick();

    virtual void MiddleButtonDown();
    virtual void MiddleButtonUp();
    virtual void MiddleButtonClick();

    virtual void MoveCursor(POINT);
    virtual void MoveCursor(LONG x, LONG y);

  protected:
    enum Button
    {
        BUTTON_NONE = 0x00,
        BUTTON_LEFT = 0x01,
        BUTTON_RIGHT = 0x02,
        BUTTON_MIDDLE = 0x04
    };

    void PopulateRangeSpeedVector();
    int GetSpeedByRange(int range) const;

    static int GetRangeBySpeed(int speed);
    static POINT GetCurrentCursorPosition(LPDWORD error);

    BYTE buttons_{BUTTON_NONE};
    std::vector<int> range_speed_vec_;

    static const BYTE REPORT_ID{0x02};
    static const LONG MAX_ABSOLUTE_SPEED{127};
    static const int DISTANCE_TOLERANCE{3};
    static const int EPP_DISABLED{0};
    static const int EPP_ENABLED{1};
    static const int SENSITIVITY_MIN{1};
    static const int SENSITIVITY_MAX{20};

  private:
#pragma pack(1)
    struct Report
    {
        BYTE reportId;
        BYTE buttons;
        CHAR x;
        CHAR y;
    };
#pragma pack()

    virtual void SendMouseReport(CHAR xSpeed, CHAR ySpeed);
};
