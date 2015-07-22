// virustest_environment.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest_environment.h>
#include <virustest_suite.h>

VirusTest::Environment::Environment(const std::string& name)
: m_name(name)
, m_log(spdlog::get("environment"))
{
  auto concurrency = std::thread::hardware_concurrency();
  m_maxWorkers = concurrency == 0 ? 4 : concurrency;
  m_log->info("maxWorkers {}", m_maxWorkers);
}

VirusTest::Environment::~Environment()
{}

void
VirusTest::Environment::queueSuite(std::shared_ptr<Suite> suite) {
  m_suiteQueue.push(suite);
}

void
VirusTest::Environment::run() {
  m_log->info("environment {} starting with {} queued suites", m_name, m_suiteQueue.size());
  while (!m_suiteQueue.empty()) {
    if (m_workers.size() >= m_maxWorkers) {
      std::this_thread::yield();
      expireWorkers();
      continue;
    }

    while (!m_suiteQueue.empty() && (m_workers.size() < m_maxWorkers)) {
      m_log->info("worker accepting suite {}", m_suiteQueue.front()->getName());
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
  log->info("suite {} starting", suite->getName());
  suite->run();
  log->info("suite {} completed", suite->getName());
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
