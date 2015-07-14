// controllers/grow-module.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var express = require('express');
var numeral = require('numeral');
var router = express.Router();
var mongoose = require('mongoose');
var GrowModule = mongoose.model('GrowModule');

module.exports = function (app) {
  app.use('/grow-module', router);
};

function randomTemperature ( ) {
  return numeral((Math.random() * 8.0) + 70.0).format('0');
}

function randomHumidity ( ) {
  return numeral((Math.random() * 4.0) + 48.0).format('0');
}

function randomLumens ( ) {
  return numeral(Math.round((Math.random() * 2000) + 120000)).format('0,0');
}

router.get('/', function (req, res, next) {
  var mergedModules = [ ];
  GrowModule.find(function (err, modules) {
    if (err) return next(err);
    modules.forEach(function (module) {
      module = module.toObject();
      module.monitors = {
        'temperature': randomTemperature(),
        'humidity': randomHumidity(),
        'lumens': randomLumens()
      };
      mergedModules.push(module);
    });
    res.status(200).json({ 'modules': mergedModules });
  });
});

router.post('/', function (req, res, next) {
  GrowModule.create(req.body, function (err, module) {
    if (err) return next(err);
    res.status(200).json({ 'module': module });
  });
});
