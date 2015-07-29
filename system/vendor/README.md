# 3rd-Party Components
VirusOne makes use of 3rd-party libraries to provide standardized functionality to the various libraries and applications in the system. To populate these components, execute the following commands in a terminal from within the repository:

    git submodule init
    git submodule update

git will then populate the submodules throughout the repo (which are all kept here by convention for the C++ components).

## rapidjson
[RapidJSON]() is used to implement JSON encoding and parsing within VirusOne. The VirusOne TCP protocol is implemented to transport JSON-encoded commands and their responses throughout the system. This allows very easy integration with Node.js and other Web-based technologies to help extend what VirusOne can do throughout the years to come.

## spdlog
Super-fast C++ logging library. It is highly configurable, easily attached to a variety of sinks/databases for centralized reporting and incredibly fast using very little memory.
