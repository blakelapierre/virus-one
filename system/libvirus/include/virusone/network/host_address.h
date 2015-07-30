// virusone/network/host.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#pragma once

#include <virusone/network/address_ipv4.h>
#include <virusone/network/port_number.h>

#include <string>

struct sockaddr_in;

namespace VirusOne { namespace Network {

  class HostAddress {
  public:

    HostAddress();
    HostAddress(const AddressIpV4& address, const PortNumber& port);
    HostAddress(uint32_t address, uint16_t port);
    virtual ~HostAddress();

    virtual bool operator == (const HostAddress& host) const;
    virtual bool operator != (const HostAddress& host) const;

    virtual std::string toString() const;
    virtual struct sockaddr_in toSockAddrIn() const;

  protected:

    AddressIpV4 m_address;
    PortNumber m_port;

  };

} /* Network */ } /* VirusOne */
