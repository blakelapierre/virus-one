// devices/sensors/temperature.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusesp/devices/sensor.h>
#include <rapidjson/document.h>

namespace VirusEsp { namespace Sensors {

  class Temperature : public VirusEsp::Devices::Sensor<double> {
  public: // VirusOne::Sensor interface methods

    virtual bool reset();
    virtual bool isConnected() const;
    virtual bool isCalibrated() const;
    virtual const std::string getTypeName() const;
    virtual const rapidjson::Value& getCurrentValue() const;

  public: // VirusOne::Pollable interface methods

    virtual void poll();
    virtual void destroy();

  public: // methods

    Temperature();
    virtual ~Temperature();

    virtual void initialize(/* portNumber */);

  protected: // attributes

    rapidjson::Value m_currentValue;

  };

} /* Sensors */ } /* VirusEsp */
