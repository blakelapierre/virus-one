# libvirusesp

The VirusOne Extra Sensory Perception (ESP) library is what enables the VirusOne system to communicate with various external devices, controls, switches and other data sources best supported by a plugin model. A series of base classes are provided upon which support can be built for a variety of external devices and services.

VirusOne ESP depends on [RapidJSON](https://github.com/miloyip/rapidjson) for is Document and Value types. This allows VirusOne to pass JSON objects directly to VirusOne objects for them to inspect and self-configure as indicated. The entire "protocol" spoken between all VirusOne applications and libraries is simply [JavaScript Object Notation (JSON)](http://json.org/).

VirusOne ESP is organized into a logical series of directories that correspond to C++ namespaces. The files tend to correspond to classes, but this is not always the case.

## Devices

A Device is an object that represents an external data source such as a sensor, control, camera or microphone.

A Service is an object that implements a business logic service such as a device monitor that watches a device's values and reports on their conditions.