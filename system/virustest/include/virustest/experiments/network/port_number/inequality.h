// experiments/network_port_number/inequality.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest_experiment.h>

namespace VirusTest { namespace Experiments { namespace NetworkPortNumber {

  class Inequality : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    Inequality();
    virtual ~Inequality();

  protected:

  };

} /* NetworkPortNumber */ } /* Experiments */ } /* VirusTest */
