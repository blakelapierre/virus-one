'use strict';

/**
 * @ngdoc filter
 * @name virusOneApp.filter:zeroNone
 * @function
 * @description
 * # zeroNone
 * Filter in the virusOneApp.
 */
angular.module('virusOneApp')
  .filter('zeroNone', function () {
    return function (input) {
      return input === 0 ? 'None' : input;
    };
  });
