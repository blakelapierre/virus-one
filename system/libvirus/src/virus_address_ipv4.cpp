// virus_address.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include "virus_address_ipv4.h"

#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

VirusOne::AddressIpV4::AddressIpV4()
: m_address(0)
{}

VirusOne::AddressIpV4::AddressIpV4(const AddressIpV4& address)
: m_address(address.m_address)
{}

VirusOne::AddressIpV4::AddressIpV4(uint32_t address)
: m_address(address)
{}

VirusOne::AddressIpV4::~AddressIpV4()
{}

void
VirusOne::AddressIpV4::operator = (const AddressIpV4& address) {
  m_address = address.m_address;
}

void
VirusOne::AddressIpV4::operator = (uint32_t address) {
  m_address = address;
}

bool
VirusOne::AddressIpV4::operator == (const AddressIpV4& address) const {
  return m_address == address.m_address;
}

bool
VirusOne::AddressIpV4::operator == (uint32_t address) const {
  return m_address == address;
}

bool
VirusOne::AddressIpV4::operator != (const AddressIpV4& address) const {
  return m_address != address.m_address;
}

bool
VirusOne::AddressIpV4::operator != (uint32_t address) const {
  return m_address != address;
}

bool
VirusOne::AddressIpV4::fromString(const std::string& address) {
  struct in_addr in;
  if (!inet_aton(address.c_str(), &in)) {
    return false;
  }
  m_address = in.s_addr;
  return true;
}

std::string
VirusOne::AddressIpV4::toString() const {
  struct in_addr in;
  in.s_addr = m_address;
  return std::string(inet_ntoa(in));
}
