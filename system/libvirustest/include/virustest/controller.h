// virustest_controller.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <memory>
#include <string>
#include <list>

#include <spdlog/spdlog.h>

namespace VirusTest {

  class Experiment;

  /**
   * Implements the VirusTest test controller. Test controllers accept runnable
   * test objects into their execution queue and run them when the start()
   * method is called, returning the aggregate pass/fail result of all executed
   * tests.
   */
  class Controller {
  public:

    Controller(const std::string& name);
    virtual ~Controller();

    const std::string& getName() { return m_name; }

    virtual std::shared_ptr<Experiment> addExperiment(std::shared_ptr<Experiment> experiment);
    virtual bool removeExperiment(std::shared_ptr<Experiment> experiment);

    virtual void run();

  protected:

    typedef std::list<std::shared_ptr<Experiment>> ExperimentList;
    typedef ExperimentList::iterator ExperimentListIterator;
    typedef ExperimentList::const_iterator ExperimentListConstIterator;
    ExperimentList m_experiments;

    typedef std::list<std::shared_ptr<Controller>> ChildList;
    typedef ChildList::iterator ChildListIterator;
    typedef ChildList::const_iterator ChildListConstIterator;
    ChildList m_children;

  protected: // methods

    std::string m_name;
    std::shared_ptr<spdlog::logger> m_log;

    void runExperiments();
    void runChildren();

  };

}
