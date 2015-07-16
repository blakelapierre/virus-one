'use strict';

describe('Filter: simpleDate', function () {

  // load the filter's module
  beforeEach(module('virusOneApp'));

  // initialize a new instance of the filter before each test
  var simpleDate;
  beforeEach(inject(function ($filter) {
    simpleDate = $filter('simpleDate');
  }));

  // it('should return the input prefixed with "simpleDate filter:"', function () {
  //   var text = 'angularjs';
  //   expect(simpleDate(text)).toBe('simpleDate filter: ' + text);
  // });

});
