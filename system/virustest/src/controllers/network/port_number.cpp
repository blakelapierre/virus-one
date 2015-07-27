// controllers/network/port_number.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virus_macros.h>
#include <controllers/network/port_number.h>

/*
 * Controlled Experiments
 */
#include <experiments/network/port_number/assign.h>
// #include <experiments/network/port_number/equality.h>
// #include <experiments/network/port_number/inequality.h>
// #include <experiments/network/port_number/less_than.h>
// #include <experiments/network/port_number/greater_than.h>
// #include <experiments/network/port_number/to_string.h>
// #include <experiments/network/port_number/from_string.h>

VirusTest::Controllers::Network::PortNumber::PortNumber()
: VirusTest::Controller("Network::PortNumber")
{
  addExperiment(std::make_shared<VirusTest::Experiments::Network::PortNumber::Assign>());
  // addExperiment(std::make_shared<VirusTest::Experiments::Network::PortNumber::ToString>());
  // addExperiment(std::make_shared<VirusTest::Experiments::Network::PortNumber::FromString>());
  // addExperiment(std::make_shared<VirusTest::Experiments::Network::PortNumber::Equality>());
  // addExperiment(std::make_shared<VirusTest::Experiments::Network::PortNumber::Inequality>());
  // addExperiment(std::make_shared<VirusTest::Experiments::Network::PortNumber::LessThan>());
  // addExperiment(std::make_shared<VirusTest::Experiments::Network::PortNumber::GreaterThan>());
}

VirusTest::Controllers::Network::PortNumber::~PortNumber()
{}
