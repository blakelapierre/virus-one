'use strict';

describe('Filter: zeroNone', function () {

  // load the filter's module
  beforeEach(module('virusOneApp'));

  // initialize a new instance of the filter before each test
  var zeroNone;
  beforeEach(inject(function ($filter) {
    zeroNone = $filter('zeroNone');
  }));

  // it('should return the input prefixed with "zeroNone filter:"', function () {
  //   var text = 'angularjs';
  //   expect(zeroNone(text)).toBe('zeroNone filter: ' + text);
  // });

});
