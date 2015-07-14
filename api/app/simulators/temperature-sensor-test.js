var bunyan = require('bunyan');
var log = bunyan.createLogger({'name': 'temperature-sensor-simulator'});

var util = require('util');
var TemperatureSensorSimulator = require('./temperature-sensor.js');

var test = new TemperatureSensorSimulator({ minTemp: 70.0, maxTemp: 90.0 });
log.trace('test object', test);

test.on('update', function (currentTemp) {
  log.info('onUpdate', currentTemp);
});

var updateIntervalId = setInterval(test.update.bind(test), 250);
setTimeout(function ( ) {
  clearInterval(updateIntervalId);
  updateIntervalId = null;
  log.info('test complete');
}, 5000);
