'use strict';

function EnvironmentsCtrl ($scope, Environment) {
  var self = this;
  Environment.get(function (environment) {
    console.log('environment', environment);
    self.environments = environment.environments;
  });
}

EnvironmentsCtrl.$inject = [
  '$scope',
  'Environment'
];

/**
 * @ngdoc function
 * @name virusOneApp.controller:EnvironmentsCtrl
 * @description
 * # EnvironmentsCtrl
 * Controller of the virusOneApp
 */
angular.module('virusOneApp')
  .controller('EnvironmentsCtrl', EnvironmentsCtrl);
