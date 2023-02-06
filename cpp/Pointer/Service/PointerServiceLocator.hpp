#ifndef POINTER_SERVICE_H
#define POINTER_SERVICE_H

#include <iostream>
#include "PointerServiceEngines.hpp"
#include "../../Os/OsResolver.hpp"

class PointerServiceLocator {
	private:
		OsResolver m_osResolver;
	public:
		PointerServiceLocator();
		PointerService* Resolve();
};

#endif