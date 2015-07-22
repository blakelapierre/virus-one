// test/main.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <stdio.h>
#include <iostream>
#include <assert.h>

#include <spdlog/spdlog.h>

#include "port_number.h"
#include "json.h"

#include "virus_timestamp.h"
#include "virus_sensor_temperature_simulator.h"

namespace VirusTest {

  /**
   * Executes the given test function with standardized output and reporting.
   */
  bool run(bool (*testFunction)(void), const char* groupName, const char* testDesc) {
    printf("%-16s %-32s ", groupName, testDesc);
    if (!testFunction()) {
      printf("✖ Fail\n");
      return false;
    }
    printf("✔ Pass\n");
    return true;
  }

}

/*
 * Main test script
 */
int main (int argc, char* argv[]) {

  namespace spd = spdlog;
  auto console = spd::stdout_logger_mt("console");
  console->info("Welcome to spdlog!");  

  printf(
    "\n\n"
    "===============================================================================\n"
    "%-16s %-32s RESULT\n"
    "===============================================================================\n"
    , "COMPONENT"
    , "TEST NAME"
  );

  VirusOne::Timestamp tsStart;

  // VirusOne::PortNumber tests
  VirusTest::run(VirusTest::port_assignment, "PortNumber", "Value assignment");
  VirusTest::run(VirusTest::port_equality, "PortNumber", "Boolean equality");
  VirusTest::run(VirusTest::port_inequality, "PortNumber", "Boolean inequality");
  VirusTest::run(VirusTest::port_less_than, "PortNumber", "Boolean less than");
  VirusTest::run(VirusTest::port_greater_than, "PortNumber", "Boolean greater than");

  VirusTest::run(VirusTest::json_parse, "JSON", "JSON parse");
  VirusTest::run(VirusTest::json_write, "JSON", "JSON write");

  VirusOne::Timestamp tsEnd;
  printf(
    "===============================================================================\n"
    "VirusOne Unit Tests completed in %f seconds\n"
    "\n"
    , tsEnd.secondsFrom(tsStart)
  );

  return 0;
}
