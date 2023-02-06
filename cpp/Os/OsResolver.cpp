#include "OsResolver.hpp"

#include <iostream>

OsResolver::OsResolver() {}

OsType OsResolver::Resolve() {
#if defined(_WIN32)
	return OsType::WINDOWS;
#else
	return OsType::NOT_SUPPORTED;
#endif
}
