// models/plant.js
// Copyright (C) Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: Plant');

var PlantSchema = new Schema({
  'strain': { 'type': String, 'required': true },
  'sex': { 'type': String, 'enum': ['unknown', 'male', 'female'], 'required': false },
  'created': { 'type': Date, 'required': true, 'default': Date.now },
  'potted': { 'type': Date },
  'triggered': { 'type': Date },
  'harvested': { 'type': Date },
  'jarred': { 'type': Date },
  'aborted': { 'type': Date },
  /*
   * items such as state-issued ID and other required metadata will likely
   * exist in a related collection and not here. This allows the software to be
   * adapted to various local laws, restrictions and regulations without
   * polluting the core plant monitor design.
   */
  'monitors': [{
    'type': { 'type': String, 'required': true },
    'numericValue': { 'type': Number, 'required': false },
    'textValue': { 'type': String, 'required': false }
  }],
  'events': [{
    'created': { 'type': Date, 'default': Date.now, 'required': true },
    'creator': { 'type': Schema.ObjectId, 'required': true },
    'type': {
      'type': String,
      'required': true,
      'enum': [
        'repot',
        'transplant',
        'prune',
        'train',
        'top'
      ]
    },
    'note': { 'type': String, 'required': false }
  }],
  'feedings': [{
    'created': { 'type': Date, 'default': Date.now, 'required': true },
    'water': { 'type': Number, 'required': true },
  }]
});

console.log('model: Plant');
mongoose.model('Plant', PlantSchema);
