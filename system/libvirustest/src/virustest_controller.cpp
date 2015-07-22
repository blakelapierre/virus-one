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
, m_log(spdlog::get("controllers"))
{}

VirusTest::Controller::~Controller()
{}

void
VirusTest::Controller::addExperiment(Experiment* pExperiment) {
  m_log->info("add experiment [{}]", pExperiment->getName());
  m_experiments.push_back(pExperiment);
}

bool
VirusTest::Controller::removeExperiment(Experiment* pExperiment) {
  m_log->info("remove experiment [{}]", pExperiment->getName());
  ExperimentListIterator ei = std::find(m_experiments.begin(), m_experiments.end(), pExperiment);
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
    Experiment* e = (*ei);
    m_log->info("starting experiment [{}]", e->getName().c_str());
    e->run();
    m_log->info("finished experiment [result={}]", e->getResultText());
    m_log->info("experiment [{}] result [{}]", (*ei)->getName().c_str(), (*ei)->getResultText().c_str());
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
    Controller* pChild = (*ci);
    pChild->run();
  }
  m_log->info("finished child controllers");
}
