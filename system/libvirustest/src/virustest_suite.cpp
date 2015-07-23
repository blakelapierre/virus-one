// virustest_suite.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest_suite.h>
#include <virustest_controller.h>

VirusTest::Suite::Suite(const std::string& name)
: m_name(name)
, m_log(spdlog::get("suite"))
{}

VirusTest::Suite::~Suite()
{}

void
VirusTest::Suite::addController(std::shared_ptr<Controller> controller) {
  m_log->info("adding controller {}", controller->getName());
  m_controllers.push_back(controller);
}

bool
VirusTest::Suite::removeController(std::shared_ptr<Controller> controller) {
  ControllerListIterator cle = m_controllers.end();
  ControllerListIterator cli = std::find(m_controllers.begin(), cle, controller);
  if (cli == cle) {
    m_log->error("failed to remove controller {}", controller->getName());
    return false;
  }

  m_log->info("removing controller {}", controller->getName());
  m_controllers.erase(cli);

  return true;
}

void
VirusTest::Suite::run() {
  ControllerListIterator cli, cle = m_controllers.end();
  m_log->info("suite {} starting", m_name);
  for (cli = m_controllers.begin(); cli != cle; ++cli) {
    std::shared_ptr<Controller> controller = (*cli);
    m_log->info("controller {} starting", controller->getName().c_str());
    controller->run();
    m_log->info("controller {} finished", controller->getName());
  }
  m_log->info("suite {} complete", m_name);
}
