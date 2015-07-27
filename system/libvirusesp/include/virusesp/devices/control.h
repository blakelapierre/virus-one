// devices/control.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusesp/device.h>
#include <rapidjson/document.h>

namespace VirusEsp { namespace Devices {

  class Control : public VirusEsp::Device {
  public: // methods

    Control(const std::string& name);
    Control(const std::string& name, uuid_t controlUuid);
    virtual ~Control();

    virtual bool setCurrentValue(rapidjson::Value& value) = 0;
    virtual const rapidjson::Value& getCurrentValue();

  protected:

    rapidjson::Value m_value;

  };

} /* Devices */ } /* VirusEsp */
