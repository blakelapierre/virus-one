// virusone/services/pollgroup.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusone/system/pollable.h>
#include <list>

namespace VirusOne { namespace Services {

  class PollGroup : public VirusOne::System::Pollable {
  public: // VirusOne::Pollable interface methods

    virtual void poll();
    virtual void destroy();

  public: // methods

    PollGroup();
    virtual ~PollGroup();

    virtual void add(std::shared_ptr<Pollable> pollable);
    virtual bool remove(std::shared_ptr<Pollable> pollable);
    virtual void removeAll();

  protected:

    typedef std::list<std::shared_ptr<Pollable>> ClientList;
    typedef ClientList::iterator ClientListIterator;
    typedef ClientList::const_iterator ClientListCIterator;
    ClientList m_clients;

  };

} /* Services */ } /* VirusOne */
