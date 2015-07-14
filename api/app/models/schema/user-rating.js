// user-rating.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: UserRating');

module.exports = exports = new Schema({
  'effectName': { 'type': String, 'required': true },
  'experiences': [{
    'creator': { 'type': Schema.ObjectId, 'ref': 'User' },
    'created': { 'type': Date, 'default': Date.now },
    'magnitude': { 'type': Number, 'required': true },
    'notes': { 'type': String, 'required': false }
  }]
});
