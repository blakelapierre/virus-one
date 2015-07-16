'use strict';

/* global $ */

function HeaderCtrl ($scope, $location) {

  var closedIcon = 'right chevron icon'; //'ellipsis vertical icon'
  var openIcon = 'left chevron icon';

  $scope.sidebarIcon = closedIcon;

  $scope.$on('$locationChangeSuccess', function ( ) {
    var path = $location.path();
    $scope.monitorClass = (path === '/') ? 'active' : '';
    $scope.environmentsClass = (path === '/environments') ? 'active' : '';
    $scope.modulesClass = (path === '/modules') ? 'active' : '';
    $scope.plantsClass = (path === '/plants') ? 'active' : '';
    $scope.strainsClass = (path === '/strains') ? 'active' : '';
    $scope.nutrientsClass = (path === '/nutrients') ? 'active' : '';
  });

  var menuClosedLeftX = $('.left.menu').css('left');
  $scope.onSidebarToggle = function ( ) {
    var curMenuLeftX = $('.left.menu').css('left');
    console.log('curMenuLeftX', curMenuLeftX);
    if (curMenuLeftX !== '0px') {
      $('.left.menu').css('left', 0);
      $scope.sidebarIcon = openIcon;
    } else {
      $('.left.menu').css('left', menuClosedLeftX);
      $scope.sidebarIcon = closedIcon;
    }
  };

  $scope.closeSidebar = function ( ) {
    $('.left.menu').css('left', menuClosedLeftX);
    $scope.sidebarIcon = closedIcon;
  };
}

HeaderCtrl.$inject = [
  '$scope',
  '$location'
];

/**
 * @ngdoc function
 * @name virusOneApp.controller:HeaderCtrl
 * @description
 * # HeaderCtrl
 * Controller of the virusOneApp
 */
angular.module('virusOneApp')
  .controller('HeaderCtrl', HeaderCtrl);
