// experiments/json_parse.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest/experiment.h>

namespace VirusTest { namespace Experiments {

  class JsonParse : public VirusTest::Experiment {
  public: // interface methods

    virtual void run();

  public: // methods

    JsonParse();
    virtual ~JsonParse();

  protected:

  };

} /* Experiments */ } /* VirusTest */
