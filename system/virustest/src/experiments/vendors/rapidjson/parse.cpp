// experiments/json_parse.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone-test/experiments/vendors/rapidjson/parse.h>
#include <rapidjson/document.h>

VirusTest::Experiments::Vendors::RapidJson::Parse::Parse()
: Experiment("Vendors::RapidJson::Parse")
{}

VirusTest::Experiments::Vendors::RapidJson::Parse::~Parse()
{}

void
VirusTest::Experiments::Vendors::RapidJson::Parse::run() {
  const char* jsonText = "{ \"project\":\"virusone\", \"stars\":10 }";
  try {

    rapidjson::Document document;
    document.Parse(jsonText);

    expect(document.IsObject(), "Document::IsObject", "generated document is not an object");
    expect(document.HasMember("project"), "Document::HasMember('project')", "generated document does not have a 'project' member");
    expect(document.HasMember("stars"), "Document::HasMember('stars')", "generated document does not have a 'stars' member");

    rapidjson::Value& value = document["stars"];
    expect(value.IsNumber(), "Value::IsNumber", "stars member is not a number");
    expect(value == 10, "Value Equality (integer)", "star count is not 10 as expected");

    value = document["project"];
    expect(value.IsString(), "Value::IsString", "project member is not a string");
    expect(value == "virusone", "Value Equality (string)", "project is not set to 'virusone'");

  } catch (std::exception e) {

    fail("an exception has occurred");

  }
}
