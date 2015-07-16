'use strict';

function ModulesCtrl (GrowModule) {
  var self = this;

  GrowModule.get(function (modules) {
    console.log('modules', modules);
    modules.modules.forEach(function (module) {
      module.plantCount = Math.floor(Math.random() * 4);
    });
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
