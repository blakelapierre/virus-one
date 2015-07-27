#pragma once

#include <virusone/system/exception.h>

namespace VirusEsp { 

  class ServiceException : public VirusOne::System::Exception {
  public:

    ServiceException(const std::string& serviceName, const std::string& fmt, ...);
    ServiceException(const ServiceException& exception);
    virtual ~ServiceException();

    const std::string& serviceName;

  };

} /* VirusEsp */
