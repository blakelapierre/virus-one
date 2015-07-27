// virustest_experiment.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest_experiment.h>
#include <virustest_exception.h>

#include <algorithm>

VirusTest::Experiment::Experiment(const std::string& name)
: m_name(name)
, m_log(spdlog::get("experiment"))
, m_result(kResultIncomplete)
{}

VirusTest::Experiment::~Experiment()
{}

const std::string&
VirusTest::Experiment::getName()
{
  return m_name;
}

std::shared_ptr<VirusTest::Experiment>
VirusTest::Experiment::addChild(std::shared_ptr<Experiment> experiment) {
  m_children.push_back(experiment);
  return experiment;
}

bool
VirusTest::Experiment::removeChild(std::shared_ptr<Experiment> experiment) {
  ChildListIterator cli = std::find(m_children.begin(), m_children.end(), experiment);
  if (cli == m_children.end()) {
    return false;
  }
  m_children.erase(cli);
  return true;
}

void
VirusTest::Experiment::expect(bool predicate, const std::string& testName, const std::string& message) {
  if (predicate) {
    m_log->info("test {} PASS");
    return;
  }
  m_log->error("test {} produced unexpected results", testName);
  fail(message); // fail() throws an exception
}

void
VirusTest::Experiment::setResult(ExperimentResult result) {
  m_result = result;
}

void
VirusTest::Experiment::pass() {
  setResult(kResultPass);
  m_log->info("{} result PASS", m_name);
}

void
VirusTest::Experiment::fail(const std::string& message) {
  setResult(kResultFail);
  throw new VirusTest::/*ExperimentFail*/Exception(message);
}

void
VirusTest::Experiment::incomplete(const std::string& message) {
  setResult(kResultIncomplete);
  throw new VirusTest::/*ExperimentIncomplete*/Exception(message);
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
