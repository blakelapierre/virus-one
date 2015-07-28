// service.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>

#include <virusesp/service.h>
#include <virusesp/service_exception.h>

VirusEsp::Service::Service(
  const std::string& name
)
: m_name(name)
, m_log(spdlog::get("virusesp"))
{}

VirusEsp::Service::Service(
  const std::string& name,
  const VirusOne::Services::Uuid& uuid
)
: m_name(name)
, m_log(spdlog::get("virusesp"))
, m_serviceUuid(uuid)
{}

VirusEsp::Service::~Service()
{
  m_log->info("service {} destroyed", m_name);
}

const VirusOne::Services::Uuid&
VirusEsp::Service::getUuid() {
  return m_serviceUuid;
}

bool
VirusEsp::Service::isActive() const
{
  return m_bServiceActive;
}

VirusEsp::Service::ExecuteCommandFuture
VirusEsp::Service::executeCommandAsync(const rapidjson::Document& command, rapidjson::Document& response)
{
//   auto commandRunner = std::bind(&Service::executeCommand, this, std::placeholders::_1, std::placeholders::_2);
//   ExecuteCommandFuture fut = std::async(std::launch::async, commandRunner, command, response);
//   return fut;
}

bool
VirusEsp::Service::executeCommandDeferred(const rapidjson::Document& command, rapidjson::Document& response)
{
  
}
