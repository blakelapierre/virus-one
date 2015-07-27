// network/port_number.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/network/port_number.h>

#include <arpa/inet.h>

VirusOne::Network::PortNumber::PortNumber()
: m_portNumber(0)
{}

VirusOne::Network::PortNumber::PortNumber(const PortNumber& port)
: m_portNumber(port.m_portNumber)
{}

VirusOne::Network::PortNumber::PortNumber(uint16_t port)
: m_portNumber(htons(port))
{}

VirusOne::Network::PortNumber::~PortNumber()
{
  m_portNumber = 0;
}

bool
VirusOne::Network::PortNumber::operator == (const PortNumber& port) const {
  return m_portNumber == port.m_portNumber;
}

bool
VirusOne::Network::PortNumber::operator != (const PortNumber& port) const {
  return m_portNumber != port.m_portNumber;
}

bool
VirusOne::Network::PortNumber::operator > (const PortNumber& port) const {
  return m_portNumber > port.m_portNumber;
}

bool
VirusOne::Network::PortNumber::operator < (const PortNumber& port) const {
  return m_portNumber < port.m_portNumber;
}

void
VirusOne::Network::PortNumber::operator = (const PortNumber& port) {
  m_portNumber = port.m_portNumber;
}

void
VirusOne::Network::PortNumber::operator = (unsigned short port) {
  m_portNumber = htons(port);
}

uint16_t
VirusOne::Network::PortNumber::value() const {
  return ntohs(m_portNumber);
}

std::string
VirusOne::Network::PortNumber::toString() const {
  char buffer[16];
  snprintf(buffer,sizeof(buffer), "%d", ntohs(m_portNumber));
  return std::string(buffer);
}
