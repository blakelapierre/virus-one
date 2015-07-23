// virus_test_controller.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest_controller.h>
#include <virustest_experiment.h>
#include <algorithm>

VirusTest::Controller::Controller(
  const std::string& name
)
: m_name(name)
, m_log(spdlog::get("controller"))
{}

VirusTest::Controller::~Controller()
{}

void
VirusTest::Controller::addExperiment(std::shared_ptr<Experiment> experiment) {
  m_log->info("add experiment [{}]", experiment->getName());
  m_experiments.push_back(experiment);
}

bool
VirusTest::Controller::removeExperiment(std::shared_ptr<Experiment> experiment) {
  m_log->info("remove experiment [{}]", experiment->getName());
  ExperimentListIterator ei = std::find(m_experiments.begin(), m_experiments.end(), experiment);
  if (ei == m_experiments.end()) {
    return false;
  }
  m_experiments.erase(ei);
  return true;
}

void
VirusTest::Controller::run() {
  this->runExperiments();
  this->runChildren();
}

void
VirusTest::Controller::runExperiments() {
  ExperimentListIterator ei, ee = m_experiments.end();
  m_log->info("running experiments");
  for (ei = m_experiments.begin(); ei != ee; ++ei) {
    std::shared_ptr<Experiment> experiment = (*ei);
    m_log->info("starting experiment [{}]", experiment->getName());
    experiment->run();
    m_log->info("finished experiment [result={}]", experiment->getResultText());
    m_log->info("experiment [{}] result [{}]", experiment->getName(), experiment->getResultText());
  }
  m_log->info("finished experiments");
}

void
VirusTest::Controller::runChildren() {
  if (m_children.empty()) {
    return;
  }

  m_log->info("running child controllers");
  ChildListIterator ci, ce = m_children.end();
  for (ci = m_children.begin(); ci != ce; ++ci) {
    std::shared_ptr<Controller> child = (*ci);
    child->run();
  }
  m_log->info("finished child controllers");
}
