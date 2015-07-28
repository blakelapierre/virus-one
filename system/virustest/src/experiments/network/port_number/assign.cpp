// experiments/network_port_number/assign.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/network/port_number.h>

#include <virustest/experiments/network/port_number/assign.h>

VirusTest::Experiments::Network::PortNumber::Assign::Assign()
: Experiment("Network::PortNumber::Assign")
{}

VirusTest::Experiments::Network::PortNumber::Assign::~Assign()
{}

void
VirusTest::Experiments::Network::PortNumber::Assign::run() {
  VirusOne::Network::PortNumber portNumber;
  expect(portNumber.value() == 0, "constructor", "network port did not initialize to zero");

  portNumber = 80;
  expect(portNumber.value() == 80, "assignment operator", "network port number assignment operator has failed");

  VirusOne::Network::PortNumber portNumberCopy(portNumber);
  expect(portNumberCopy.value() == 80, "copy constructor", "network port copy constructor has failed");

  VirusOne::Network::PortNumber initializedPortNumber(80);
  expect(portNumberCopy.value() == 80, "parameterized constructor", "network port parameterized constructor has failed");

  VirusOne::Network::PortNumber newPortNumber(8080);
  expect(newPortNumber.value() == 8080, "parameterized constructor", "network part parameterized constructor has failed");

  portNumber = newPortNumber;
  expect(portNumber.value() == 8080, "assignment operator", "network port assignment operator has failed");
  expect(newPortNumber.value() == 8080, "const correctness", "source port number altered during assign");

  pass();
}
