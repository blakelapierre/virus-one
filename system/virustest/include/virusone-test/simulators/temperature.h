// temperature_simulator.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusesp/sensors/temperature.h>

namespace VirusEsp { namespace Simulators { namespace Sensors {

  class Temperature : public VirusEsp::Sensors::Temperature {
  public:

    Temperature();
    virtual ~Temperature();

    virtual void initialize(/* portNumber */);
    virtual void poll();

  };

} /* Sensors */ } /* Simulators */ } /* VirusEsp */
