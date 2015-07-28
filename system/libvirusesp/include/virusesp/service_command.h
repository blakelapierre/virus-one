// service_command.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusesp/service.h>
#include <memory>

/*
 * Asynchronous service commands are implemented using std::async and
 * std::future. For information about how they work on your particular
 * architecture, please review the C++11 documentation available at these
 * links:
 *
 * C++ std::future
 * http://www.cplusplus.com/reference/future/future/
 *
 * C++ std::async
 * http://www.cplusplus.com/reference/future/async/
 *
 * The gist is that the way VirusOne uses async and future, a thread pool should
 * exist to process commands. The launch::async policy is requested for
 * asynchronous commands, and the launch::deferred policy is requested for
 * deferred service commands.
 */

#include <rapidjson/document.h>

namespace VirusEsp {
  
  class Service;

  class ServiceCommand {
  public: // types

    enum CommandState {
      kCommandStatePending,
      kCommandStateRequestSent,
      kCommandStateResolved,
      kCommandStateCanceled
    };

  public: // methods

    ServiceCommand(Service& service, const rapidjson::Document& request);
    virtual ~ServiceCommand();

    const VirusOne::Services::Uuid& uuid() const { return m_uuid; }
    void uuid(const VirusOne::Services::Uuid& uuid) { m_uuid = uuid; }

    virtual void resolve(std::shared_ptr<rapidjson::Document> result);
    virtual void cancel();

  protected:

    VirusOne::Services::Uuid m_uuid;
    Service& m_service;
    const rapidjson::Document& m_request;

    CommandState m_eCommandState;
    std::shared_ptr<rapidjson::Document> m_result;

  };

  typedef std::shared_ptr<ServiceCommand> ServiceCommandPtr;

}
