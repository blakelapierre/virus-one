// suites/json.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest/controller.h>

#include <virusone-test/suites/json.h>
#include <virusone-test/experiments/json/parse.h>
#include <virusone-test/experiments/json/write.h>

VirusTest::Suites::Json::Json()
: VirusTest::Suite("JSON Processing")
{
  auto controller = std::make_shared<VirusTest::Controller>("JSON Test Controller");
  controller->addExperiment(std::make_shared<VirusTest::Experiments::JsonParse>());
  controller->addExperiment(std::make_shared<VirusTest::Experiments::JsonWrite>());
  addController(controller);
}

VirusTest::Suites::Json::~Json()
{}
