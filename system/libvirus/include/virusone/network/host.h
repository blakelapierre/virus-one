// virusone/network/host.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#pragma once

#include <virusone/network/address_ipv4.h>
#include <virusone/network/port_number.h>

#include <string>

namespace VirusOne { namespace Network {

  class Host {
  public:

    Host();
    Host(const AddressIpV4& address, const PortNumber& port);
    Host(uint32_t address, uint16_t port);
    virtual ~Host();

    virtual bool operator == (const Host& host) const;
    virtual bool operator != (const Host& host) const;

    virtual std::string toString() const;

  protected:

    AddressIpV4 m_address;
    PortNumber m_port;

  };

} /* Network */ } /* VirusOne */
