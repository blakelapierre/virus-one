'use strict';

describe('Controller: NutrientsCtrl', function () {

  // load the controller's module
  beforeEach(module('virusOneApp'));

  var NutrientsCtrl;

  // Initialize the controller and a mock scope
  beforeEach(inject(function ($controller /*, $rootScope */) {
    NutrientsCtrl = $controller('NutrientsCtrl', {
      // place here mocked dependencies
    });
  }));

  // it('should attach a list of awesomeThings to the scope', function () {
  //   expect(NutrientsCtrl.awesomeThings.length).toBe(3);
  // });
});
