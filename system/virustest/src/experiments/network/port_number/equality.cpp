// experiments/network_port_number/equality.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/network/port_number.h>

#include <virusone-test/experiments/network/port_number/equality.h>

VirusTest::Experiments::Network::PortNumber::Equality::Equality()
: Experiment("Network::PortNumber::Equality")
{}

VirusTest::Experiments::Network::PortNumber::Equality::~Equality()
{}

void
VirusTest::Experiments::Network::PortNumber::Equality::run() {
  VirusOne::Network::PortNumber portNumber1(80);
  VirusOne::Network::PortNumber portNumber2(80);
  expect(portNumber1 == portNumber2, "Equality (positive)", "network port numbers do not match");

  pass();
}
