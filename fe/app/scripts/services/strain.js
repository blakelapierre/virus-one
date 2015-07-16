// services/strain.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

'use strict';

function StrainService ($resource) {

  var serviceUrl = 'http://192.168.1.12:3000/strain/:strainId';
  var defaultParameters = null;

  console.log('creating Strain service');

  return $resource(serviceUrl, defaultParameters, {
    'get': { 'method': 'GET', 'withCredentials': true, 'cache': false },
    'create': { 'method': 'POST', 'withCredentials': true },
    'delete': { 'method': 'DELETE', 'withCredentials': true }
  });

}

StrainService.$inject = [
  '$resource'
];

/**
 * @ngdoc service
 * @name virusOneApp.strain
 * @description
 * # strain
 * Service in the virusOneApp.
 */
angular.module('virusOneApp')
  .service('Strain', StrainService);
