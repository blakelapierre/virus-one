// virus_sensor.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virus_pollable.h>

#include <uuid/uuid.h>
#include "rapidjson/document.h"

namespace VirusOne {

  class Sensor : public Pollable {
  public:

    Sensor();
    Sensor(uuid_t sensorUuid);
    virtual ~Sensor();

    virtual bool reset() = 0;
    virtual bool isConnected() const = 0;
    virtual bool isCalibrated() const = 0;

    virtual const std::string getTypeName() const = 0;
    virtual const rapidjson::Value& getCurrentValue() const = 0;

  protected:

    uuid_t m_sensorUuid;
    char m_sensorUuidString[37];

  };
}
