// suites/json.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest_controller.h>

#include <suites/json.h>
#include <experiments/json_parse.h>
#include <experiments/json_write.h>

VirusTest::Suites::Json::Json()
: VirusTest::Suite("JSON Processing")
, m_controller(std::make_shared<VirusTest::Controller>("JSON Test Controller"))
{
  m_controller->addExperiment(std::make_shared<VirusTest::Experiments::JsonParse>());
  m_controller->addExperiment(std::make_shared<VirusTest::Experiments::JsonWrite>());
  addController(m_controller);
}

VirusTest::Suites::Json::~Json()
{}
