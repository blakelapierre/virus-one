// filters/gendericon.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// All Rights Reserved

'use strict';

/**
 * @ngdoc filter
 * @name virusOneApp.filter:genderIcon
 * @function
 * @description
 * # genderIcon
 * Filter in the virusOneApp.
 */
angular.module('virusOneApp')
  .filter('genderIcon', function () {
    return function (input) {
      var genderIconName = 'neuter';
      if (input === undefined) {
        return '';
      }
      switch (input) {
        case 'male':
          genderIconName = 'man';
          break;
        case 'female':
          genderIconName = 'woman';
          break;
        case 'intersex':
          genderIconName = 'intergender';
          break;
        default:
          break;
      }
      return genderIconName.toString() + ' icon';
    };
  });
