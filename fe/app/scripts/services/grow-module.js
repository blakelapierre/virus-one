// services/grow-module.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

'use strict';

function GrowModuleService ($resource) {

  var serviceUrl = 'http://192.168.1.12:3000/grow-module/';
  var defaultParameters = null;

  console.log('creating GrowModule service');

  return $resource(serviceUrl, defaultParameters, {
    'get': { 'method': 'GET', 'withCredentials': true },
    'create': { 'method': 'POST', 'withCredentials': true },
    'delete': { 'method': 'DELETE', 'withCredentials': true }
  });

}

GrowModuleService.$inject = [
  '$resource'
];

/**
 * @ngdoc service
 * @name virusOneApp.growModule
 * @description
 * # growModule
 * Service in the virusOneApp.
 */
angular.module('virusOneApp')
  .service('GrowModule', GrowModuleService);
