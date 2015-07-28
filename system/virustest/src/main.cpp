// test/main.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <spdlog/spdlog.h>

#include <virustest/system.h>
#include <virustest/environment.h>
#include <virustest/controller.h>
#include <virustest/experiment.h>

#include <virusone/services/timestamp.h>

#include <virusone-test/suites/system.h>
#include <virusone-test/suites/network.h>
#include <virusone-test/suites/json.h>

/*
 * Main test script
 */
int main (int argc, char* argv[]) {

  VirusTest::System system;

  std::shared_ptr<spdlog::logger> log = spdlog::stdout_logger_mt("virustest");
  log->info("configuring tests");

  auto environment = std::make_shared<VirusTest::Environment>("virustest");
  environment->queueSuite(std::make_shared<VirusTest::Suites::System>());
  environment->queueSuite(std::make_shared<VirusTest::Suites::Network>());
  environment->queueSuite(std::make_shared<VirusTest::Suites::Json>());

  VirusOne::Services::Timestamp tsStart;
  environment->run();
  VirusOne::Services::Timestamp tsEnd;

  log->info("VirusOne Unit Tests completed in {} seconds", tsEnd.secondsFrom(tsStart));

  return 0;
}
