// virus_timestamp.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

#include "virus_macros.h"
#include "virus_timestamp.h"

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

VirusOne::Timestamp::Timestamp()
{
  update();
}

VirusOne::Timestamp::Timestamp(const Timestamp& timestamp)
: m_tv(timestamp.m_tv)
{}

VirusOne::Timestamp::~Timestamp()
{}

void
VirusOne::Timestamp::update()
{
  gettimeofday(&m_tv, null);
}

float
VirusOne::Timestamp::secondsFrom(const Timestamp& timestamp) const
{
  struct timeval result;
  timersub(&m_tv, &timestamp.m_tv, &result);
  return (float)result.tv_sec + ((float)result.tv_usec / 1000000.0f);
}

float
VirusOne::Timestamp::secondsTo(const Timestamp& timestamp) const
{
  struct timeval result;
  timersub(&timestamp.m_tv, &m_tv, &result);
  return (float)result.tv_sec + ((float)result.tv_usec / 1000000.0f);
}

std::string
VirusOne::Timestamp::toString() const
{
  struct tm localTime;
  localtime_r(&m_tv.tv_sec, &localTime);

  static char buffer[128];
  size_t writeIdx = strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);
  snprintf(&buffer[writeIdx], sizeof(buffer) - writeIdx, ".%06lu", m_tv.tv_usec);

  return std::string(buffer);
}

std::string
VirusOne::Timestamp::now() {
  Timestamp t;
  return t.toString();
}
