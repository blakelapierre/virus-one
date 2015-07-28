// test/main.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <spdlog/spdlog.h>

#include <virustest_system.h>
#include <virustest_environment.h>
#include <virustest_controller.h>
#include <virustest_experiment.h>

#include <virusone/services/timestamp.h>

#include <virustest/suites/system.h>
#include <virustest/suites/network.h>
#include <virustest/suites/json.h>

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
