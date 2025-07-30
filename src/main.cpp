#include <iostream>
#include <string>

#include "Mouse.h"
#include "Keyboard.h"

int main()
{
    Mouse mouse;
    try {
        mouse.Initialize();
    } catch (const std::runtime_error &e) {
        std::cout << std::string("Mouse initialization: ") + e.what() << std::endl;
        return EXIT_FAILURE;
    }

    Keyboard keyboard;
    try {
        keyboard.Initialize();
    } catch (const std::runtime_error &e) {
        std::cout << std::string("Keyboard initialization: ") + e.what() << std::endl;
        return EXIT_FAILURE;
    }

    Sleep(5000);

    mouse.MoveCursor(136, 271);

    Sleep(500);

    mouse.MoveCursor(56, 315);

    Sleep(500);

    mouse.MoveCursor(283, 350);

    Sleep(500);

    mouse.MoveCursor(275, 271);

    Sleep(500);

    return EXIT_SUCCESS;
}
