#include "PointerCommandResult.hpp"

PointerCommandResult::PointerCommandResult(string message, bool success) {
	this->message = message;
	this->success = success;
}