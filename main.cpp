// FNAM: main.cpp
// DESC: main for Logger
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 27 April 2021
// UPDT: 28 April 2021
// VERS: 1.0
// SRCS: https://refactoring.guru/design-patterns/chain-of-responsibility
//		 https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example

#include <iostream>

#include "include/DemoClass.h"

int main() {
    MyClassExample myClass;
    myClass.setMemberVar(8);

    std::cout << myClass.getLog() << std::endl;
    return 0;
}
