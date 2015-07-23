// suites/json.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virustest_suite.h>

namespace VirusTest { namespace Suites {

  class Json : public VirusTest::Suite {
  public:

    Json();
    virtual ~Json();

  protected:

    std::shared_ptr<VirusTest::Controller> m_controller;

  };

}/*Suites*/ }/*VirusTest*/
