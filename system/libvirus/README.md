# libvirus
libvirus is an MIT-licensed open source C++ library for use with the VirusOne Grow Automation and Monitoring system. It provides services to the virusd system daemon and enables 3rd-party application developers to easily build for and extend the VirusOne platform with new features, services and functionality.

libvirus was created by [Rob Colbert](https://www.linkedin.com/in/robcolbert) as part of a *major* act of civil disobedience agaisnt the unjust laws of cannabis prohibition. The creation of this software is part of what I did while mastering the cultivation of cannabis living in Pittsburgh, Pennsylvania...where cannabis in all forms is whack-a-doo illegal. Creating this software in my lab is probably a state felony.

Fuck Matt Baker (R-Tioga). Fuck him completely with a bag of borrowed dicks. He singlehandedly prevented Pennsylvania from having safe access to effective medication and prolonged the suffering of many. He is a despicable purchased Big Pharma puppet who accepted over $40,000 in campaign contributions from companies such as Rite-Aid, Astra-Zeneca and several others. The man is an *asshole* who would rather watch children suffer with seizures and cancer than allow them access to the relief and healing they need.

## Soundtrack
[Seek N Destroy x ICHI - Maidan](https://soundcloud.com/seek-n-destroy/seek-n-destroy-x-ichi-maidan-original-mix)
[Extra Terra - Annunaki](https://soundcloud.com/trapmusic/extra-terra-annunaki-edm-com-exclusive)

## Requirements

Linux command line knowledge. Someone else can fork this project and go care about usability. libvirus is engineered to build, link and provide service on GNU Linux.

The only development and build environment I think might almost maybe work for you is Red Hat's [Fedora Linux Desktop](https://getfedora.org/) hosting the GNU development tools and whatever you prefer as an editor/IDE. It all depends on what you've done to the host. I use an out-of-box-stock Fedora 22 host + all dnf updates as they are released. It could be faster for you to run an off-the-shelf Fedora 22 ISO in a VirtualBox VM to cut your builds.

libvirus makes use of the [CMake](http://www.cmake.org/) build system to manage and maintain the project's build system. [GNU Make](http://www.gnu.org/software/make/) is ultimately used to build the library and its associated unit test executable.

### C++11
libvirus makes use of features of the C++11 (2011) language standard. Most specifically, the -std=gnu++11 switch is used to enable C++11 support in g++.

### SQLite 3

SQLite 3 (sqlite3) is used to implement a persistent and resilient data cache in the VirusOne monitoring process. Data read from sensors is written to a local persistent store. As the VirusOne monitoring process calls out to each monitor to read its data, the monitor will attempt to service the request using a query configured to match the ingress request for information.

### Package Dependencies
sudo dnf install sqlite3 libsq3 libuuid libuuid-devel

## Library Services

### Sensor Data Input
libvirus implements the C++ code required to read values from external sensors. This includes temperature, humidity, pH, PPM and luminosity sensors.

### External Device Control
libvirus implements the C++ code required to control external devices such as light switch relays and dimmers, fan speed controllers, pumps and servos.

### Data Storage and Retrieval
A common data storage interface is provided as a front-end to libsqlite3 for persistent data storage and retrieval with queries and quotas. As data is being read from sensors, it is locally persisted by virusd using an sqlite3 database. This provides resiliency to the data in case of system failures, allowing capture of as much data as possible in all cases.

Data is flushed as it is read by the main monitor application.

### JSON Formatting and Parsing
libvirus uses [RapidJSON](https://github.com/miloyip/rapidjson) for JSON parsing and processing behind its own interface.

### Virus Monitor Network Protocol (VMNP)
VirusOne uses its own binary protocol over TCP to communicate with the monitors. Full HTTP REST service is not provided by the monitors for efficiency. They are tiny computers with very limited resources dedicated to the process of high-speed/low-latency data input and output.

The Virus Monitor Network Protocol (VMNP) defines the standard for exchanging commands and data with virusd. Classes are offered to build, parse and process network data between virusd and the Node.js application server.

Data is communicated using a very simple TCP protocol that accepts a request and returns an expected response.

### TCP/IP network communications
Basic TCP/IP socket communications library allowing easy communication with the VirusOne Node.js application server for monitoring and control.

### Logging
libvirus and Virus One use [spdlog](https://github.com/gabime/spdlog) for robust application logging to files, the console and other data stores.

## Thank You's
Just in case anyone ever cares about this library, know that certain people's software and actions helped to make it possible over the years.

### Cubieboard
Without the Cubieboard and technolgies similar to it such as Raspberry Pi, etc., the VirusOne Grow Monitoring and Reporting System would not be quite as possible or as feasible for as many people to access and use. Affordable building-block PCs like this are our future. Please, people - keep making these!

### Sublime Text 3
Over the past 30+ years, I've preferred tools like Visual SlickEdit, gedit and vi. I've used Visual Studio where required and hated it. I've used Eclipse (once) where required and seriously fucking hated it. I used to use Code Warrior and go all the way back to Borland Turbo C and Pascal. KDevelop is another.

Of them, Sublime Text 3 is truly my favorite. Being able to edit anything with any tools on any platform with simple configuration is tits. Period. I get exactly the same app with the same shortcut keys always looking and behaving the same while launching faster than my terminal.

Thanks, people. Your software genuinely helps me get shit done every day.

### GNOME terminal
It's resizeable. There. I pretty much win. It also supports a transparent background. And, that just looks awesome along with the custom colors I can set for everything...but don't and never have. The terminal just *always* works and has literally never crashed. Not once. 15+ years of service. Zero fuckups. That's my kinda shit.

If you've ever done software development in the Windows terminal, you know why I'm thanking these people. We spend *time* staring at this shit. *TIME*. GNOME Terminal is just a fucking gangster when it comes to productivity features for me.

### Electronic Dance Music
If it wasn't for [this playlist](https://soundcloud.com/vctech/sets/favorites-2015), writing this software would have been intolerably quiet as I did most of this work at night with headphones on while others in the house peacefully slept. I rocked the fuck out all over this.
