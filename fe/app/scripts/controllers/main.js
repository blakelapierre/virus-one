// controllers/main.js
// Copyright (C) 2015 Rob Colbert
// License: MIT

'use strict';

function MainCtrl ($scope, GrowModule) {
  var self = this;

  console.log('GrowModule', GrowModule);
  GrowModule.get(function (modules) {
    console.log('modules', modules);
    self.modules = modules.modules;
  });
}

MainCtrl.$inject = [
  '$scope',
  'GrowModule'
];

/**
 * @ngdoc function
 * @name virusOneApp.controller:MainCtrl
 * @description
 * # MainCtrl
 * Controller of the virusOneApp
 */
angular.module('virusOneApp')
  .controller('MainCtrl', MainCtrl);
