// virus_host.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include "virus_host.h"

VirusOne::Host::Host()
{}

VirusOne::Host::Host(const AddressIpV4& address, const PortNumber& port)
: m_address(address)
, m_port(port)
{}

VirusOne::Host::Host(uint32_t address, uint16_t port)
: m_address(address)
, m_port(port)
{}

VirusOne::Host::~Host()
{}

bool
VirusOne::Host::operator == (const Host& host) const
{
  return (m_address == host.m_address) && (m_port == host.m_port);
}

bool
VirusOne::Host::operator != (const Host& host) const
{
  return (m_address != host.m_address) || (m_port != host.m_port);
}

std::string
VirusOne::Host::toString() const
{
  return m_address.toString() + ":" + m_port.toString();
}
