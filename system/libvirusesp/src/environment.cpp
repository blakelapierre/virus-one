
#include <virusone/system/macros.h>
#include <virusesp/environment.h>

VirusEsp::Environment::Environment(
  const std::string& name
)
: m_name(name)
{}

VirusEsp::Environment::~Environment()
{
  destroy();
}

void
VirusEsp::Environment::addService(ServicePtr service) {

}

bool
VirusEsp::Environment::findService(
  const VirusOne::Uuid& serviceUuid,
  ServicePtr& service
) {
  return false;
}

void
VirusEsp::Environment::addDevice(DevicePtr service) {

}

bool
VirusEsp::Environment::findDevice(
  const VirusOne::Uuid& deviceUuid,
  DevicePtr& device
)
{
  return false;
}

void
VirusEsp::Environment::poll() {
  
}

void
VirusEsp::Environment::destroy() {
  
}
