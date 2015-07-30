// experiments/json_write.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone-test/experiments/vendors/rapidjson/write.h>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <rapidjson/document.h>

VirusTest::Experiments::Vendors::RapidJson::Write::Write()
: Experiment("Vendors::RapidJson::Write")
{}

VirusTest::Experiments::Vendors::RapidJson::Write::~Write()
{}

void
VirusTest::Experiments::Vendors::RapidJson::Write::run(void) {
  it("should write JSON objects", [this]() {
    rapidjson::Document document(rapidjson::kObjectType);
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

    if (!document.IsObject()) {
      fail("document is not an object");
      return;
    }

    rapidjson::Value samples(rapidjson::kArrayType);
    rapidjson::Value sample;

    sample.SetObject();
    sample.AddMember("temp", 72, allocator);
    samples.PushBack(sample, allocator);

    sample.SetObject();
    sample.AddMember("temp", 73, allocator);
    samples.PushBack(sample, allocator);

    sample.SetObject();
    sample.AddMember("temp", 74, allocator);
    samples.PushBack(sample, allocator);

    document.AddMember("samples", samples, allocator);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    const std::string expectedResult = "{\"samples\":[{\"temp\":72},{\"temp\":73},{\"temp\":74}]}";
    if (buffer.GetString() != expectedResult) {
      fail("generated JSON text is incorrect");
      return;
    }
  });
}
