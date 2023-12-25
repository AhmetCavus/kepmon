#include <iostream>
#include "PointerServiceEngines.hpp"

#if defined(_WIN32)

//  global compilation flag configuring windows sdk headers
//  preventing inclusion of min and max macros clashing with <limits>
#define NOMINMAX 1

//  override byte to prevent clashes with <cstddef>
#define byte win_byte_override

#include <Windows.h> // gdi plus requires Windows.h
// ...includes for other windows header that may use byte...

//  Undefine byte macros so it won't collide with <cstddef> header content.
#undef byte

INPUT CreateInput(DWORD type) {
	INPUT input;
	ZeroMemory(&input, sizeof(input));
	input.type = type;
	return input;
}

PointerPos PointerServiceWin::getPointerPosition() {
	POINT pos;
	GetCursorPos(&pos);
	return PointerPos(pos.x, pos.y);
}

PointerBoundary PointerServiceWin::getPointerBoundary() {
	RECT display;
	const HWND hDisplay = GetDesktopWindow();
	GetWindowRect(hDisplay, &display);
	return PointerBoundary(display.right, display.bottom);
}

bool PointerServiceWin::SetPointerPos(PointerPos pos) {
	return SetCursorPos(pos.x, pos.y);
}

PointerCommandResult PointerServiceWin::SendPointerInput(PointerCommand command) {
	try
	{
		switch (command.action) {
			case PointerCommand::MOUSE_R_CLICK:
			{
				INPUT mouseDownInput = CreateInput(INPUT_MOUSE);
				mouseDownInput.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
				SendInput(1, &mouseDownInput, sizeof(INPUT));

				INPUT mouseUpInput = CreateInput(INPUT_MOUSE);
				mouseUpInput.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
				SendInput(1, &mouseUpInput, sizeof(INPUT));
				break;
			}
			case PointerCommand::MOUSE_L_CLICK:
			{
				INPUT mouseDownInput = CreateInput(INPUT_MOUSE);
				mouseDownInput.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
				SendInput(1, &mouseDownInput, sizeof(INPUT));

				INPUT mouseUpInput = CreateInput(INPUT_MOUSE);
				mouseUpInput.mi.dwFlags = MOUSEEVENTF_LEFTUP;
				SendInput(1, &mouseUpInput, sizeof(INPUT));
				break;
			}
			case PointerCommand::MOUSE_M_CLICK:
			{
				INPUT mouseDownInput = CreateInput(INPUT_MOUSE);
				mouseDownInput.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
				SendInput(1, &mouseDownInput, sizeof(INPUT));

				INPUT mouseUpInput = CreateInput(INPUT_MOUSE);
				mouseUpInput.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
				SendInput(1, &mouseUpInput, sizeof(INPUT));
				break;
			}
		}
		return PointerCommandResult("", true);
	}
	catch (const std::exception& ex)
	{
		string message = ex.what();
		return PointerCommandResult(message, false);
	}
}

#endif