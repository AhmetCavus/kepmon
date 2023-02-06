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
