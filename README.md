# virus-one
The Virus One grow automation, monitoring and reporting application. As time passes and this application becomes more complete, this README will explain how to install, configure and use the application. It's early days. You need to be a seasoned MEAN stack developer to get this software correctly running. An installer is simply not the current priority.

## AngularJS
AngularJS is the application's front end development framework. Angular is used only for application structure. No off-the-shelf bindings to any front-end framework are used. This keeps Angular as isolated as possible, the application remains as performant as possible and minimal resources are used.

## Semantic UI
Semantic UI is used to deliver an outstanding end user experience that is elegant, simple and intuitive. Careful consideration has been given to the Virus One main application user interface to remove all clutter and keep access to the information you need as the top priority.

Semantic in used in favor of Twitter Bootstrap because the amount of HTML needed to generate the same or better UI in Semantic is simply less and more easily understood. I have yet to feel like I "hacked together" a UI in Semantic. Every Bootstrap UI I've ever built felt like a hack.

## node-webkit
Virus One is hosted on desktop and laptop computers in any HTML5-compliant Web browser or using node-webkit as a standalone, kios-grade application hosting environment.

## Node.js + ExpressJS
An ExpressJS REST API is implemented atop Node.js offering full access to any HTTP client that has awareness of the public API and how to use it.

## MongoDB
MondoDB is used to help Virus One implement a true Internet of Things centered around your Indoor Controlled Environment Agriculture grow operation. All data is stored within MongoDB collections, and the MongoDB Aggregation Framework is used to report on that data for visualization in the front end.