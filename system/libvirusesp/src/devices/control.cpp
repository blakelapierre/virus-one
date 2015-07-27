// devices/control.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusesp/devices/control.h>

VirusEsp::Devices::Control::Control(
  const std::string& name
)
: Device(name)
{}

VirusEsp::Devices::Control::Control(
  const std::string& name,
  uuid_t controlUuid
)
: Device(name, controlUuid)
{}

VirusEsp::Devices::Control::~Control() {

}

bool
VirusEsp::Devices::Control::setCurrentValue(rapidjson::Value& value) {
  m_value = value;
}

const rapidjson::Value&
VirusEsp::Devices::Control::getCurrentValue() {
  return m_value;
}
