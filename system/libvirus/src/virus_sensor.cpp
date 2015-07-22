// virus_sensor.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include "virus_sensor.h"

VirusOne::Sensor::Sensor() {
  uuid_generate(m_sensorUuid);
  uuid_unparse(m_sensorUuid, m_sensorUuidString);
}

VirusOne::Sensor::Sensor(uuid_t sensorUuid) {
  uuid_copy(m_sensorUuid, sensorUuid);
  uuid_unparse(m_sensorUuid, m_sensorUuidString);
}

VirusOne::Sensor::~Sensor() {
  uuid_clear(m_sensorUuid);
}
