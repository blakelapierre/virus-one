// models/watering.js
// Copyright (C) Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: Watering');
var WateringSchema = new Schema({
  'gallons': { 'type': Number, 'required': true },
  'pH': { 'type': Number, 'required': true },
  'nutrients': [{
    'nutrientId': { 'type': Schema.ObjectId, 'required': true },
    'amountTsp': { 'type': Number, 'required': true },
    'costCents': { 'type': Number, 'required': true }
  }],
  'costCents': { 'type': Number, 'required': true }
});

console.log('model: Watering');
mongoose.model('Watering', WateringSchema);
