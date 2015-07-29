# VirusOne System Components
VirusOne includes several components that are built in C++. I did not take the approach of building compiled Node.js extensions because I don't want the overhead of Node.js above these components as this code will be running on resource-limited devices such as the [Cubieboard](http://cubieboard.org/).

Node.js is used only to run the VirusOne API as a centralized resource acting as an application gateway and router between the VirusOne Web application and the VirusOne Control Modules. It calls out to control modules and aggregates their data for centralized reporting. It will also call out to the modules to issue commands and configure them such as making temporary changes to the feeding program.

The VirusOne TCP protocol is used for communications between Node.js and the VirusOne system components. Command pattern JSON is exchanged over a raw TCP connection to issue commands and read their responses.

## libvirus
VirusOne Core (libvirus) is the base platform abstraction library upon which all VirusOne functionality has been built. It provides abstractions for sockets, port numbers, pollable objects, UUID values, host configurations, system-level services (timestamp, clock, etc.) and the VirusOne application exception base class.

## libvirusesp
VirusOne ESP (Extra-Sensory Perception) implements the business logic divided into two primary groups: Devices and Services. Devices are things like sensors and controls. Services aggregate devices and add controller logic to accept commands from the VirusOne Web application and translate those commands into actual device commands. Command can be requests to set a configuration or to read a device's current status/value.

This component is what allows VirusOne to make things happen in the real world. If you are here to analyze what it would take to integrate your device(s) with VirusOne, this is where you want to begin.

## libvirustest
VirusOne Test Framework is a multi-threaded unit and performance testing framework build specifically for exercising the VirusOne codebase. I only want to have to change my tests when something like the C++ language changes and not when some retarded fucking hipster decides to alter my entire reality without provocation. No, hipster. You aren't allowed to screw my productivity just because you think some wonk new syntax is what everyone should be using.

## virusone-test
VirusOne is a test-driven project all the way down to its C++ core on a framework I built myself because I hate hipsters *and* bullshit...which often go hand-in-hand. I really do. So, the VirusOne TEST application and framework was created to put literally every line, overload, feature, class, method and value in the entirety of VirusOne through all of its positive and negative tests even if I didn't write the component (spdlog, rapidjson, etc.).

This is a large, multi-threaded test framework designed to rip through a code base as fast as your processor can call functions recording every result of everything tested...in a database...for historic analysis, transparency and accountability.

Tests are organized as follows:

    System (singleton of sorts)
      Environment (as many as needed)
        Suite
          Controller
              Experiment
              ...
          Controller
              Experiment
                Experiment (child of above)
                Experiment
              ...
        Suite
          Controller
              Experiment
              ...
        Suite
          Controller
              Experiment
              ...
      Environment (as many as needed)
        Suite
            Controller
              Experiment
              Experiment

The System has a pool of worker threads that will accept Controllers from Suites as capacity to run them becomes available. Suites then drain their Controllers into the selected worker thread where their Experiment(s) are executed serially by the thread. Thus, within one Controller, serial execution of Experiments is guaranteed. Controllers, however, are not. This is why Experiments can have children and dependencies, but no other component in the framework will. They are not guaranteed to be executed serially and are actually services on a first-come/first-served basis. Suites that run faster can be in & out before the first Suite ever finishes if it takes an incredible amount of time to run.

## vendor
All 3rd-party components (spdlog, rapidjson, etc.) are linked as submodules in the vendor directory. To populate the vendor directory, execute the following commands within the repository after you check it out:

    git submodule init
    git submodule update

All submodules will be pulled into the project tree and the VirusOne application(s) will build.

