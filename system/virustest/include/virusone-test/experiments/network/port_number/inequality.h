// experiments/network_port_number/inequality.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest/experiment.h>

namespace VirusTest { namespace Experiments { namespace Network { namespace PortNumber {

  class Inequality : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    Inequality();
    virtual ~Inequality();

  protected:

  };

} /* Network */ } /* PortNumber */ } /* Experiments */ } /* VirusTest */
