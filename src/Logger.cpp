// FNAM: Logger.cpp
// DESC: Logger interface and abstract base class functions
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 27 April 2021
// UPDT: 27 April 2021
// VERS: 1.0
// SRCS: https://refactoring.guru/design-patterns/chain-of-responsibility
//		 https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example
#include "../include/Logger.h"

handle_ptr Logger::setNext(handle_ptr nextHandle) {
	this->next_ = std::move(nextHandle);
	return nextHandle;
}

std::string Logger::handle(const std::string& request) {
	if (this->next_) {
		return this->next_->handle(request);
	}
	return {};
}