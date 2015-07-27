// device.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusesp/device.h>
#include <uuid/uuid.h>

VirusEsp::Device::Device(
  const std::string& name
)
: Pollable(name)
{}

VirusEsp::Device::Device(
  const std::string& name,
  const VirusOne::Services::Uuid& uuid
)
: Pollable(name)
, m_uuid(uuid)
{}

VirusEsp::Device::~Device()
{}
