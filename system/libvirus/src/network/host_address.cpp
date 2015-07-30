// network/host.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include <virusone/macros.h>
#include <virusone/network/host_address.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

VirusOne::Network::HostAddress::HostAddress()
{}

VirusOne::Network::HostAddress::HostAddress(
  const AddressIpV4& address,
  const PortNumber& port
)
: m_address(address)
, m_port(port)
{}

VirusOne::Network::HostAddress::HostAddress(
  uint32_t address,
  uint16_t port
)
: m_address(address)
, m_port(port)
{}

VirusOne::Network::HostAddress::~HostAddress()
{}

bool
VirusOne::Network::HostAddress::operator == (const HostAddress& host) const
{
  return (m_address == host.m_address) && (m_port == host.m_port);
}

bool
VirusOne::Network::HostAddress::operator != (const HostAddress& host) const
{
  return (m_address != host.m_address) || (m_port != host.m_port);
}

std::string
VirusOne::Network::HostAddress::toString() const
{
  return m_address.toString() + ":" + m_port.toString();
}

struct sockaddr_in
VirusOne::Network::HostAddress::toSockAddrIn() const {
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = m_address.hton();
  address.sin_port = m_port.hton();

  return address;
}
