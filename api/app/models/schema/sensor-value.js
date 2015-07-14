// models/schema/sensor-value.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: SensorValue');

var DataBuffer = require('./data-buffer.js');

var SensorValue = new Schema();

module.exports = SensorValue;
