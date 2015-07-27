#pragma once

#include <virusesp/service_command.h>
#include <atomic>

namespace VirusEsp {

  class Service;

  class ServiceCommandQueue {
  public: // methods

    ServiceCommandQueue(Service& service);
    virtual ~ServiceCommandQueue();

    ServiceCommandPtr createCommand(const rapidjson::Document& request, CommandCallback callback);
    bool cancelCommand(ServiceCommandPtr command);
    void resolveCommand(ServiceCommandPtr command, std::shared_ptr<rapidjson::Document> result);

  protected:

    Service& m_service;

    typedef std::map<CommandId, std::shared_ptr<ServiceCommand> > CommandMap;
    typedef CommandMap::iterator CommandMapIterator;
    typedef CommandMap::const_iterator CommandMapConstIterator;
    CommandMap m_commands;
    CommandId m_nextCommandId;

  };
}