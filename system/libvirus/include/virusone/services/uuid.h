// virusone/services/uuid.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <uuid/uuid.h>
#include <string>

namespace VirusOne { namespace Services {

  class Uuid {
  public:

    Uuid();
    Uuid(const Uuid& uuid);
    Uuid(uuid_t uuid);
    virtual ~Uuid();

    void generate();
    void operator = (const Uuid& uuid);
    void operator = (const uuid_t uuid);

  protected: // methods

    void updateValueString();

  protected: // attributes

    uuid_t m_value;
    std::string m_valueString;

  };

} /* Services */ } /* VirusOne */
