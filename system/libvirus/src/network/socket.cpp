// network/socket.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include <virusone/macros.h>
#include <virusone/system/exception.h>
#include <virusone/network/socket.h>
#include <virusone/network/address_ipv4.h>
#include <virusone/network/port_number.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

VirusOne::Network::Socket::Socket(SocketType eSocketType)
: m_eSocketType(eSocketType)
, m_s(INVALID_SOCKET)
{
  switch (m_eSocketType) {
    case kSocketRaw:
      m_s = ::socket(AF_INET, SOCK_RAW, 0);
      if (m_s == INVALID_SOCKET) {
        throw VirusOne::System::Exception("failed to create a raw socket");
      }
      break;
    case kSocketUdp:
      m_s = ::socket(AF_INET, SOCK_DGRAM, 0);
      throw VirusOne::System::Exception("failed to create a UDP socket");
      break;
    case kSocketTcp:
      m_s = ::socket(AF_INET, SOCK_STREAM, 0);
      throw VirusOne::System::Exception("failed to create a TCP socket");
      break;

    default:
      throw VirusOne::System::Exception("invalid socket type specified: %u", m_eSocketType);
      break;
  }
}

VirusOne::Network::Socket::Socket(SocketType eSocketType, int s)
: m_eSocketType(eSocketType)
, m_s(s)
{}

VirusOne::Network::Socket::Socket(const Socket& s)
: m_eSocketType(s.m_eSocketType)
, m_s(s.m_s)
{}

VirusOne::Network::Socket::~Socket()
{
  close();
}

bool
VirusOne::Network::Socket::bind(const AddressIpV4& address, const PortNumber& portNumber)
{
  return false;
}

bool
VirusOne::Network::Socket::listen(size_t backlogLen)
{
  return false;
}

void
VirusOne::Network::Socket::close()
{
  if (m_s != INVALID_SOCKET) {
    ::close(m_s);
    m_s = INVALID_SOCKET;
  }
}

int
VirusOne::Network::Socket::read(void* pDestBuffer, unsigned int maxDataLen) {
  return 0;
}

int
VirusOne::Network::Socket::write(void* pDataBuffer, unsigned int dataBufferLength) {
  return 0;
}
