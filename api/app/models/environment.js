// models/environment.js
// Copyright (C) Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: Environment');

var EnvironmentSchema = new Schema({
  'name': { 'type': String, 'required': true },
  'temperature': { 'type': Number, 'required': false },
  'humidity': { 'type': Number, 'required': false },
  'modules': [{
    'moduleId': { 'type': Schema.ObjectId, 'required': true }
  }]
});

console.log('model: Environment');
mongoose.model('Environment', EnvironmentSchema);
