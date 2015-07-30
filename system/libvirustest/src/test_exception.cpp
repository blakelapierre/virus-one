// test_exception.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virustest/test_exception.h>

VirusTest::TestException::TestException(const std::string& message)
: VirusOne::System::Exception(message)
{}

VirusTest::TestException::~TestException()
{}

const char*
VirusTest::TestException::what() {
  return (std::string("TestException: ") + std::string(m_message)).c_str();
}
