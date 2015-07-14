// simulators/temperature-sensor.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var util = require('util');
var uuid = require('node-uuid');
var events = require('events');

/**
 * 
 */
function TemperatureSensorSimulator (options) {
  events.EventEmitter.call(this); // inheritance support

  this.sensorId = options.sensorId || uuid.v4();
  this.state = 'calibrating';

  this.calibrationReadsRemaining = options.calibrationReads | 3;
  this.minTemp = options.minTemp || 70.0;
  this.maxTemp = options.maxTemp || 82.0;
  this.currentValue = null;
}

//
// Inheritance Support
//
util.inherits(TemperatureSensorSimulator, events.EventEmitter);

/**
 * method: getCurrentValue
 */
TemperatureSensorSimulator.prototype.getCurrentValue = function ( ) {
  return this.currentValue;
};

/**
 * method: updateSensorValue
 */
TemperatureSensorSimulator.prototype.updateSensorValue = function ( ) {
  // assign a random new value after a number of simulated calibration reads.  
  this.currentValue = ((Math.random() * (this.maxTemp - this.minTemp)) + this.minTemp);
};

/**
 * method: update
 */
TemperatureSensorSimulator.prototype.update = function ( ) {
  switch (this.state) {
    case 'calibrating':
      if (--this.calibrationReadsRemaining <= 0) {
        this.calibrationReadsRemaining = 0;
        this.state = 'active';
        this.updateSensorValue();
      }
      break;
    
    case 'active':
      this.updateSensorValue();
      break;

    default:
      console.error('invalid temp sensor sim state:', this.state);
      break;
  }

  this.emit('update', { 'state': this.state, 'value': this.currentValue });
};

module.exports = TemperatureSensorSimulator;
