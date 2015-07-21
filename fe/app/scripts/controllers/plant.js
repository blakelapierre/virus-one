// controllers/plants.js
// Copyright (C) 2015 Rob Colbert <rob.isConnected@gmail.com>
// License: MIT

'use strict';

/* global: moment */

function PlantsCtrl ($location, Plant) {
  var self = this;

  console.log('Hello from the PlantsCtrl controller');
  this.$location = $location;
  this.PlantService = Plant;

  this.PlantService.get(function (plants) {
    console.log('plants', plants);
    self.plants = plants.plants;
  });
}

PlantsCtrl.prototype.loadPlant = function (plantId) {
  console.log('loading plant view', plantId.toString());
  this.$location.url('/plant/' + plantId.toString());
};

PlantsCtrl.prototype.showNewPlantModal = function ( ) {
  angular.element('#newPlantModal').modal('show');
};

PlantsCtrl.prototype.createPlant = function (/* $event */) {
  console.log('PlantsCtrl.createPlant is stubbed');
};

PlantsCtrl.$inject = [
  '$location',
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
