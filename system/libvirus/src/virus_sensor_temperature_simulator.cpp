// virus_sensor_temperature_simulator.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

// Will be adding C++11 chrono features.
// http://www.informit.com/articles/article.aspx?p=1881386&seqNum=2

#include "virus_sensor_temperature_simulator.h"

rapidjson::Value g_sensorTypeName;

VirusOne::TemperatureSensorSimulator::TemperatureSensorSimulator()
: Sensor()
{}

VirusOne::TemperatureSensorSimulator::TemperatureSensorSimulator(uuid_t sensorUuid)
: Sensor(sensorUuid)
{}

VirusOne::TemperatureSensorSimulator::~TemperatureSensorSimulator()
{}

bool
VirusOne::TemperatureSensorSimulator::reset() {
  printf("resetting temperature sensor %s\n", m_sensorUuidString);
  return true;
}

bool
VirusOne::TemperatureSensorSimulator::isConnected() {
  return true;
}

bool
VirusOne::TemperatureSensorSimulator::isCalibrated() {
  return true;
}

const rapidjson::Value&
VirusOne::TemperatureSensorSimulator::getCurrentValue() {
  m_currentValue = 76 + (rand() % 4);
  return m_currentValue;
}
