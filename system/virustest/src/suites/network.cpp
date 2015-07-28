// suites/network.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>

#include <virustest/suites/network.h>
#include <virustest/controllers/network/port_number.h>

VirusTest::Suites::Network::Network()
: VirusTest::Suite("Network")
{
  addController(std::make_shared< VirusTest::Controllers::Network::PortNumber >());
}

VirusTest::Suites::Network::~Network()
{}
