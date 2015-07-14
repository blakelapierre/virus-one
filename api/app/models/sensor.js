// models/sensor.js
// Copyright (C) Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;
var SensorValue = require('./schema/sensor-value.js');

console.log('schema: Sensor');
var SensorSchema = new Schema({
  'type' : { 'type': String, 'enum': ['temp','rh','light','ph','camera'] },
  'readings': [{
    'created': { 'type': Date, required: true, default: Date.now },
    'value': {
      'number': { 'type': Number, 'required': false },
      'string': { 'type': String, 'required': false },
      'boolean': { 'type': Boolean, 'required': false },
      'buffers': [{
        'mimeType': { 'type': String, 'required': true },
        'data': { 'type': Buffer, 'required': true }
      }]
    }
  }],
  'costCents': { 'type': Number, 'required': true }
});

console.log('model: Sensor');
mongoose.model('Sensor', SensorSchema);
