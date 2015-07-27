// services/log.cpp
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT (see LICENSE)

#include <virusone/macros.h>
#include <virusone/services/log.h>

#include <spdlog/spdlog.h>

void
VirusOne::Services::Log::info(const std::string& message) {
  spdlog::get("virusone")->info(message);
}

void
VirusOne::Services::Log::warn(const std::string& message) {
  spdlog::get("virusone")->warn(message);
}

void
VirusOne::Services::Log::error(const std::string& message) {
  spdlog::get("virusone")->error(message);
}

void
VirusOne::Services::Log::system(const std::string& message) {
  // @TODO i18n
  spdlog::get("virusone")->info(std::string("SYSTEM MESSAGE: ") + message);
}

void
VirusOne::Services::Log::fatal(const std::string& message) {
  spdlog::get("virusone")->error(message);
}

void
VirusOne::Services::Log::debug(const std::string& message) {
  spdlog::get("virusone")->debug(message);
}

void
VirusOne::Services::Log::write(Level eLevel, const std::string& message) {
  spdlog::get("virusone")->info(message);
}
