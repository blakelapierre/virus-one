'use strict';

function EnvironmentService ($resource) {
  var serviceUrl = 'http://192.168.1.12:3000/environment/';
  var defaultParameters = null;

  console.log('creating Environment service');

  return $resource(serviceUrl, defaultParameters, {
    'get': { 'method': 'GET', 'withCredentials': true },
    'create': { 'method': 'POST', 'withCredentials': true },
    'delete': { 'method': 'DELETE', 'withCredentials': true }
  });

}

EnvironmentService.$inject = [
  '$resource'
];

/**
 * @ngdoc service
 * @name virusOneApp.environment
 * @description
 * # environment
 * Service in the virusOneApp.
 */
angular.module('virusOneApp')
  .service('Environment', EnvironmentService);
