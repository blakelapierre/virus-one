// virus_sensor_temperature_simulator.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include "virus_sensor.h"

namespace VirusOne {

  class TemperatureSensorSimulator : public Sensor
  {
  public:

    TemperatureSensorSimulator();
    TemperatureSensorSimulator(uuid_t sensorUuid);
    virtual ~TemperatureSensorSimulator();

    virtual bool reset();
    virtual bool isConnected();
    virtual bool isCalibrated();

    virtual const std::string getTypeName() { return "TemperatureSensorSimulator"; }
    virtual const rapidjson::Value& getCurrentValue();

  protected:

    rapidjson::Value m_currentValue;

  };
}
