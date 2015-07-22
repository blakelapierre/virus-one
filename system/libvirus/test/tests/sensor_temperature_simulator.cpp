// test/port_number.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <assert.h>

#include "virus_port_number.h"
#include "port_number.h"

static bool sts_reset(void) {
  VirusOne::TemperatureSensorSimulator ts;
  assert(ts.reset() == true);
  return true;
}

static bool sts_current_value(void) {
  const rapidjson::Value& temp = ts.getCurrentValue();
  assert(temp.GetDouble() > 0.0);
  return true;
}

bool
VirusTest::sensor_temperature_simulator(void) {
  return true;
}
