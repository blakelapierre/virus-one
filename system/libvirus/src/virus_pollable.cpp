// virus_pollable.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virus_pollable.h>

VirusOne::Pollable::Pollable()
: m_ePollableState(kPollableRunning)
{}

VirusOne::Pollable::~Pollable()
{
  if (m_ePollableState != kPollableTerminated) {
    m_ePollableState = kPollableTerminated;
  }
}

bool
VirusOne::Pollable::pause() {
  if (m_ePollableState != kPollableRunning) {
    return false;
  }
  m_ePollableState = kPollablePaused;
  return true;
}

bool
VirusOne::Pollable::resume() {
  if (m_ePollableState != kPollablePaused) {
    return false;
  }
  m_ePollableState = kPollableRunning;
  return true;
}

bool
VirusOne::Pollable::terminate() {
  switch (m_ePollableState) {
    case kPollableRunning:
    case kPollablePaused:
      m_ePollableState = kPollableTerminated;
      break;
    
    default:
      // m_log->error("request to terminate pollable in state {}", m_ePollableState);
      return false;
  }
  // m_log->info("pollable terminated");
  return true;
}

VirusOne::Pollable::PollableState
VirusOne::Pollable::getState() {
  return m_ePollableState;
}
