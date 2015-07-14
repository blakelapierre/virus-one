'use strict';

describe('Controller: PlantsCtrl', function () {

  // load the controller's module
  beforeEach(module('virusOneApp'));

  var PlantsCtrl;

  // Initialize the controller and a mock scope
  beforeEach(inject(function ($controller/*, $rootScope*/) {
    PlantsCtrl = $controller('PlantsCtrl', {
      // place here mocked dependencies
    });
  }));

  // it('should attach a list of awesomeThings to the scope', function () {
  //   expect(PlantsCtrl.awesomeThings.length).toBe(3);
  // });
});
