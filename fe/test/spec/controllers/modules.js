'use strict';

describe('Controller: ModulesCtrl', function () {

  // load the controller's module
  beforeEach(module('virusOneApp'));

  var ModulesCtrl;

  // Initialize the controller and a mock scope
  beforeEach(inject(function ($controller/*, $rootScope*/) {
    ModulesCtrl = $controller('ModulesCtrl', {
      // place here mocked dependencies
    });
  }));

  // it('should attach a list of awesomeThings to the scope', function () {
  //   expect(ModulesCtrl.awesomeThings.length).toBe(3);
  // });
});
