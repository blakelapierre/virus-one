// controllers/vendor/rapidjson.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>

#include <virusone-test/controllers/vendors/rapidjson.h>
#include <virusone-test/experiments/vendors/rapidjson/parse.h>
#include <virusone-test/experiments/vendors/rapidjson/write.h>


VirusTest::Controllers::Vendors::RapidJson::RapidJson()
: VirusTest::Controller("Vendors::RapidJson")
{
  addExperiment(std::make_shared<VirusTest::Experiments::Vendors::RapidJson::Parse>());
  addExperiment(std::make_shared<VirusTest::Experiments::Vendors::RapidJson::Write>());
}

VirusTest::Controllers::Vendors::RapidJson::~RapidJson()
{}
