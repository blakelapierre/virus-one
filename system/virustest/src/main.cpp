// test/main.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <spdlog/spdlog.h>

#include <virustest_system.h>
#include <virustest_environment.h>
#include <virustest_controller.h>
#include <virustest_experiment.h>

#include <virus_timestamp.h>
#include <virus_sensor_temperature_simulator.h>

#include <suites/json.h>

/*
 * Main test script
 */
int main (int argc, char* argv[]) {

  VirusTest::System system;

  std::shared_ptr<spdlog::logger> log = spdlog::stdout_logger_mt("virustest");
  log->info("configuring tests");

  auto environment = std::make_shared<VirusTest::Environment>("virustest");
  environment->queueSuite(std::make_shared<VirusTest::Suites::Json>());

  VirusOne::Timestamp tsStart;
  environment->run();
  VirusOne::Timestamp tsEnd;

  log->info("VirusOne Unit Tests completed in {} seconds", tsEnd.secondsFrom(tsStart));

  return 0;
}
