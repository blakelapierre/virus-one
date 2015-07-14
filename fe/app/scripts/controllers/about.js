'use strict';

function AboutCtrl ($scope, $location, $anchorScroll) {
  $scope.goToTop = function ( ) {
    console.log('$anchorScroll', $anchorScroll);
    $location.hash('top');
    $anchorScroll();
  };
}

AboutCtrl.$inject = [
  '$scope',
  '$location',
  '$anchorScroll'
];

/**
 * @ngdoc function
 * @name virusOneApp.controller:AboutCtrl
 * @description
 * # AboutCtrl
 * Controller of the virusOneApp
 */
angular.module('virusOneApp')
  .controller('AboutCtrl', AboutCtrl);
