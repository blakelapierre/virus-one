// controllers/plant-view.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

'use strict';

/* global: moment */

function PlantViewCtrl ($scope, $route, Plant) {
  var self = this;
  var plantId = $route.current.params.plantId;

  console.log('Hello from the PlantViewCtrl controller');
  console.log('plantId', plantId);

  Plant.get({ 'plantId': plantId }, function (plant) {
    self.plant = plant.plant;
    console.log('plant', self.plant);
  });
}

PlantViewCtrl.$inject = [
  '$scope',
  '$route',
  'Plant'
];

/**
 * @ngdoc function
 * @name virusOneApp.controller:PlantViewCtrl
 * @description
 * # PlantViewCtrl
 * Controller of the virusOneApp
 */
angular.module('virusOneApp')
  .controller('PlantViewCtrl', PlantViewCtrl);
