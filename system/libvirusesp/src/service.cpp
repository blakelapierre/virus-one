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
, m_nextCommandId(0)
{
  startCommandQueueWorker();
}

VirusEsp::Service::Service(
  const std::string& name,
  const VirusOne::Services::Uuid& uuid
)
: m_name(name)
, m_log(spdlog::get("virusesp"))
, m_serviceUuid(uuid)
, m_nextCommandId(0)
{
  startCommandQueueWorker();
}

VirusEsp::Service::~Service()
{
  m_log->info(
    "service {} destroyed with {} outstanding commands"
    , m_name
    , m_commands.size()
  );
}

const VirusOne::Services::Uuid&
VirusEsp::Service::getUuid() {
  return m_serviceUuid;
}

VirusEsp::ServiceCommandPtr
VirusEsp::Service::createAsyncCommand(const rapidjson::Document& request, CommandCallback callback) {
  CommandId commandId = m_nextCommandId++; // just let it wrap
  ServiceCommandPtr command = std::make_shared<ServiceCommand>(*this, commandId, request);
  m_commands[commandId] = command;
  return command;
}

bool
VirusEsp::Service::cancelAsyncCommand(CommandId commandId) {
  CommandCallbackMapIterator sce = m_commandCallbacks.end();
  CommandCallbackMapIterator sci = m_commandCallbacks.find(commandId);
  if (sci == sce) {
    throw new ServiceException(m_name, "request to cancel untracked service command");
    return false;
  }
  m_commandCallbacks.erase(sci);
  return true;
}



void
VirusEsp::Service::startCommandQueueWorker() {

}

void
VirusEsp::Service::commandQueueWorker() {

}
