#include <napi.h>
#include <iostream>
#include <string>
#include "Pointer/Service/PointerServiceLocator.hpp"

PointerServiceLocator locator;
PointerService* service = locator.Resolve();

Napi::Object GetPointerPosition(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	// std::string name = info[0].ToString();

	PointerPos result = service->getPointerPosition();

	Napi::Object pointerPos = Napi::Object::New(env);
	pointerPos.Set("x", result.x);
	pointerPos.Set("y", result.y);

	return pointerPos;
}

Napi::Object GetPointerBoundary(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	PointerBoundary result = service->getPointerBoundary();

	Napi::Object pointerBoundary = Napi::Object::New(env);
	pointerBoundary.Set("xLimit", result.xLimit);
	pointerBoundary.Set("yLimit", result.yLimit);
	return pointerBoundary;
}

Napi::Boolean SetPointerPosition(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	float x = info[0].ToNumber();
	float y = info[1].ToNumber();

	return Napi::Boolean::New(env, service->SetPointerPos(PointerPos(x, y)));
}

void SendPointerInput(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Number typeOfIntput = info[0].ToNumber();

	switch(typeOfIntput.Int32Value()) {
		case 1: {
			service->SendPointerInput(PointerCommand::Action::MOUSE_L_CLICK);
			break;
		}
		case 2: {
			service->SendPointerInput(PointerCommand::Action::MOUSE_L_DOUBLE_CLICK);
			break;
		}
		case 3: {
			service->SendPointerInput(PointerCommand::Action::MOUSE_R_CLICK);
			break;
		}
		case 4: {
			service->SendPointerInput(PointerCommand::Action::MOUSE_M_CLICK);
			break;
		}
		default: {
			cout << "Error: Not supported operation";
		}
	}
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(
		Napi::String::New(env, "getPointerPosition"),
		Napi::Function::New(env, GetPointerPosition)
	);

	exports.Set(
		Napi::String::New(env, "getPointerBoundary"),
		Napi::Function::New(env, GetPointerBoundary)
	);

	exports.Set(
		Napi::String::New(env, "setPointerPosition"),
		Napi::Function::New(env, SetPointerPosition)
	);

	exports.Set(
		Napi::String::New(env, "setPointerInput"),
		Napi::Function::New(env, SendPointerInput)
	);

	return exports;
}

NODE_API_MODULE(pointerService, Init)
