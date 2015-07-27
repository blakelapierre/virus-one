// virusone/services/virus_timestamp.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#pragma once

#include <string>
#include <sys/time.h>

namespace VirusOne { namespace Services {

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

} /* Services */ } /* VirusOne */
