#include "PointerServiceLocator.hpp"

PointerServiceLocator::PointerServiceLocator() {}

PointerService* PointerServiceLocator::Resolve() {
	switch (m_osResolver.Resolve()) {
		case OsType::WINDOWS:
		{
			return new PointerServiceWin();
		}
		default:
		{
			return NULL;
		}
	}
}
