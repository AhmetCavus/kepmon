#if defined(__APPLE__)
#include "PointerServiceEngines.hpp"
#include <ApplicationServices/ApplicationServices.h>
#include <iostream>

PointerPos PointerServiceMac::getPointerPosition() {
	CGEventRef event = CGEventCreate(nullptr);
	CGPoint point = CGEventGetLocation(event);
	CFRelease(event);

	return PointerPos(point.x, point.y);
}

PointerBoundary PointerServiceMac::getPointerBoundary() {
	CGDirectDisplayID displayID = CGMainDisplayID();
	size_t width = CGDisplayPixelsWide(displayID);
	size_t height = CGDisplayPixelsHigh(displayID);

	return PointerBoundary(width, height);
}

bool PointerServiceMac::SetPointerPos(PointerPos pos) {
	CGPoint point = CGPointMake(pos.x, pos.y);
	CGWarpMouseCursorPosition(point);
	CGAssociateMouseAndMouseCursorPosition(true);

	return true;
}

PointerCommandResult PointerServiceMac::SendPointerInput(PointerCommand command) {
	CGEventRef eventDown, eventUp;

	switch (command.action) {
		case PointerCommand::MOUSE_L_CLICK:
			eventDown = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseDown, CGEventGetLocation(nullptr), kCGMouseButtonLeft);
			eventUp = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseUp, CGEventGetLocation(nullptr), kCGMouseButtonLeft);
			break;
		case PointerCommand::MOUSE_L_DOUBLE_CLICK:
			eventDown = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseDown, CGEventGetLocation(nullptr), kCGMouseButtonLeft);
			eventUp = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseUp, CGEventGetLocation(nullptr), kCGMouseButtonLeft);
			CGEventPost(kCGHIDEventTap, eventDown);
			CGEventPost(kCGHIDEventTap, eventUp);
			break;
		case PointerCommand::MOUSE_R_CLICK:
			eventDown = CGEventCreateMouseEvent(nullptr, kCGEventRightMouseDown, CGEventGetLocation(nullptr), kCGMouseButtonRight);
			eventUp = CGEventCreateMouseEvent(nullptr, kCGEventRightMouseUp, CGEventGetLocation(nullptr), kCGMouseButtonRight);
			break;
		case PointerCommand::MOUSE_M_CLICK:
			eventDown = CGEventCreateMouseEvent(nullptr, kCGEventOtherMouseDown, CGEventGetLocation(nullptr), kCGMouseButtonCenter);
			eventUp = CGEventCreateMouseEvent(nullptr, kCGEventOtherMouseUp, CGEventGetLocation(nullptr), kCGMouseButtonCenter);
			break;
		default:
			return PointerCommandResult("Unsupported command", false);
	}

	CGEventPost(kCGHIDEventTap, eventDown);
	CGEventPost(kCGHIDEventTap, eventUp);
	CFRelease(eventDown);
	CFRelease(eventUp);

	return PointerCommandResult("Success", true);
}
#endif
