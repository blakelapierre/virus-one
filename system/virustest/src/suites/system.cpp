// suites/system.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virus_macros.h>
#include <virustest_controller.h>
#include <suites/system.h>

VirusTest::Suites::System::System()
: VirusTest::Suite("VirusOne System")
{
  auto controller = std::make_shared<VirusTest::Controller>("Pollable");
  addController(controller);

  controller = std::make_shared<VirusTest::Controller>("PollGroup");
  addController(controller);
}

VirusTest::Suites::System::~System()
{}
