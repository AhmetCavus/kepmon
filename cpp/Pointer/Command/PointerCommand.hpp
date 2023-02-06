#include "../PointerCommandResult.hpp"

struct PointerCommand {
	enum Action {
		MOUSE_L_CLICK = 1,
		MOUSE_L_DOUBLE_CLICK = 2,
		MOUSE_R_CLICK = 3,
		MOUSE_M_CLICK = 4,
	};

	PointerCommand(Action action);

	Action action;
};