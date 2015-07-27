// network/host.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include <virusone/macros.h>
#include <virusone/network/host.h>

VirusOne::Network::Host::Host()
{}

VirusOne::Network::Host::Host(const AddressIpV4& address, const PortNumber& port)
: m_address(address)
, m_port(port)
{}

VirusOne::Network::Host::Host(uint32_t address, uint16_t port)
: m_address(address)
, m_port(port)
{}

VirusOne::Network::Host::~Host()
{}

bool
VirusOne::Network::Host::operator == (const Host& host) const
{
  return (m_address == host.m_address) && (m_port == host.m_port);
}

bool
VirusOne::Network::Host::operator != (const Host& host) const
{
  return (m_address != host.m_address) || (m_port != host.m_port);
}

std::string
VirusOne::Network::Host::toString() const
{
  return m_address.toString() + ":" + m_port.toString();
}
