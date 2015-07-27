// experiments/json_write.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest_experiment.h>

namespace VirusTest { namespace Experiments {

  class JsonWrite : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    JsonWrite();
    virtual ~JsonWrite();

  protected:

  };

} /* Experiments */ } /* VirusTest */
