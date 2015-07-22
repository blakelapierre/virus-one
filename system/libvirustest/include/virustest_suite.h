// virustest_suite.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <string>
#include <list>
#include <memory>
#include <spdlog/spdlog.h>

namespace VirusTest {

  class Controller;

  class Suite {
  public:

    Suite(const std::string& name);
    virtual ~Suite();

    const std::string& getName() { return m_name; }

    void addController(std::shared_ptr<Controller> controller);
    bool removeController(std::shared_ptr<Controller> controller);

    void run();

  protected:

    std::string m_name;
    std::shared_ptr<spdlog::logger> m_log;

    typedef std::list<std::shared_ptr<Controller>> ControllerList;
    typedef ControllerList::iterator ControllerListIterator;
    typedef ControllerList::const_iterator ControllerListConstIterator;
    ControllerList m_controllers;

  };

}
