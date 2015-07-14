// controllers/plants.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

'use strict';
/* global moment */
function PlantsCtrl ($scope, Plant) {
  var self = this;

  console.log('Hello from the PlantsCtrl controller');

  Plant.get(function (plants) {
    console.log('plants', plants);
    angular.forEach(plants.plants, function (plant) {
      plant.createdString = moment(plant.created).format('L');
      console.log('plant.createdString', plant, plant.createdString);
    });
    self.plants = plants.plants;
  });
}

PlantsCtrl.$inject = [
  '$scope',
  'Plant'
];

/**
 * @ngdoc function
 * @name virusOneApp.controller:PlantsCtrl
 * @description
 * # PlantsCtrl
 * Controller of the virusOneApp
 */
angular.module('virusOneApp')
  .controller('PlantsCtrl', PlantsCtrl);
