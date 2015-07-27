#pragma once

#include <virusone/services/pollable.h>
#include <virusone/services/pollgroup.h>

namespace VirusEsp {

  class Environment : public VirusOne::Pollable {
  public: // VirusOne::Pollable methods

    virtual void poll();
    virtual void destroy();

  public: // methods

    Environment(const std::string& name);
    virtual ~Environment();

    typedef std::shared_ptr<Service> ServicePtr;
    void addService(ServicePtr service);
    bool findService(const VirusOne::Uuid& serviceUuid, ServicePtr& service);

    typedef std::shared_ptr<Device> DevicePtr;
    void addDevice(DevicePtr service);
    bool findDevice(const VirusOne::Uuid& deviceUuid, DevicePtr& device);

  protected: // attributes

    typedef std::map<VirusOne::Uuid, DevicePtr> DeviceMap;
    typedef DeviceMap::iterator DeviceMapIterator;
    typedef DeviceMap::const_iterator DeviceMapConstIterator;
    DeviceMap m_devices;
    VirusOne::Services::PollGroup m_devicePollGroup;

    typedef std::map<VirusOne::Uuid, ServicePtr> ServiceMap;
    typedef ServiceMap::iterator ServiceMapIterator;
    typedef ServiceMap::const_iterator ServiceMapConstIterator;
    ServiceMap m_services;
    VirusOne::Services::PollGroup m_servicePollGroup;

  };

}
