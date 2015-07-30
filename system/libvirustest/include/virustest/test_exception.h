// test_exception.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <virusone/system/exception.h>

namespace VirusTest {

  class TestException : public VirusOne::System::Exception {
  public: // methods

    TestException(const std::string& message);
    virtual ~TestException();

    virtual const char* what();

  };

}
