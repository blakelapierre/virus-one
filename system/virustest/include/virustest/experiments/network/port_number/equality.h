// experiments/network_port_number/equality.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest_experiment.h>

namespace VirusTest { namespace Experiments { namespace NetworkPortNumber {

  class Equality : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    Equality();
    virtual ~Equality();

  protected:

  };

} /* NetworkPortNumber */ } /* Experiments */ } /* VirusTest */
