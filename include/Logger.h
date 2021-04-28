// FNAM: Logger.h
// DESC: A Logger interface and abstract base class
// AUTH: Timothy Albert Kline
// CRSE: F372 - Software Construction
// PROF: Dr. Chris Hartman
// STRT: 27 April 2021
// UPDT: 27 April 2021
// VERS: 1.0
// SRCS: https://refactoring.guru/design-patterns/chain-of-responsibility
//		 https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example
#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <sstream>
#include <string>

class ILogger;

using handle_ptr = std::unique_ptr<ILogger>;

enum class Level { FATAL, ERROR, WARNING, LOG_INFO };

class ILogger {
  public:
    virtual const handle_ptr &setNext(handle_ptr nextHandle) = 0;
    virtual std::string handle(const Level &logLevel,
                               const std::string &message) const = 0;
    virtual ~ILogger() = default;
};

class Logger : public ILogger {
  private:
    handle_ptr next_ = nullptr;

  public:
    Logger() = default;
    const handle_ptr &setNext(handle_ptr nextHandle) override;
    std::string handle(const Level &logLevel,
                       const std::string &message) const override;
};

class LogPrinter {
  public:
    LogPrinter() = default;

    void readOutput(const std::string &input);
    std::string printOutput() const;

  private:
    std::ostringstream output_;
};
#endif // !LOGGER_H
