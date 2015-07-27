// suites/network.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virus_macros.h>
#include <suites/network.h>

#include <controllers/network/port_number.h>

VirusTest::Suites::Network::Network()
: VirusTest::Suite("Network")
{
  addController(std::make_shared< VirusTest::Controllers::Network::PortNumber >());
}

VirusTest::Suites::Network::~Network()
{}
