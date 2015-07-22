// virus_exception.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include "virus_macros.h"
#include "virus_exception.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdarg>

VirusOne::Exception::Exception(const char* fmt, ...)
: m_messageLen(0)
, m_message(null)
{
  va_list args;

  va_start(args, fmt);
  m_messageLen = vsnprintf(null, 0, fmt, args);
  va_end(args);

  va_start(args, fmt);
  m_message = (char*)::malloc(m_messageLen+2);
  vsnprintf(m_message, m_messageLen+1, fmt, args);
  va_end(args);
}

VirusOne::Exception::Exception(const Exception& e)
: m_messageLen(0)
, m_message(null)
{
  m_messageLen = e.m_messageLen;
  m_message = (char*)::malloc(m_messageLen + 2);
  strncpy(m_message, e.m_message, e.m_messageLen + 1);
  m_messageLen = e.m_messageLen;
}

VirusOne::Exception::~Exception() throw()
{
  if (m_message != null) {
    ::free(m_message);
    m_message = null;
  }
  m_messageLen = 0;
}

const char*
VirusOne::Exception::what() const throw()
{
  return m_message;
}
