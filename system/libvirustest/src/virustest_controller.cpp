// virus_test_controller.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest/controller.h>
#include <virustest/experiment.h>
#include <algorithm>

VirusTest::Controller::Controller(
  const std::string& name
)
: m_name(name)
, m_log(spdlog::get("controller"))
{}

VirusTest::Controller::~Controller()
{}

std::shared_ptr<VirusTest::Experiment>
VirusTest::Controller::addExperiment(std::shared_ptr<Experiment> experiment) {
  m_log->debug("{} add experiment [{}]", m_name, experiment->getName());
  m_experiments.push_back(experiment);
  return experiment;
}

bool
VirusTest::Controller::removeExperiment(std::shared_ptr<Experiment> experiment) {
  m_log->debug("{} remove experiment [{}]", m_name, experiment->getName());
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
  m_log->debug("{} running experiments", m_name);
  for (ei = m_experiments.begin(); ei != ee; ++ei) {
    std::shared_ptr<Experiment> experiment = (*ei);
    m_log->info("{} starting experiment {}", m_name, experiment->getName());
    experiment->run();
    m_log->debug("{} finished experiment ({})", m_name, experiment->getResultText());
  }
  m_log->debug("{} finished experiments", m_name);
}

void
VirusTest::Controller::runChildren() {
  if (m_children.empty()) {
    return;
  }

  m_log->debug("running child controllers");
  ChildListIterator ci, ce = m_children.end();
  for (ci = m_children.begin(); ci != ce; ++ci) {
    std::shared_ptr<Controller> child = (*ci);
    child->run();
  }
  m_log->debug("finished child controllers");
}
