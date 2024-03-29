// system.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virustest/system.h>

VirusTest::System::System()
: m_systemLog(spdlog::stdout_logger_mt("system"))
, m_environmentLog(spdlog::stdout_logger_mt("environment"))
, m_suiteLog(spdlog::stdout_logger_mt("suite"))
, m_controllerLog(spdlog::stdout_logger_mt("controller"))
, m_experimentLog(spdlog::stdout_logger_mt("experiment"))
{}

VirusTest::System::~System()
{}
