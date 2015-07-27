// experiments/network_port_number/assign.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest_experiment.h>

namespace VirusTest { namespace Experiments { namespace Network { namespace PortNumber {

  class Assign : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    Assign();
    virtual ~Assign();

  protected:

  };

} /* PortNumber */ } /* Network */ } /* Experiments */ } /* VirusTest */
