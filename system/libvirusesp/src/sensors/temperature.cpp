// sensors/temperature.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <sensors/temperature.h>

VirusEsp::Sensors::Temperature::Temperature()
: m_currentValue(0.0)
{}

VirusEsp::Sensors::Temperature::~Temperature()
{
  m_currentValue = 0.0;
}

void
VirusEsp::Sensors::Temperature::initialize(/* portNumber */) {
  
}

//
// VirusOne::Sensor methods
//

bool
VirusEsp::Sensors::Temperature::reset() {
  return true;
}

bool
VirusEsp::Sensors::Temperature::isConnected() const {
  return false;
}

bool
VirusEsp::Sensors::Temperature::isCalibrated() const {
  return false;
}

const std::string
VirusEsp::Sensors::Temperature::getTypeName() const {
  return "Temperature Sensor";
}

const rapidjson::Value&
VirusEsp::Sensors::Temperature::getCurrentValue() const {
  return m_currentValue;
}

//
// VirusOne::Pollable methods
//

void
VirusEsp::Sensors::Temperature::poll() {
  /*
   * Business logic to actually read the temperature sensor's current value and
   * store it on the m_currentValue member.
   */
}

void
VirusEsp::Sensors::Temperature::destroy() {
  /*
   * Perform any logical shutdown required to detach from the temperature sensor
   * and stop reading it.
   */
}
