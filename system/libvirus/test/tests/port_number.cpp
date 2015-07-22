// test/port_number.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <assert.h>

#include "virus_port_number.h"
#include "port_number.h"

/**
 * Tests that ports store correct and expected values.
 */
bool
VirusTest::port_assignment (void) {
  VirusOne::PortNumber port(8080);
  assert(port == 8080);

  port = 80;
  assert(port == 80);

  return true;
}

/**
 * Tests that ports properly support Boolean equality tests.
 */
bool
VirusTest::port_equality (void) {
  VirusOne::PortNumber port1(80);
  VirusOne::PortNumber port2(80);

  assert(port1 == port2);
  assert(port1 == 80);
  assert(port2 == 80);

  return true;
}

/**
 * Tests that ports properly support Boolean inequality tests.
 */
bool
VirusTest::port_inequality (void) {
  VirusOne::PortNumber port1(80);
  VirusOne::PortNumber port2(81);

  assert(port1 != 0);
  assert(port2 != 0);
  assert(port1 != port2);

  return true;
}

/**
 * Tests that ports properly support Boolean less-than tests.
 */
bool
VirusTest::port_less_than (void) {
  VirusOne::PortNumber port1(80);
  VirusOne::PortNumber port2(81);

  assert(port1 == 80);
  assert(port2 == 81);
  assert(port1 < port2);

  return true;
}

/**
 * Tests that ports properly support Boolean greater-than tests.
 */
bool
VirusTest::port_greater_than (void) {
  VirusOne::PortNumber port1(81);
  VirusOne::PortNumber port2(80);

  assert(port1 == 81);
  assert(port2 == 80);
  assert(port1 > port2);

  return true;
}
