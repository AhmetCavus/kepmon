#if defined(__linux__)
#include "PointerServiceEngines.hpp"
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <iostream>


PointerPos PointerServiceLinux::getPointerPosition() {
    Display* display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        std::cerr << "Unable to open X display" << std::endl;
        return PointerPos(-1, -1);
    }

    Window root = DefaultRootWindow(display);
    int rootX, rootY, winX, winY;
    unsigned int mask;
    Window child, rootReturn;

    if (XQueryPointer(display, root, &rootReturn, &child, &rootX, &rootY, &winX, &winY, &mask) == False) {
        std::cerr << "XQueryPointer failed" << std::endl;
        XCloseDisplay(display);
        return PointerPos(-1, -1);
    }

    XCloseDisplay(display);
    return PointerPos(rootX, rootY);
}

PointerBoundary PointerServiceLinux::getPointerBoundary() {
    Display* display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        return PointerBoundary(-1, -1);
    }

    Screen* screen = DefaultScreenOfDisplay(display);
    int width = screen->width;
    int height = screen->height;
    XCloseDisplay(display);

    return PointerBoundary(width, height);
}

bool PointerServiceLinux::SetPointerPos(PointerPos pos) {
    Display* display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        return false;
    }

    XWarpPointer(display, None, DefaultRootWindow(display), 0, 0, 0, 0, pos.x, pos.y);
    XFlush(display);
    XCloseDisplay(display);

    return true;
}

PointerCommandResult PointerServiceLinux::SendPointerInput(PointerCommand command) {
    Display* display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        return PointerCommandResult("Failed to open X display", false);
    }

    switch (command.action) {
        case PointerCommand::MOUSE_L_CLICK:
            XTestFakeButtonEvent(display, 1, True, CurrentTime);
            XTestFakeButtonEvent(display, 1, False, CurrentTime);
            break;
        case PointerCommand::MOUSE_L_DOUBLE_CLICK:
            XTestFakeButtonEvent(display, 1, True, CurrentTime);
            XTestFakeButtonEvent(display, 1, False, CurrentTime);
            XTestFakeButtonEvent(display, 1, True, CurrentTime);
            XTestFakeButtonEvent(display, 1, False, CurrentTime);
            break;
        case PointerCommand::MOUSE_R_CLICK:
            XTestFakeButtonEvent(display, 3, True, CurrentTime);
            XTestFakeButtonEvent(display, 3, False, CurrentTime);
            break;
        case PointerCommand::MOUSE_M_CLICK:
            XTestFakeButtonEvent(display, 2, True, CurrentTime);
            XTestFakeButtonEvent(display, 2, False, CurrentTime);
            break;
        default:
            XCloseDisplay(display);
            return PointerCommandResult("Unsupported command", false);
    }

    XFlush(display);
    XCloseDisplay(display);
    return PointerCommandResult("Success", true);
}
#endif
