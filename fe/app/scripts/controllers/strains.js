// controllers/strain.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

'use strict';

function StrainsCtrl (Strain) {
  var self = this;
  Strain.get(function (response) {
    console.log('Strains', response);
    self.strains = response.strains;
  });
}

StrainsCtrl.$inject = [
  'Strain'
];

/**
 * @ngdoc function
 * @name virusOneApp.controller:StrainsCtrl
 * @description
 * # StrainsCtrl
 * Controller of the virusOneApp
 */
angular.module('virusOneApp')
  .controller('StrainsCtrl', StrainsCtrl);
