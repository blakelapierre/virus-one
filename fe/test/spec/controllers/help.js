'use strict';

describe('Controller: HelpCtrl', function () {

  // load the controller's module
  beforeEach(module('virusOneApp'));

  var HelpCtrl;

  // Initialize the controller and a mock scope
  beforeEach(inject(function ($controller/*, $rootScope*/) {
    HelpCtrl = $controller('HelpCtrl', {
      // place here mocked dependencies
    });
  }));

  it('should attach a list of awesomeThings to the scope', function () {
    expect(HelpCtrl.awesomeThings.length).toBe(3);
  });
});
