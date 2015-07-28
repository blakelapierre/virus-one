// experiments/network_port_number/less_than.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest_experiment.h>

namespace VirusTest { namespace Experiments { namespace Network { namespace PortNumber {

  class LessThan : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    LessThan();
    virtual ~LessThan();

  protected:

  };

} /* Network */ } /* PortNumber */ } /* Experiments */ } /* VirusTest */
