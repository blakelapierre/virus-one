// virus_port_number.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <arpa/inet.h>
#include "virus_port_number.h"

VirusOne::PortNumber::PortNumber()
: m_portNumber(0)
{}

VirusOne::PortNumber::PortNumber(const PortNumber& port)
: m_portNumber(port.m_portNumber)
{}

VirusOne::PortNumber::PortNumber(uint16_t port)
: m_portNumber(htons(port))
{}

VirusOne::PortNumber::~PortNumber()
{
  m_portNumber = 0;
}

bool
VirusOne::PortNumber::operator == (const PortNumber& port) const {
  return m_portNumber == port.m_portNumber;
}

bool
VirusOne::PortNumber::operator != (const PortNumber& port) const {
  return m_portNumber != port.m_portNumber;
}

bool
VirusOne::PortNumber::operator > (const PortNumber& port) const {
  return m_portNumber > port.m_portNumber;
}

bool
VirusOne::PortNumber::operator < (const PortNumber& port) const {
  return m_portNumber < port.m_portNumber;
}

void
VirusOne::PortNumber::operator = (const PortNumber& port) {
  m_portNumber = port.m_portNumber;
}

void
VirusOne::PortNumber::operator = (unsigned short port) {
  m_portNumber = htons(port);
}

uint16_t
VirusOne::PortNumber::value() const {
  return ntohs(m_portNumber);
}

std::string
VirusOne::PortNumber::toString() const {
  char buffer[16];
  snprintf(buffer,sizeof(buffer), "%d", ntohs(m_portNumber));
  return std::string(buffer);
}
