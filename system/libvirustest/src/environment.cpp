// environment.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest/environment.h>
#include <virustest/suite.h>

VirusTest::Environment::Environment(const std::string& name)
: m_name(name)
, m_log(spdlog::get("environment"))
{
  auto concurrency = std::thread::hardware_concurrency();
  m_maxWorkers = concurrency == 0 ? 4 : concurrency;
  m_log->debug("maxWorkers {}", m_maxWorkers);
}

VirusTest::Environment::~Environment()
{}

void
VirusTest::Environment::queueSuite(std::shared_ptr<Suite> suite) {
  m_suiteQueue.push(suite);
}

void
VirusTest::Environment::run() {
  m_log->debug("environment {} starting with {} queued suites", m_name, m_suiteQueue.size());
  while (!m_suiteQueue.empty()) {
    if (m_workers.size() >= m_maxWorkers) {
      std::this_thread::yield();
      expireWorkers();
      continue;
    }

    while (!m_suiteQueue.empty() && (m_workers.size() < m_maxWorkers)) {
      m_log->debug("worker accepting suite {}", m_suiteQueue.front()->getName());
      m_workers.push_back(std::thread(workerThread, m_suiteQueue.front()));
      m_suiteQueue.pop();
    }

  }

  while (!m_workers.empty()) {
    std::this_thread::yield();
    expireWorkers();
  }
}

void
VirusTest::Environment::workerThread(std::shared_ptr<Suite> suite) {
  std::shared_ptr<spdlog::logger> log = spdlog::get("environment");
  log->debug("starting suite {}", suite->getName());
  suite->run();
}

void
VirusTest::Environment::expireWorkers() {
  WorkerListIterator wli, wle = m_workers.end();
  for (wli = m_workers.begin(); wli != wle; ) {
    if ((*wli).joinable()) {
      (*wli).join();
      wli = m_workers.erase(wli);
      continue;
    }
    ++wli;
  }
}
