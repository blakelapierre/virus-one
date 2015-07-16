'use strict';

/* global Chart */

/*

    <canvas id="myChart" width="400" height="100"></canvas>
    <div class="ui center aligned inverted segment" id="myChartLegend"></div>

*/

function PlantMonitorChartDirective ( ) {
  return {
    template: '<div class="ui container"></div>',
    replace: true,
    restrict: 'E',
    link: function postLink(scope, element/*, attrs*/) {
      var canvas = angular.element('<canvas width="400" height="100"></canvas>');
      canvas.appendTo(element);

      var data = {
        labels: ['10:00am', '11:00am', '12:00pm', '1:00pm', '2:00pm', '3:00pm', '4:00pm'],
        datasets: [{
          label: 'Temperature',
          datasetFill: false,
          fillColor: 'rgba(220,220,32,0.2)',
          strokeColor: 'rgba(220,220,32,1)',
          pointColor: 'rgba(220,220,220,1)',
          pointStrokeColor: '#fff',
          pointHighlightFill: '#fff',
          pointHighlightStroke: 'rgba(220,220,220,1)',
          data: [68, 70, 71, 72, 74, 76, 74]
        },
        {
          label: 'Humidity',
          fillColor: 'gba(32,220,32,0.2)',
          strokeColor: 'gba(32,220,32,1)',
          pointColor: 'gba(151,187,205,1)',
          pointStrokeColor: 'gba(151,187,205,1)',
          pointHighlightFill: 'fff',
          pointHighlightStroke: 'gba(151,187,205,1)',
          data: [46, 48, 50, 54, 53, 52, 55]
        }]
      };

      var options = {
        responsive: true,
        datasetFill: false,
        legendTemplate : '<% for (var i=0; i<datasets.length; i++){%><div style="display: block; color:<%=datasets[i].strokeColor%>; margin-right: 8px;"><%if(datasets[i].label){%><%=datasets[i].label%><%}%></div><%}%>'
      };
      var ctx = canvas.get(0).getContext('2d');
      var myLineChart = new Chart(ctx).Line(data, options);

      var legend = angular.element('<div class="ui inverted center aligned segment"></div>');
      legend.html(myLineChart.generateLegend());
      legend.appendTo(element);
    }
  };
}

/**
 * @ngdoc directive
 * @name virusOneApp.directive:plantMonitorChart
 * @description
 * # plantMonitorChart
 */
angular.module('virusOneApp')
  .directive('plantMonitorChart', PlantMonitorChartDirective);
