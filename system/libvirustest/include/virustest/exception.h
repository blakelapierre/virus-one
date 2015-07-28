// virustest_exception.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <exception>
#include <string>

namespace VirusTest {

  class Exception : public std::exception {
  public:

    Exception(const std::string& message) : m_message(message) {}
    virtual ~Exception() {}

    virtual const char* what() { return m_message.c_str(); }

  protected:

    std::string m_message;

  };

}
