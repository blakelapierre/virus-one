// controllers/plant.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var express = require('express');
var numeral = require('numeral');
var router = express.Router();
var mongoose = require('mongoose');
var Plant = mongoose.model('Plant');

module.exports = function (app) {
  app.use('/plant', router);
};

router.get('/', function (req, res, next) {
  Plant.find(function (err, plants) {
    if (err) return next(err);
    res.status(200).json({ 'plants': plants });
  });
});

router.get('/:plantId', function (req, res, next) {
  console.log('req.params', req.params);
  Plant.findById(req.params.plantId, function (err, plant) {
    if (err) return next(err);
    res.status(200).json({ 'plant': plant });
  });
});

router.post('/', function (req, res, next) {
  Plant.create(req.body, function (err, plant) {
    if (err) return next(err);
    res.status(200).json({ 'plant': plant });
  });
});
