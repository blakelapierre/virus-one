// models/user.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: User');
var UserSchema = new Schema({
  'username': { 'type': String, 'required': true },
  'password': { 'type': String, 'required': true },
  'authorization': {
    'type': String,
    'required': true,
    'enum': [
      'user',
      'moderator',
      'administrator'
    ],
    'default': 'user'
  },
  'demographics': {
    'firstName': { 'type': String, 'required': true },
    'lastName': { 'type': String, 'required': true },
    'sex': {
      'type': String,
      'required': true,
      'enum': [
        'male', 'female'
      ]
    },
    'association': {
      'type': String,
      'required': true,
      'enum': [
        'recreational',
        'patient',
        'care provider',
        'medical professional',
        'researcher',
        'grower'
      ]
    }
  }
});

console.log('model: User');
mongoose.model('User', UserSchema);
