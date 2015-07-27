// virusone/system/pollable.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <spdlog/spdlog.h>
#include <string>
#include <memory>

namespace VirusOne { namespace System {
  
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

    Pollable(const std::string& name = std::string(""));
    virtual ~Pollable();

    virtual bool pause();
    virtual bool resume();
    virtual bool terminate();
    virtual PollableState getState();

    virtual std::shared_ptr<spdlog::logger> log() { return m_log; }

  protected:

    std::string m_name;
    std::shared_ptr<spdlog::logger> m_log;
    PollableState m_ePollableState;

  };

} /* System */ } /* VirusOne */
