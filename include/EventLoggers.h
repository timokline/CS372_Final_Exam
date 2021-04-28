// FNAM: EventLoggers.h
// DESC: Various derived classes of Logger
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 27 April 2021
// UPDT: 27 April 2021
// VERS: 1.0
// SRCS: https://refactoring.guru/design-patterns/chain-of-responsibility
//		 https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example
#include "Logger.h"

class FatalLogger : public Logger {
  public:
    std::string handle(const Level &logLevel,
                       const std::string &message) const override;
};

class ErrorLogger : public Logger {
    std::string handle(const Level &logLevel,
                       const std::string &message) const override;
};

class WarningLogger : public Logger {
    std::string handle(const Level &logLevel,
                       const std::string &message) const override;
};

class InfoLogger : public Logger {
    std::string handle(const Level &logLevel,
                       const std::string &message) const override;
};
