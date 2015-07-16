// filters/simple-date.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// All Rights Reserved

'use strict';

/* global moment */

/**
 * @ngdoc filter
 * @name virusOneApp.filter:simpleDate
 * @function
 * @description
 * # simpleDate
 * Filter in the virusOneApp.
 */
angular.module('virusOneApp')
  .filter('simpleDate', function () {
    return function (input) {
      return moment(input).format('L');
    };
  });
