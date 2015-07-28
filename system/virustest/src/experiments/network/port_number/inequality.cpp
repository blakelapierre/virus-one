// experiments/network_port_number/inequality.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/network/port_number.h>

#include <virusone-test/experiments/network/port_number/inequality.h>

VirusTest::Experiments::Network::PortNumber::Inequality::Inequality()
: Experiment("Network::PortNumber::Inequality")
{}

VirusTest::Experiments::Network::PortNumber::Inequality::~Inequality()
{}

void
VirusTest::Experiments::Network::PortNumber::Inequality::run() {
  VirusOne::Network::PortNumber portNumber1(80);
  VirusOne::Network::PortNumber portNumber2(8080);
  expect(portNumber1 != portNumber2, "Inequality", "network port numbers match when they shouldn't");
  pass();
}
