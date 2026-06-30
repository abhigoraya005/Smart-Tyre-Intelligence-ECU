/* ============================================================
   SMART TYRE INTELLIGENCE ECU — charts.js
   ============================================================ */

'use strict';

(function () {
  const MAX_POINTS = 30;

  function makeLabel() {
    const now = new Date();
    return now.toLocaleTimeString('en-US', { hour12: false, hour: '2-digit', minute: '2-digit', second: '2-digit' });
  }

  function commonOptions(color, suggestedMax, suggestedMin = 0) {
    return {
      responsive: true,
      maintainAspectRatio: false,
      animation: { duration: 300, easing: 'linear' },
      plugins: {
        legend: { display: false },
        tooltip: { enabled: false }
      },
      scales: {
        x: {
          grid: { color: 'rgba(255,255,255,0.02)' },
          ticks: { color: '#475569', font: { size: 8, family: 'Share Tech Mono' }, maxTicksLimit: 5 }
        },
        y: {
          suggestedMin, suggestedMax,
          grid: { color: 'rgba(255,255,255,0.02)' },
          ticks: { color: '#475569', font: { size: 8, family: 'Share Tech Mono' }, maxTicksLimit: 4 }
        }
      },
      elements: {
        point: { radius: 0 },
        line: { tension: 0.2, borderWidth: 1.5 }
      }
    };
  }

  function buildGradient(ctx, color) {
    const chartArea = ctx.chart?.chartArea;
    if (!chartArea) return color + '11';
    const g = ctx.chart.ctx.createLinearGradient(0, chartArea.top, 0, chartArea.bottom);
    g.addColorStop(0, color + '33');
    g.addColorStop(1, color + '00');
    return g;
  }

  let tempChart, pressureChart, healthChart, loadChart;

  function initCharts() {
    const tempCtx     = document.getElementById('chart-temperature')?.getContext('2d');
    const pressureCtx = document.getElementById('chart-pressure')?.getContext('2d');
    const healthCtx    = document.getElementById('chart-health')?.getContext('2d');
    const loadCtx       = document.getElementById('chart-load')?.getContext('2d');

    if (tempCtx) {
      tempChart = new Chart(tempCtx, {
        type: 'line',
        data: { labels: [], datasets: [{ data: [], borderColor: '#FF3B30', backgroundColor: (ctx) => buildGradient(ctx, '#FF3B30'), fill: true }] },
        options: commonOptions('#FF3B30', 100, 0),
      });
    }
    if (pressureCtx) {
      pressureChart = new Chart(pressureCtx, {
        type: 'line',
        data: { labels: [], datasets: [{ data: [], borderColor: '#00BFFF', backgroundColor: (ctx) => buildGradient(ctx, '#00BFFF'), fill: true }] },
        options: commonOptions('#00BFFF', 50, 10),
      });
    }
    if (healthCtx) {
      healthChart = new Chart(healthCtx, {
        type: 'line',
        data: { labels: [], datasets: [{ data: [], borderColor: '#00E5FF', backgroundColor: (ctx) => buildGradient(ctx, '#00E5FF'), fill: true }] },
        options: commonOptions('#00E5FF', 100, 0),
      });
    }
    if (loadCtx) {
      loadChart = new Chart(loadCtx, {
        type: 'line',
        data: { labels: [], datasets: [{ data: [], borderColor: '#00FF7F', backgroundColor: (ctx) => buildGradient(ctx, '#00FF7F'), fill: true }] },
        options: commonOptions('#00FF7F', 130, 0),
      });
    }
  }

  function pushPoint(chart, value) {
    if (!chart) return;
    chart.data.labels.push(makeLabel());
    chart.data.datasets[0].data.push(value);
    if (chart.data.labels.length > MAX_POINTS) {
      chart.data.labels.shift();
      chart.data.datasets[0].data.shift();
    }
    chart.update('none');
  }

  function update(state) {
    pushPoint(tempChart,     +state.sensors.temperature.toFixed(1));
    pushPoint(pressureChart, +state.sensors.pressure.toFixed(1));
    pushPoint(healthChart,   +state.healthScore.toFixed(0));
    pushPoint(loadChart,     +state.sensors.load.toFixed(0));
  }

  window.chartSystem = { init: initCharts, update };
})();