// virustest_experiment.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest_experiment.h>
#include <virustest_exception.h>

#include <algorithm>

VirusTest::Experiment::Experiment(const std::string& name)
: m_name(name)
, m_result(kResultIncomplete)
{}

VirusTest::Experiment::~Experiment()
{}

const std::string&
VirusTest::Experiment::getName()
{
  return m_name;
}

void
VirusTest::Experiment::addChild(Experiment* pExperiment) {
  m_children.push_back(pExperiment);
}

bool
VirusTest::Experiment::removeChild(Experiment* pExperiment) {
  ChildListIterator e = std::find(m_children.begin(), m_children.end(), pExperiment);
  if (e == m_children.end()) {
    return false;
  }
  m_children.erase(e);
  return true;
}

void
VirusTest::Experiment::expect(bool predicate, const std::string& message) {
  if (predicate) return;
  fail(message);
}

void
VirusTest::Experiment::setResult(ExperimentResult result) {
  m_result = result;
}

void
VirusTest::Experiment::pass() {
  setResult(kResultPass);
}

void
VirusTest::Experiment::fail(const std::string& message) {
  setResult(kResultFail);
  throw new VirusTest::Exception(message);
}

void
VirusTest::Experiment::incomplete(const std::string& message) {
  setResult(kResultIncomplete);
  throw new VirusTest::Exception(message);
}

VirusTest::Experiment::ExperimentResult
VirusTest::Experiment::getResult() const {
  return m_result;
}

const std::string
VirusTest::Experiment::getResultText() const {
  switch (m_result) {
    case kResultFail:
      return "kResultFail";
    case kResultPass:
      return "kResultPass";
    case kResultIncomplete:
      return "kResultIncomplete";
    default:
      break;
  }
  return "[INVALID RESULT CODE]";
}
