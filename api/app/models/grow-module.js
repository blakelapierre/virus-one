// models/grow-module.js
// Copyright (C) Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: GrowModule');

var GrowModuleSchema = new Schema({
  'name': { 'type': String, 'required': true },
  'temperature': { 'type': Number, 'required': false },
  'humidity': { 'type': Number, 'required': false },
  'plants': [{
    'plantId': { 'type': Schema.ObjectId, 'required': true },
    'slot': { 'type': Number, 'required': true }
  }]
});

console.log('model: GrowModule');
mongoose.model('GrowModule', GrowModuleSchema);
