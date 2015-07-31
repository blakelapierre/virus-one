# virus-one
The Virus One grow automation, monitoring and reporting application. As time 
passes and this application becomes more complete, this README will explain how 
to install, configure and use the application. It's early days. You need to be a 
seasoned MEAN stack developer to get this software correctly running. An 
installer is simply not the current priority.

## Project Directory Structure

Directory           | Component                                               
--------------------|---------------------------------------------------
api                 | The ExpressJS-based Node.js API server
data                | MongoDB database files
fe                  | The VirusOne AngularJS HTML5 Front End
system              | VirusOne C++ Components
system/libvirus     | VirusOne Application Development Library
system/libvirusesp  | VirusOne Extra-Sensory Perception (ESP) Library
system/libvirustest | VirusOne Unit and Performance Testing Framework
system/virustest    | VirusOne Unit and Performance Testing Application

## Getting Started
The VirusOne repository includes links to submodules. To clone into the entire 
VirusOne repository:

    git clone git@github.com:robcolbert/virus-one.git
    git submodule init
    git submodule update
    git pull origin
    git checkout develop

### Modern C++
You will need a C++ compiler to build the VirusOne System Library (VOSL). 
VirusOne uses the C++11 language standard as implemented by the GNU C++ 
-std=gnu++11 compiler switch. The GNU toolchain should be available for whatever 
you're using. If you can't make use of C++11 in 2015, I'm not sorry.

[Learn More](http://blog.smartbear.com/c-plus-plus/the-biggest-changes-in-c11-and-why-you-should-care/)

### IDE
I am using [KDevelop 4.7.1](https://www.kdevelop.org/) to build the C++ 
components; and [Sublime Text 3](http://www.sublimetext.com/3) for the Web 
components. Will eventually migrate everything into KDevelop for convenience. 
Only KDevelop requires the use of "project" files. For now, they are restricted 
to the system directory. These are early days, and this is all likely to change 
with the whole project being migrated into KDevelop 4.

### Grunt
[Grunt](http://gruntjs.com/) is used to manage and build the VirusOne Web 
application.

### Bower
[Bower](http://bower.io/) is used to manage various 3rd-party components in the 
VirusOne Web application.

### MongoDB
[MongoDB](https://www.mongodb.org/) is used for the VirusOne Web API. It is an 
absolute requirement, and its Aggregation Framework is used for data reporting 
services.

### Node.js
[Node.js](https://nodejs.org/) is used to build the VirusOne API server. 
Node.js also powers Grunt and Bower, so it is required to build all VirusOne Web 
components on the command line.

### ExpressJS
[ExpressJS](http://expressjs.com/) is used to implement the VirusOne Web 
application's API server.

### Jasmine and Karma
[Jasmine](http://jasmine.github.io/) and 
[Karma](http://karma-runner.github.io/0.13/index.html) are used to implement and 
run the VirusOne Web component tests.

### AngularJS
[AngularJS](https://angularjs.org/) is used to build the VirusOne Web 
application front end.

### Chart.js
[Chart.js](http://www.chartjs.org/) is used to implement charts and graphs in 
the VirusOne Web application front end.
