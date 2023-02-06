#include "../PointerPos.hpp"
#include "../Command/PointerCommand.hpp"
#include "../PointerBoundary.hpp"

class PointerService {
	public:
		virtual PointerPos getPointerPosition() = 0;
		virtual PointerBoundary getPointerBoundary() = 0;
		virtual bool SetPointerPos(PointerPos pos) = 0;
		virtual PointerCommandResult SendPointerInput(PointerCommand command) = 0;
};
