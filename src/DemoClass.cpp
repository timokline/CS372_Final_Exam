// FNAM: DemoClass.cpp
// DESC: MyClassExample functions
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 27 April 2021
// UPDT: 28 April 2021
// VERS: 1.0
// SRCS: https://refactoring.guru/design-patterns/chain-of-responsibility
//		 https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example//
#include "../include/DemoClass.h"

MyClassExample::MyClassExample() {
    auto message = logger_.head_->handle(Level::LOG_INFO,
                                         "MyClassExample: Default Constructor");
    logPrinter_->readOutput(message);
}

void MyClassExample::setMemberVar(const int &val) {
    exampleVar_ = val;
    auto message = logger_.head_->handle(
        Level::WARNING,
        "MyClassExample: exampleVar_ state changed >> " + std::to_string(val));
    logPrinter_->readOutput(message);
}

std::string MyClassExample::getLog() const {
    return logPrinter_->printOutput();
}
