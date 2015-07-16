'use strict';

describe('Directive: plantMonitorChart', function () {

  // load the directive's module
  beforeEach(module('virusOneApp'));

  var element,
    scope;

  beforeEach(inject(function ($rootScope) {
    scope = $rootScope.$new();
  }));

  // it('should make hidden element visible', inject(function ($compile) {
  //   element = angular.element('<plant-monitor-chart></plant-monitor-chart>');
  //   element = $compile(element)(scope);
  //   expect(element.text()).toBe('this is the plantMonitorChart directive');
  // }));
});
