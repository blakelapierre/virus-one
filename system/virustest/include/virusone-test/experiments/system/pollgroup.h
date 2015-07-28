// experiments/pollgroup_poll.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest/experiment.h>

namespace VirusTest { namespace Experiments {

  class PollGroup : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    PollGroup();
    virtual ~PollGroup();

  protected:

  };

} /* Experiments */ } /* VirusTest */
