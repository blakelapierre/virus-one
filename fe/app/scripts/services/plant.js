// services/plant.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

'use strict';

function PlantService ($resource) {

  var serviceUrl = 'http://192.168.1.12:3000/plant/:plantId';
  var defaultParameters = null;

  console.log('creating Plant service');

  return $resource(serviceUrl, defaultParameters, {
    'get': { 'method': 'GET', 'withCredentials': true, 'cache': false },
    'create': { 'method': 'POST', 'withCredentials': true },
    'delete': { 'method': 'DELETE', 'withCredentials': true }
  });

}

PlantService.$inject = [
  '$resource'
];

/**
 * @ngdoc service
 * @name virusOneApp.plant
 * @description
 * # plant
 * Service in the virusOneApp.
 */
angular.module('virusOneApp')
  .service('Plant', PlantService);
