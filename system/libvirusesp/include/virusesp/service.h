// service.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusone/system/pollable.h>
#include <virusone/services/uuid.h>

#include <virusesp/service_command_queue.h>

#include <rapidjson/document.h>

#include <thread>
#include <map>

namespace VirusEsp {

  class ServiceCommand;
  class ServiceCommandPtr;

  /**
   * Your service will minimally override the executeCommand() method and
   * implement it, blocking execution until complete.
   *
   * This base class provides an asynchronous command queue that accepts
   * requests to start an asynchronous command and inserts it into a serialized
   * command queue. Separately, one or more worker threads will exist to consume
   * commands from the a service's queue, execute them and resolve their result
   * back to the application as a service.
   */
  class Service : public VirusOne::System::Pollable {
  public: // types

    typedef uint32_t CommandId;
    typedef std::function<void (CommandId, const rapidjson::Document&)> CommandCallback;

  public: // interfaces

    virtual const std::string getTypeName() const = 0;
    virtual void executeCommand(
      rapidjson::Document& command,
      rapidjson::Document& response
    ) = 0;

  public: // methods

    Service(const std::string& name);
    Service(const std::string& name, const VirusOne::Services::Uuid& uuid);
    virtual ~Service();

    const VirusOne::Services::Uuid& getUuid();
    
    rapidjson::Document& executeCommandAsync(
      rapidjson::Document& command,
      rapidjson::Document& response
    );
    rapidjson::Document& executeCommandDeferred(
      rapidjson::Document& command,
      rapidjson::Document& response
    );

  protected: // attributes

    std::string m_name;
    std::shared_ptr<spdlog::logger> m_log;
    VirusOne::Services::Uuid m_serviceUuid;

  private: // command queue thread (one per service)

    bool m_bServiceActive;

  };

} /* VirusEsp */
