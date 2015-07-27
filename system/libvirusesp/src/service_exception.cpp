
#include <virusone/macros.h>
#include <virusesp/service_exception.h>
#include <cstdarg>

VirusEsp::ServiceException::ServiceException(
  const std::string& serviceName,
  const std::string& fmt,
  ...
)
: VirusOne::System::Exception()
, serviceName(serviceName)
{
  va_list args;
  va_start(args, fmt);
  buildMessage(serviceName + " " + fmt, args);
  va_end(args);
}

VirusEsp::ServiceException::ServiceException(
  const ServiceException& exception
)
: Exception(exception)
, serviceName(exception.serviceName)
{}

VirusEsp::ServiceException::~ServiceException()
{}
