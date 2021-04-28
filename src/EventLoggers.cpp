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

std::string FatalLogger::handle(const Level &logLevel,
                                const std::string &message) const {
    if (logLevel == Level::FATAL) {
        return "[FATAL]: " + message;
    }
    return Logger::handle(logLevel, message);
}

std::string ErrorLogger::handle(const Level &logLevel,
                                const std::string &message) const {
    if (logLevel == Level::ERROR) {
        return "[ERROR]: " + message;
    }
    return Logger::handle(logLevel, message);
}

std::string WarningLogger::handle(const Level &logLevel,
                                  const std::string &message) const {
    if (logLevel == Level::WARNING) {
        return "[WARNING]: " + message;
    }
    return Logger::handle(logLevel, message);
}

std::string InfoLogger::handle(const Level &logLevel,
                               const std::string &message) const {
    if (logLevel == Level::LOG_INFO) {
        return "[INFO]: " + message;
    }
    return Logger::handle(logLevel, message);
}

LoggerChain::LoggerChain() { createChain(); }

void LoggerChain::createChain() {
    head_ = std::make_unique<FatalLogger>();
    handle_ptr errorLogger = std::make_unique<ErrorLogger>();
    handle_ptr warningLogger = std::make_unique<WarningLogger>();
    handle_ptr infoLogger = std::make_unique<InfoLogger>();

    head_->setNext(std::move(errorLogger))
        ->setNext(std::move(warningLogger))
        ->setNext(std::move(infoLogger));
}
