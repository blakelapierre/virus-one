#pragma once

#include <sensors/temperature.h>

namespace VirusEsp { namespace SensorSimulators {

  class Temperature : public VirusEsp::Sensors::Temperature {
  public:

    Temperature();
    virtual ~Temperature();

    virtual void initialize(/* portNumber */);
    virtual void poll();

  };

} /* Sensors */ } /* VirusEsp */
