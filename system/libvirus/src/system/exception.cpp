// system/exception.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include <virusone/macros.h>
#include <virusone/system/exception.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

VirusOne::System::Exception::Exception()
: m_messageLen(0)
, m_message(null)
{}

VirusOne::System::Exception::Exception(const std::string& fmt, ...)
: m_messageLen(0)
, m_message(null)
{
  va_list args;
  va_start(args, fmt);
  buildMessage(fmt, args);
  va_end(args);
}

VirusOne::System::Exception::Exception(const std::string& fmt, va_list args)
: m_messageLen(0)
, m_message(null)
{
  buildMessage(fmt, args);
}


VirusOne::System::Exception::Exception(const Exception& e)
: m_messageLen(0)
, m_message(null)
{
  m_messageLen = e.m_messageLen;
  m_message = (char*)::malloc(m_messageLen + 2);
  strncpy(m_message, e.m_message, e.m_messageLen + 1);
  m_messageLen = e.m_messageLen;
}

VirusOne::System::Exception::~Exception() throw() {
  clearMessage();
}

const char*
VirusOne::System::Exception::what() const throw() {
  return m_message == null ? "VirusOne Generic Exception" : m_message;
}

void
VirusOne::System::Exception::buildMessage(const std::string& fmt, ...) {
  va_list args;
  va_start(args, fmt);
  buildMessage(fmt, args);
  va_end(args);
}

void
VirusOne::System::Exception::buildMessage(const std::string& fmt, va_list argsIn) {
  va_list args;
  va_copy(args, argsIn);
  m_messageLen = vsnprintf(null, 0, fmt.c_str(), args);
  va_end(args);

  clearMessage();

  va_copy(args, argsIn);
  m_message = (char*)::malloc(m_messageLen + 2);
  vsnprintf(m_message, m_messageLen+1, fmt.c_str(), args);
  va_end(args);
}

void
VirusOne::System::Exception::clearMessage() {
  FREE_OBJECT( m_message );
  m_messageLen = 0;
}
