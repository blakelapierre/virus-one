// virus_pollgroup.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virus_pollable.h>
#include <list>

namespace VirusOne {

  class PollGroup : public Pollable {
  public: // VirusOne::Pollable interface methods

    virtual void poll();
    virtual void destroy();

  public: // methods

    PollGroup();
    virtual ~PollGroup();

    virtual void add(PollablePtr pollable);
    virtual bool remove(PollablePtr pollable);
    virtual void removeAll();

  protected:

    typedef std::list<PollablePtr> ClientList;
    typedef ClientList::iterator ClientListIterator;
    typedef ClientList::const_iterator ClientListCIterator;
    ClientList m_clients;

  };

}
