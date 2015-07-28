// experiments/json_parse.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone-test/experiments/json/parse.h>
#include <rapidjson/document.h>

VirusTest::Experiments::JsonParse::JsonParse()
: Experiment("JsonParse")
{}

VirusTest::Experiments::JsonParse::~JsonParse()
{}

void
VirusTest::Experiments::JsonParse::run() {
  const char* jsonText = "{ \"project\":\"virusone\", \"stars\":10 }";
  try {

    rapidjson::Document document;
    document.Parse(jsonText);

    expect(document.IsObject(), "JsonParse", "generated document is not an object");
    expect(document.HasMember("project"), "JsonParse", "generated document does not have a 'project' member");
    expect(document.HasMember("stars"), "JsonParse", "generated document does not have a 'stars' member");

    rapidjson::Value& value = document["stars"];
    expect(value.IsNumber(), "JsonParse", "stars member is not a number");
    expect(value == 10, "JsonParse", "star count is not 10 as expected");

    value = document["project"];
    expect(value.IsString(), "JsonParse", "project member is not a string");
    expect(value == "virusone", "JsonParse", "project is not set to 'virusone'");

  } catch (std::exception e) {

    fail("an exception has occurred");

  }
}
