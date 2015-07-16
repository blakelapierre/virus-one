'use strict';

describe('Service: Strain', function () {

  // load the service's module
  beforeEach(module('virusOneApp'));

  // instantiate service
  var Strain;
  beforeEach(inject(function (_Strain_) {
    Strain = _Strain_;
  }));

  it('should do something', function () {
    expect(!!Strain).toBe(true);
  });

});
