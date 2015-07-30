// network/address.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include <virusone/macros.h>
#include <virusone/network/address_ipv4.h>

#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

VirusOne::Network::AddressIpV4::AddressIpV4()
: m_address(0)
{}

VirusOne::Network::AddressIpV4::AddressIpV4(const AddressIpV4& address)
: m_address(address.m_address)
{}

VirusOne::Network::AddressIpV4::AddressIpV4(uint32_t address)
: m_address(address)
{}

VirusOne::Network::AddressIpV4::~AddressIpV4()
{}

void
VirusOne::Network::AddressIpV4::operator = (const AddressIpV4& address) {
  m_address = address.m_address;
}

void
VirusOne::Network::AddressIpV4::operator = (uint32_t address) {
  m_address = address;
}

bool
VirusOne::Network::AddressIpV4::operator == (const AddressIpV4& address) const {
  return m_address == address.m_address;
}

bool
VirusOne::Network::AddressIpV4::operator == (uint32_t address) const {
  return m_address == address;
}

bool
VirusOne::Network::AddressIpV4::operator != (const AddressIpV4& address) const {
  return m_address != address.m_address;
}

bool
VirusOne::Network::AddressIpV4::operator != (uint32_t address) const {
  return m_address != address;
}

bool
VirusOne::Network::AddressIpV4::fromString(const std::string& address) {
  struct in_addr in;
  if (!inet_aton(address.c_str(), &in)) {
    return false;
  }
  m_address = in.s_addr;
  return true;
}

std::string
VirusOne::Network::AddressIpV4::toString() const {
  struct in_addr in;
  in.s_addr = m_address;
  return std::string(inet_ntoa(in));
}

uint32_t
VirusOne::Network::AddressIpV4::hton() const {
  return htonl(m_address);
}

void
VirusOne::Network::AddressIpV4::ntoh(uint32_t address) {
  m_address = ntohl(address);
}
