// models/user.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var mongoose = require('mongoose');
var Schema = mongoose.Schema;

console.log('schema: User');
var UserSchema = new Schema({
  'firstName': { 'type': String, 'required': true },
  'lastName': { 'type': String, 'required': true },
  'username': { 'type': String, 'required': true },
  'password': { 'type': String, 'required': true },
  'authorization': { 'type': String, 'required': true, 'default': 'gardener'}
});

console.log('model: User');
mongoose.model('User', UserSchema);
