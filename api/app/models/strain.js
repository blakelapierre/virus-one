// models/strain.js
// Copyright (C) Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;
var UserRatingSchema = require('./schema/user-rating');

/*
EFFECTS:
happy, uplifting, euphoric, relaxed

NEGATIVES:
red/dry eyes, dry mouth, harshness/cough, paranoia, heavy chest

MEDICAL:
pain, sleep, appetite

AROMA and FLAVOR:
sweet, diesel, rubber, citrus, floral, fruit, earthy
*/

console.log('schema: Strain');
var StrainSchema = new Schema({
  'name' : { 'type': String, 'required': true, 'unique': true },
  'source': {
    'seedCompany': {
      'name': { 'type': String, 'required': false },
      'href': { 'type': String, 'required': false }
    },
    'breeder': {
      'name': { 'type': String, 'required': false },
      'href': { 'type': String, 'required': false }
    }
  },
  'description': { 'type': String, 'required': true },
  'effects': {
    'availableEffects': [ String ],
    'effects': [ UserRatingSchema ]
  },
  'negatives': {
    'availableEffects': [ String ],
    'ratings': [ UserRatingSchema ]
  },
  'medical': {
    'availableEffects': [ String ],
    'ratings': [ UserRatingSchema ]
  },
  'links': [{
    'name': { 'type': String, 'required': true },
    'href': { 'type': String, 'required': true }
  }]
});

console.log('model: Strain');
mongoose.model('Strain', StrainSchema);
