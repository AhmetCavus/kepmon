#include "OsResolver.hpp"

#include <iostream>

OsResolver::OsResolver() {}

OsType OsResolver::Resolve() {
#if defined(_WIN32)
	return OsType::WINDOWS;
#elif defined(__linux__)
	return OsType::LINUX;
#elif defined(__APPLE__)
	return OsType::MAC;
#else
	return OsType::NOT_SUPPORTED;
#endif
}
