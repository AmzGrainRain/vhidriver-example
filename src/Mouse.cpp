#include "Mouse.h"

#include <stdexcept>

#include "registry.h"

Mouse::Mouse() : VirtualHID{L"\\\\?\\HID#VHIDriver&Col02#1"}
{
}

void Mouse::Initialize()
{
    if (IsInitialized())
        throw std::runtime_error{"ERROR_DOUBLE_INITIALIZATION"};
    PopulateRangeSpeedVector();
    VirtualHID::Initialize();
}

void Mouse::LeftButtonDown()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    buttons_ |= BUTTON_LEFT;
    SendMouseReport(0, 0);
}

void Mouse::LeftButtonUp()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    buttons_ &= ~BUTTON_LEFT;
    SendMouseReport(0, 0);
}

void Mouse::LeftButtonClick()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    LeftButtonDown();
    LeftButtonUp();
}

void Mouse::RightButtonDown()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    buttons_ |= BUTTON_RIGHT;
    SendMouseReport(0, 0);
}

void Mouse::RightButtonUp()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    buttons_ &= ~BUTTON_RIGHT;
    SendMouseReport(0, 0);
}

void Mouse::RightButtonClick()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    RightButtonDown();
    RightButtonUp();
}

void Mouse::MiddleButtonDown()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    buttons_ |= BUTTON_MIDDLE;
    SendMouseReport(0, 0);
}

void Mouse::MiddleButtonUp()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    buttons_ &= ~BUTTON_MIDDLE;
    SendMouseReport(0, 0);
}

void Mouse::MiddleButtonClick()
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    MiddleButtonDown();
    MiddleButtonUp();
}

void Mouse::MoveCursor(POINT point)
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    MoveCursor(point.x, point.y);
}

void Mouse::MoveCursor(LONG x, LONG y)
{
    if (!IsInitialized())
        throw std::runtime_error{"ERROR_NOT_INITIALIZED"};
    while (!IsAborted())
    {
        DWORD getCurrentCursorPositionError = ERROR_SUCCESS;
        POINT currentPoint = GetCurrentCursorPosition(&getCurrentCursorPositionError);
        if (ERROR_SUCCESS != getCurrentCursorPositionError)
        {
            throw std::runtime_error{"ERROR_CURSOR_PROCESSING"};
        }

        LONG distance = (LONG)sqrt(pow(x - currentPoint.x, 2) + pow(y - currentPoint.y, 2));
        if (distance <= DISTANCE_TOLERANCE)
        {
            return;
        }

        CHAR xSpeed = static_cast<CHAR>(GetSpeedByRange(abs(x - currentPoint.x)));
        xSpeed = (x > currentPoint.x ? xSpeed : -xSpeed);

        CHAR ySpeed = static_cast<CHAR>(GetSpeedByRange(abs(y - currentPoint.y)));
        ySpeed = (y > currentPoint.y ? ySpeed : -ySpeed);

        SendMouseReport(xSpeed, ySpeed);
        Sleep(1);
    }
}

void Mouse::Abort()
{
    VirtualHID::Abort();
}

void Mouse::PopulateRangeSpeedVector()
{
    range_speed_vec_.clear();
    int rangeIndex = 0;
    for (int speed = 0; speed < MAX_ABSOLUTE_SPEED + 1; ++speed)
    {
        int range = GetRangeBySpeed(speed);
        while (rangeIndex <= range)
        {
            range_speed_vec_.push_back(speed);
            ++rangeIndex;
        }
    }
}

int Mouse::GetSpeedByRange(int range) const
{
    if (range_speed_vec_.empty())
    {
        return static_cast<int>(sqrt(range));
    }

    if (range > range_speed_vec_.size() - 1)
    {
        range = static_cast<int>(range_speed_vec_.size()) - 1;
    }

    return range_speed_vec_.at(range);
}

int Mouse::GetRangeBySpeed(int speed)
{
    double sensitivityFactors[21] = {0,    0.03125, 0.625, 0.125, 0.25, 0.375, 0.5,  0.625, 0.75, 0.875, 1,
                                     1.25, 1.5,     1.75,  2,     2.25, 2.5,   2.75, 3,     3.25, 3.5};
    auto& rs = RegistryService::GetInstance();
    int sensitivity = rs.GetMouseSensivity();
    int eppSpeed = rs.GetMouseSpeed();

    if (sensitivity < SENSITIVITY_MIN || sensitivity > SENSITIVITY_MAX || eppSpeed < EPP_DISABLED ||
        eppSpeed > EPP_ENABLED)
    {
        return speed;
    }

    double sensitivityFactor = eppSpeed == EPP_ENABLED ? 1 : sensitivityFactors[sensitivity];
    double eppFactor = eppSpeed == EPP_ENABLED ? 0.25 * sensitivity : 1;
    double range = static_cast<double>(speed) * sensitivityFactor * eppFactor;
    return static_cast<int>(range);
}

POINT Mouse::GetCurrentCursorPosition(LPDWORD error)
{
    POINT currentPoint{0, 0};
    BOOL getCursorPosResult = GetCursorPos(&currentPoint);
    if (!getCursorPosResult && nullptr != error)
    {
        *error = GetLastError();
    }
    return currentPoint;
}

void Mouse::SendMouseReport(CHAR xSpeed, CHAR ySpeed)
{
    Report report;
    report.reportId = REPORT_ID;
    report.buttons = buttons_;
    report.x = xSpeed;
    report.y = ySpeed;

    SetOutputReport(&report, static_cast<DWORD>(sizeof(Report)));
}
