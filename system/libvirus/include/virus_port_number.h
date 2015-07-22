// virus_port_number.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <cstdint>
#include <string>

namespace VirusOne {

  class PortNumber {
  public:

    PortNumber();
    PortNumber(const PortNumber& port);
    PortNumber(uint16_t port);
    virtual ~PortNumber();

    virtual bool operator == (const PortNumber& port) const;
    virtual bool operator != (const PortNumber& port) const;
    virtual bool operator > (const PortNumber& port) const;
    virtual bool operator < (const PortNumber& port) const;

    virtual void operator = (const PortNumber& port);
    virtual void operator = (unsigned short port);
    virtual uint16_t value() const;

    virtual std::string toString() const;

  protected:

    uint16_t m_portNumber;

  };

}
