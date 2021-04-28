// FNAM: EventLoggers.h
// DESC: Various derived classes of Logger functions
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 27 April 2021
// UPDT: 27 April 2021
// VERS: 1.0
// SRCS: https://refactoring.guru/design-patterns/chain-of-responsibility
//		 https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example
#include "../include/EventLoggers.h"

std::string FatalLogger::handle(const std::string& request) {
	//TODO: Write this!!!
	return "";
}

std::string ErrorLogger::handle(const std::string& request) {
		return "";	//TODO: Write this!!!

}

std::string WarningLogger::handle(const std::string& request) {
		return "";	//TODO: Write this!!!
}

std::string InfoLogger::handle(const std::string& request) {
		return "";	//TODO: Write this!!!
}
