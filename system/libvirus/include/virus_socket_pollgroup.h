// virus_socket_pollgroup.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <list>

namespace VirusOne {

  class SocketPollGroup {
  public:

    SocketPollGroup();
    virtual ~SocketPollGroup();

    virtual void addSocket(const Socket& socket);
    virtual void removeSocket(const Socket& socket);
    virtual void removeAllSockets();

  protected:

    typedef std::list<Socket*> SocketList;
    typedef SocketList::iterator SocketListIterator;
    typedef SocketList::const_iteator SocketListCIterator;
    SocketList m_sockets;

  };

}
