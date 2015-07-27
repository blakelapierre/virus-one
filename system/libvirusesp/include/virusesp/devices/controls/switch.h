// devices/controls/switch.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusesp/devices/control.h>
#include <rapidjson/document.h>

namespace VirusEsp { namespace Controls { 

  class Switch : public VirusEsp::Devices::Control {
  public: // interface methods

    virtual bool setCurrentValue(const rapidjson::Value& value);
    virtual rapidjson::Value getCurrentValue();

  public: // methods

    Switch();
    Switch(uuid_t controlUuid);
    virtual ~Switch();

  };

} /* Controls */ } /* VirusEsp */
