// virus-log.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

namespace VirusOne {

  class Log {
  public:

    enum Level {
      DEBUG,
      INFO,
      WARN,
      ERROR,
      SYSTEM,
      FATAL
    };

    virtual void debug(const std::string& message);
    virtual void info(const std::string& message);
    virtual void warn(const std::string& message);
    virtual void error(const std::string& message);
    virtual void system(const std::string& message);
    virtual void fatal(const std::string& message);

    virtual void write(Level eLevel, const std::string& message);

  protected:

  };
}
