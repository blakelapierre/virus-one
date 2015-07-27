// device.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusone/system/pollable.h>
#include <virusone/services/uuid.h>

#include <string>
#include <spdlog/spdlog.h>

namespace VirusEsp {

  class Device : public VirusOne::System::Pollable {
  public: // interfaces

    virtual const std::string getTypeName() const = 0;
    virtual bool reset() = 0;
    virtual bool isConnected() const = 0;
    virtual bool isCalibrated() const = 0;

  public: // VirusOne::System::Pollable overrides

    virtual std::shared_ptr<spdlog::logger> log() { return m_deviceLog; }

  public: // methods

    Device(const std::string& name);
    Device(const std::string& name, const VirusOne::Services::Uuid& deviceUuid);
    virtual ~Device();

  protected: // attributes

    std::string m_name;
    VirusOne::Services::Uuid m_uuid;
    std::shared_ptr<spdlog::logger> m_deviceLog;

  };

} /* VirusEsp */
