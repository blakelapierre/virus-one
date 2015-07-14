// controllers/environment.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var express = require('express');
var numeral = require('numeral');
var router = express.Router();
var mongoose = require('mongoose');
var Environment = mongoose.model('Environment');

module.exports = function (app) {
  app.use('/environment', router);
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
  Environment.find(function (err, environments) {
    if (err) return next(err);
    res.status(200).json({ 'environments': environments });
  });
});

router.get('/:environmentId', function (req, res, next) {
  Environment.findById(req.params.environmentId, function (err, environment) {
    if (err) return next(err);
    res.status(200).json({ 'environment': environment });
  });
});

router.post('/', function (req, res, next) {
  Environment.create(req.body, function (err, environment) {
    if (err) return next(err);
    res.status(200).json({ 'environment': environment });
  });
});
