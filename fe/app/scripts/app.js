'use strict';

/**
 * @ngdoc overview
 * @name virusOneApp
 * @description
 * # virusOneApp
 *
 * Main module of the application.
 */
angular
  .module('virusOneApp', [
    'ngAnimate',
    'ngCookies',
    'ngResource',
    'ngRoute',
    'ngSanitize',
    'ngTouch'
  ])
  .config(function ($routeProvider) {
    $routeProvider
      .when('/', {
        templateUrl: 'views/main.html',
        controller: 'MainCtrl',
        controllerAs: 'monitor'
      })
      .when('/environments', {
        templateUrl: 'views/environments.html',
        controller: 'EnvironmentsCtrl',
        controllerAs: 'environments'
      })
      .when('/modules', {
        templateUrl: 'views/modules.html',
        controller: 'ModulesCtrl',
        controllerAs: 'modules'
      })
      .when('/plants', {
        templateUrl: 'views/plants.html',
        controller: 'PlantsCtrl',
        controllerAs: 'plants'
      })
      .when('/plant/:plantId', {
        templateUrl: 'views/plant-view.html',
        controller: 'PlantViewCtrl',
        controllerAs: 'plantView'
      })
      .when('/nutrients', {
        templateUrl: 'views/nutrients.html',
        controller: 'NutrientsCtrl',
        controllerAs: 'nutrients'
      })
      .when('/about', {
        templateUrl: 'views/about.html',
        controller: 'AboutCtrl'
      })
      .when('/strains', {
        templateUrl: 'views/strains.html',
        controller: 'StrainsCtrl',
        controllerAs: 'strains'
      })
      .when('/help', {
        templateUrl: 'views/help.html',
        controller: 'HelpCtrl',
        controllerAs: 'help'
      })
      .otherwise({
        redirectTo: '/'
      });
  });
