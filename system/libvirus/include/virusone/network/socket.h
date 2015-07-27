// virusone/network/socket.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusone/system/stream.h>

#include <sys/types.h>
#include <sys/socket.h>

#ifndef INVALID_SOCKET
#define INVALID_SOCKET (-1)
#endif

namespace VirusOne { namespace Network {

  class AddressIpV4;
  class PortNumber;

  class Socket : public VirusOne::System::Stream {
  public:

    enum SocketType {
      kSocketInvalid = INVALID_SOCKET,
      kSocketRaw = 0,
      kSocketUdp,
      kSocketTcp
    };    

    Socket(SocketType eType);
    Socket(SocketType eType, int s);
    Socket(const Socket& s);
    virtual ~Socket();

    virtual bool bind(const AddressIpV4& address, const PortNumber& port);
    virtual bool listen(size_t backlogLen);
    virtual bool connect(const AddressIpV4& address, const PortNumber& port);
    virtual void close();
    
    virtual int read(void* pDestBuffer, unsigned int maxDataLen);
    virtual int write(void* pDataBuffer, unsigned int dataBufferLength);

  protected:

    SocketType m_eSocketType;
    int m_s;

  };

} /* Network */ } /* VirusOne */
