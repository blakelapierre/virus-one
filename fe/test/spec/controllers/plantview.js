'use strict';

describe('Controller: PlantviewCtrl', function () {

  // load the controller's module
  beforeEach(module('virusOneApp'));

  var PlantviewCtrl;

  // Initialize the controller and a mock scope
  beforeEach(inject(function ($controller/*, $rootScope*/) {
    PlantviewCtrl = $controller('PlantviewCtrl', {
      // place here mocked dependencies
    });
  }));

  // it('should attach a list of awesomeThings to the scope', function () {
  //   expect(PlantviewCtrl.awesomeThings.length).toBe(3);
  // });
});
