// system/pollable.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/system/pollable.h>

VirusOne::System::Pollable::Pollable(
  const std::string& name
)
: m_name(name)
, m_log(spdlog::get("virusone"))
, m_ePollableState(kPollableRunning)
{}

VirusOne::System::Pollable::~Pollable()
{
  if (m_ePollableState == kPollableTerminated) {
    return;
  }
  terminate();
}

bool
VirusOne::System::Pollable::pause() {
  if (m_ePollableState != kPollableRunning) {
    m_log->error("request to pause non-running pollable {}", m_name);
    return false;
  }

  m_log->debug("pausing pollable {}", m_name);
  m_ePollableState = kPollablePaused;

  return true;
}

bool
VirusOne::System::Pollable::resume() {
  if (m_ePollableState != kPollablePaused) {
    m_log->error("request to resume non-paused pollable {}", m_name);
    return false;
  }

  m_log->debug("resuming pollable {}", m_name);
  m_ePollableState = kPollableRunning;

  return true;
}

bool
VirusOne::System::Pollable::terminate() {
  switch (m_ePollableState) {
    case kPollableRunning:
    case kPollablePaused:
      m_log->debug("terminating pollable {}", m_name);
      destroy();
      m_ePollableState = kPollableTerminated;
      break;
    
    default:
      m_log->error("request to terminate non-running pollable", m_name);
      return false;
  }
  return true;
}

VirusOne::System::Pollable::PollableState
VirusOne::System::Pollable::getState() {
  return m_ePollableState;
}
