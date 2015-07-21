'use strict';

describe('Directive: growModuleSummary', function () {

  // load the directive's module
  beforeEach(module('virusOneApp'));

//  var element;
  var scope;

  beforeEach(inject(function ($rootScope) {
    scope = $rootScope.$new();
  }));

  // it('should make hidden element visible', inject(function ($compile) {
  //   element = angular.element('<grow-module-summary></grow-module-summary>');
  //   element = $compile(element)(scope);
  //   expect(element.text()).toBe('this is the growModuleSummary directive');
  // }));
});
