// services/pollgroup.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/services/pollgroup.h>

VirusOne::Services::PollGroup::PollGroup()
{}

VirusOne::Services::PollGroup::~PollGroup()
{}

void
VirusOne::Services::PollGroup::add(std::shared_ptr<Pollable> pollable) {
  m_clients.push_back(pollable);
}

bool
VirusOne::Services::PollGroup::remove(std::shared_ptr<Pollable> pollable) {
  ClientListIterator cle = m_clients.end();
  ClientListIterator cli = std::find(m_clients.begin(), cle, pollable);
  if (cli == cle) {
    return false;
  }

  m_clients.erase(cli);

  return true;
}

void
VirusOne::Services::PollGroup::removeAll() {
  m_clients.clear();
}

void
VirusOne::Services::PollGroup::poll() {
  ClientListIterator cli, cle = m_clients.end();
  for (cli = m_clients.begin(); cli != cle; ) {
    std::shared_ptr<Pollable> pollable = (*cli);
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
VirusOne::Services::PollGroup::destroy() {
  removeAll();
}
