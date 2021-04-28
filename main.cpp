// FNAM: Shape.hpp
// DESC: A Shape base class
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 27 April 2021
// UPDT: 27 April 2021
// VERS: 1.0
// SRCS: https://refactoring.guru/design-patterns/chain-of-responsibility
//		 https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example
#include <iostream>
#include <memory>
#include <string>

#include "include/EventLoggers.h"
#include "include/Logger.h"

class LoggerChain {
  public:
    LoggerChain() { createChain(); }

    handle_ptr head_;

  private:
    void createChain() {
        head_ = std::make_unique<FatalLogger>();
        handle_ptr errorLogger = std::make_unique<ErrorLogger>();
        handle_ptr warningLogger = std::make_unique<WarningLogger>();
        handle_ptr infoLogger = std::make_unique<InfoLogger>();

        head_->setNext(std::move(errorLogger))
            ->setNext(std::move(warningLogger))
            ->setNext(infoLogger);
    }
};

class MyClassExample {
  public:
    MyClassExample();

  private:
    int exampleVar_ = 0;
    LoggerChain logger_;
};

MyClassExample::MyClassExample() {
    logger_.head_->handle(Level::LOG_INFO,
                                "MyClassExample: Default Constructor");
}

int main() {
    MyClassExample myClass;

    return 0;
}
