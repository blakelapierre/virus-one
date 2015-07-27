// experiments/json_write.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virus_macros.h>
#include <experiments/json/write.h>

#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <rapidjson/document.h>

VirusTest::Experiments::JsonWrite::JsonWrite()
: Experiment("JsonWrite")
{}

VirusTest::Experiments::JsonWrite::~JsonWrite()
{}

void
VirusTest::Experiments::JsonWrite::run(void) {
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

  pass();
}
