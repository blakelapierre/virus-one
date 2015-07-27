// devices/controls/analog.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusesp/devices/control.h>

namespace VirusEsp { namespace Devices { namespace Controls { 

  class Analog : public Control {
  public: // interface methods

    virtual bool Control::setCurrentValue(const rapidjson::Value& value);
    virtual const rapidjson::Value& getCurrentValue();

  public: // methods

    Analog();
    virtual ~Analog();

  };

} /* Controls */ } /* Devices */ } /* VirusEsp */
