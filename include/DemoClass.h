// FNAM: DemoClass.h
// DESC: A Class demonstating the Logger class
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 27 April 2021
// UPDT: 28 April 2021
// VERS: 1.0
// SRCS: https://refactoring.guru/design-patterns/chain-of-responsibility
//		 https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example
#ifndef DEMO_CLASS_H
#define DEMO_CLASS_H

#include "EventLoggers.h"
#include "Logger.h"

class MyClassExample {
  public:
    MyClassExample();

    void setMemberVar(const int &val);
    std::string getLog() const;

  private:
    std::unique_ptr<LogPrinter> logPrinter_ = std::make_unique<LogPrinter>();
    int exampleVar_ = 0;
    LoggerChain logger_;
};

#endif // !DEMO_CLASS_H
