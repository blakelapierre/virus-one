#include <virus_macros.h>
#include <experiments/json_parse.h>

VirusTest::JsonParseExperiment::JsonParseExperiment()
: Experiment("JsonParseExperiment")
{}

VirusTest::JsonParseExperiment::~JsonParseExperiment()
{}

void
VirusTest::JsonParseExperiment::run() {
  const char* jsonText = "{ \"project\":\"virusone\", \"stars\":10 }";
  try {

    rapidjson::Document document;
    document.Parse(jsonText);

    expect(document.IsObject(), "generated document is not an object");
    expect(document.HasMember("project"), "generated document does not have a 'project' member");
    expect(document.HasMember("stars"), "generated document does not have a 'stars' member");

    rapidjson::Value& value = document["stars"];
    expect(value.IsNumber(), "stars member is not a number");
    expect(value == 10, "star count is not 10 as expected");

    value = document["project"];
    expect(value.IsString(), "project member is not a string");
    expect(value == "virusone", "project is not set to 'virusone'");

  } catch (std::exception e) {

    fail("an exception has occurred");

  }
}
