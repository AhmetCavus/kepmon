#include "PointerService.hpp"

#if defined(_WIN32)
class PointerServiceWin : public PointerService {
	public:
		PointerPos getPointerPosition();
		PointerBoundary getPointerBoundary();
		bool SetPointerPos(PointerPos pos);
		PointerCommandResult SendPointerInput(PointerCommand command);
};
#endif

#if defined(__linux__)
class PointerServiceLinux : public PointerService {
	public:
		PointerPos getPointerPosition();
		PointerBoundary getPointerBoundary();
		bool SetPointerPos(PointerPos pos);
		PointerCommandResult SendPointerInput(PointerCommand command);
};
#endif

#if defined(__APPLE__)
class PointerServiceMac : public PointerService {
	public:
		PointerPos getPointerPosition();
		PointerBoundary getPointerBoundary();
		bool SetPointerPos(PointerPos pos);
		PointerCommandResult SendPointerInput(PointerCommand command);
};
#endif
