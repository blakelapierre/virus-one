// devices/sensor.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusesp/device.h>
#include <rapidjson/document.h>

namespace VirusEsp { namespace Devices {

  template<class T>
  class Sensor : public VirusEsp::Device {
  public: // interface methods

    virtual const rapidjson::Value& getCurrentValue() const = 0;

  public: // methods

    Sensor();
    Sensor(uuid_t sensorUuid);
    virtual ~Sensor();

  };

} /* Devices */ } /* VirusEsp */
