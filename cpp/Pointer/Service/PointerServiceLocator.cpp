#include "PointerServiceLocator.hpp"

PointerServiceLocator::PointerServiceLocator() {}

PointerService* PointerServiceLocator::Resolve() {
	#if defined(_WIN32)
		return new PointerServiceWin();
	#elif defined(__linux__)
		return new PointerServiceLinux();
	#elif defined(__APPLE__)
		return new PointerServiceMac();
	#else
		return NULL;
	#endif
}
