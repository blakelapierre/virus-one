// virus_timestamp.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#pragma once

#include <sys/time.h>
#include <string>

namespace VirusOne {

  class Timestamp {
  public:

    Timestamp();
    Timestamp(const Timestamp& timestamp);
    virtual ~Timestamp();

    void update();

    float secondsFrom(const Timestamp& timestamp) const;
    float secondsTo(const Timestamp& timestamp) const;

    std::string toString() const;
    static std::string now();

  protected:

    struct timeval m_tv;

  };

}
