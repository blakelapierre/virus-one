// virusone/network/port_number.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <cstdint>
#include <string>

namespace VirusOne { namespace Network {

  class PortNumber {
  public:

    PortNumber();
    PortNumber(const PortNumber& port);
    PortNumber(uint16_t portNumber);
    virtual ~PortNumber();

    virtual bool operator == (const PortNumber& port) const;
    virtual bool operator != (const PortNumber& port) const;
    virtual bool operator > (const PortNumber& port) const;
    virtual bool operator < (const PortNumber& port) const;

    virtual void operator = (const PortNumber& port);
    virtual void operator = (unsigned short portNumber);

    virtual std::string toString() const;
    virtual uint16_t hton() const;
    virtual void ntoh(uint16_t portNumber);

  protected:

    uint16_t m_portNumber;

  };

} /* Network */ } /* VirusOne */
