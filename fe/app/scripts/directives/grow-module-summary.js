'use strict';

function GrowModuleSummaryDirective () {
  return {
    template: '<div></div>',
    restrict: 'E',
    link: function postLink(scope, element/*, attrs*/) {
      element.text('this is the growModuleSummary directive');
    }
  };
}

/**
 * @ngdoc directive
 * @name virusOneApp.directive:growModuleSummary
 * @description
 * # growModuleSummary
 */
angular.module('virusOneApp')
  .directive('growModuleSummary', GrowModuleSummaryDirective);
