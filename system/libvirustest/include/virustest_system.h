// virustest_system.h
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#pragma once

#include <spdlog/spdlog.h>

namespace VirusTest {

  class System {
  public:

    System();
    virtual ~System();

  protected:

    std::shared_ptr<spdlog::logger> m_systemLog;
    std::shared_ptr<spdlog::logger> m_environmentLog;
    std::shared_ptr<spdlog::logger> m_suiteLog;
    std::shared_ptr<spdlog::logger> m_controllerLog;
    std::shared_ptr<spdlog::logger> m_experimentLog;

  };

}
