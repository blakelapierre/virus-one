// services/uuid.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/services/uuid.h>

VirusOne::Services::Uuid::Uuid() {
  generate();
}

VirusOne::Services::Uuid::Uuid(const Uuid& uuid) {
  uuid_copy(m_value, uuid.m_value);
  updateValueString();
}

VirusOne::Services::Uuid::Uuid(uuid_t uuid) {
  uuid_copy(m_value, uuid);
  updateValueString();
}

VirusOne::Services::Uuid::~Uuid() {
  uuid_clear(m_value);
  m_valueString = std::string("");
}

void
VirusOne::Services::Uuid::generate() {
  uuid_generate(m_value);
  updateValueString();
}

void
VirusOne::Services::Uuid::operator = (const Uuid& uuid) {
  uuid_copy(m_value, uuid.m_value);
  m_valueString = uuid.m_valueString;
}

void
VirusOne::Services::Uuid::operator = (const uuid_t uuid) {
  uuid_copy(m_value, uuid);
  updateValueString();
}

void
VirusOne::Services::Uuid::updateValueString() {
  char valueString[40];
  uuid_unparse(m_value, valueString);
  m_valueString = valueString;
}
