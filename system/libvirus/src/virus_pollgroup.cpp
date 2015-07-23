// virus_pollgroup.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virus_macros.h>
#include <virus_pollgroup.h>

VirusOne::PollGroup::PollGroup()
{}

VirusOne::PollGroup::~PollGroup()
{}

void
VirusOne::PollGroup::add(PollablePtr pollable) {
  m_clients.push_back(pollable);
}

bool
VirusOne::PollGroup::remove(PollablePtr pollable) {
  ClientListIterator cle = m_clients.end();
  ClientListIterator cli = std::find(m_clients.begin(), cle, pollable);
  if (cli == cle) {
    return false;
  }

  m_clients.erase(cli);

  return true;
}

void
VirusOne::PollGroup::removeAll() {
  m_clients.clear();
}

void
VirusOne::PollGroup::poll() {
  ClientListIterator cli, cle = m_clients.end();
  for (cli = m_clients.begin(); cli != cle; ) {
    PollablePtr pollable = (*cli);
    switch (pollable->getState()) {
      case Pollable::kPollableRunning:
        pollable->poll();
        ++cli;
        break;
      
      case Pollable::kPollablePaused:
        ++cli;
        break;

      case Pollable::kPollableTerminated:
        pollable->destroy();
        cli = m_clients.erase(cli);
        break;

      default:
        // m_log->error("invalid pollable state {}", pollable->getState());
        ++cli;
        break;
    }
  }
}

void
VirusOne::PollGroup::destroy() {
  removeAll();
}
