// home.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

var express = require('express');
var router = express.Router();
var mongoose = require('mongoose');
var GrowModule = mongoose.model('GrowModule');

module.exports = function (app) {
  app.use('/', router);
};

router.get('/', function (req, res, next) {
  GrowModule.find(function (err, modules) {
    if (err) return next(err);
    res.render('index', {
      'title': 'VirusOne',
      'modules': modules
    });
  });
});
