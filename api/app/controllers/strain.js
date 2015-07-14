// controllers/strain.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var express = require('express');
var router = express.Router();
var mongoose = require('mongoose');
var Strain = mongoose.model('Strain');

console.log('controller: /strain');

module.exports = function (app) {
  app.use('/strain', router);
};

router.get('/', function (req, res, next) {
  Strain.find(function (err, strains) {
    if (err) return next(err);
    res.status(200).json({ 'strains': strains });
  });
});

router.get('/:strainId', function (req, res, next) {
  Strain.findById(req.params.strainId, function (err, strain) {
    if (err) return next(err);
    res.status(200).json({ 'strain': strain });
  });
});

router.post('/', function (req, res, next) {
  Strain.create(req.body, function (err, strain) {
    if (err) return next(err);
    res.status(200).json({ 'strain': strain });
  });
});
