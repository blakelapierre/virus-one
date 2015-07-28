// suites/network.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>

#include <virusone-test/suites/network.h>
#include <virusone-test/controllers/network/port_number.h>

VirusTest::Suites::Network::Network()
: VirusTest::Suite("Network")
{
  addController(std::make_shared<VirusTest::Controllers::Network::PortNumber>());
}

VirusTest::Suites::Network::~Network()
{}
