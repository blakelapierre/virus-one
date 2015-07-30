// suites/vendors/rapidjson.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone-test/suites/vendors/rapidjson.h>

#include <virusone-test/controllers/vendors/rapidjson.h>

#include <virusone-test/experiments/vendors/rapidjson/parse.h>
#include <virusone-test/experiments/vendors/rapidjson/write.h>

VirusTest::Suites::Vendors::RapidJson::RapidJson::RapidJson()
: VirusTest::Suite("RapidJSON")
{
  auto controller = std::make_shared<VirusTest::Controllers::Vendors::RapidJson>();
  controller->addExperiment(std::make_shared<VirusTest::Experiments::Vendors::RapidJson::Parse>());
  controller->addExperiment(std::make_shared<VirusTest::Experiments::Vendors::RapidJson::Write>());
  addController(controller);
}

VirusTest::Suites::Vendors::RapidJson::~RapidJson()
{}
