// virus_pollable.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <spdlog/spdlog.h>
#include <memory>

namespace VirusOne {
  
  class Pollable {
  public: // types

    enum PollableState {
      kPollableRunning,
      kPollablePaused,
      kPollableTerminated,
      kPollableDestroyed
    };

  public: // interface methods

    virtual void poll() = 0;
    virtual void destroy() = 0;

  public: // methods

    Pollable();
    virtual ~Pollable();

    virtual bool pause();
    virtual bool resume();
    virtual bool terminate();
    virtual PollableState getState();

  protected:

    std::shared_ptr<spdlog::logger> m_log;
    PollableState m_ePollableState;

  };

  typedef std::shared_ptr<Pollable> PollablePtr;

}
