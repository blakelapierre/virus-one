'use strict';

describe('Filter: genderIcon', function () {

  // load the filter's module
  beforeEach(module('virusOneApp'));

  // initialize a new instance of the filter before each test
  var genderIcon;
  beforeEach(inject(function ($filter) {
    genderIcon = $filter('genderIcon');
  }));

  // it('should return the input prefixed with "genderIcon filter:"', function () {
  //   var text = 'angularjs';
  //   expect(genderIcon(text)).toBe('genderIcon filter: ' + text);
  // });

});
