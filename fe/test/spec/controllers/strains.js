'use strict';

describe('Controller: StrainsCtrl', function () {

  // load the controller's module
  beforeEach(module('virusOneApp'));

  var StrainsCtrl;

  // Initialize the controller and a mock scope
  beforeEach(inject(function ($controller/*, $rootScope*/) {
    StrainsCtrl = $controller('StrainsCtrl', {
      // place here mocked dependencies
    });
  }));

  // it('should attach a list of awesomeThings to the scope', function () {
  //   expect(StrainsCtrl.awesomeThings.length).toBe(3);
  // });
});
