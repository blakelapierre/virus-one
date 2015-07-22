// virustest_environment.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <queue>
#include <list>
#include <memory>
#include <thread>
#include <spdlog/spdlog.h>

namespace VirusTest {

  class Suite;

  class Environment {
  public:

    Environment(const std::string& name);
    virtual ~Environment();

    void queueSuite(std::shared_ptr<Suite> suite);
    void run();

  protected: // methods

    void expireWorkers();
    static void workerThread(std::shared_ptr<Suite> suite);

  protected: // attributes

    std::string m_name;
    size_t m_maxWorkers;
    std::shared_ptr<spdlog::logger> m_log;

    typedef std::queue<std::shared_ptr<Suite>> SuiteQueue;
    SuiteQueue m_suiteQueue;

    typedef std::list<std::thread> WorkerList;
    typedef WorkerList::iterator WorkerListIterator;
    typedef WorkerList::const_iterator WorkerListConstIterator;
    WorkerList m_workers;

  };

}
