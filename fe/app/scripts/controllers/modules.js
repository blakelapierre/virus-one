'use strict';

function ModulesCtrl (GrowModule) {
  var self = this;

  GrowModule.get(function (modules) {
    console.log('modules', modules);
    self.modules = modules.modules;
  });
}

ModulesCtrl.$inject = [
  'GrowModule'
];

/**
 * @ngdoc function
 * @name virusOneApp.controller:ModulesCtrl
 * @description
 * # ModulesCtrl
 * Controller of the virusOneApp
 */
angular.module('virusOneApp')
  .controller('ModulesCtrl', ModulesCtrl);
