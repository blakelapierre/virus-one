// models/nutrient.js
// Copyright (C) Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: Nutrient');

var NutrientSchema = new Schema({
  'name': { 'type': String, 'required': true },
  'costPerGallonCents': { 'type': Number, 'required': true }
});

console.log('model: Nutrient');
mongoose.model('Nutrient', NutrientSchema);
