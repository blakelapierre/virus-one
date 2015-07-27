// virusone/network/address_ipv4.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <cstdint>
#include <string>

namespace VirusOne { namespace Network {

  class AddressIpV4 {
  public:

    AddressIpV4();
    AddressIpV4(const AddressIpV4& address);
    AddressIpV4(const uint32_t address);
    virtual ~AddressIpV4();

    virtual void operator = (const uint32_t address);
    virtual void operator = (const AddressIpV4& address);

    bool operator == (const AddressIpV4& address) const;
    bool operator != (const AddressIpV4& address) const;
    bool operator == (uint32_t address) const;
    bool operator != (uint32_t address) const;

    virtual bool fromString(const std::string& address);
    virtual std::string toString() const;

  protected:

    uint32_t m_address;

  };

} /* Network */ } /* VirusOne */
