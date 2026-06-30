/* ============================================================
   SMART TYRE INTELLIGENCE ECU — dashboard.js
   ============================================================ */

'use strict';

const SENSOR_CONFIG = {
  temperature: { min: 20,  max: 120, normal: [20, 70],  unit: '°C',  label: 'TEMPERATURE' },
  pressure:    { min: 15,  max: 55,  normal: [28, 35],  unit: 'PSI', label: 'PRESSURE'    },
  vibration:   { min: 0,   max: 8,   normal: [0, 2.5],  unit: 'g',   label: 'VIBRATION'   },
  load:        { min: 0,   max: 130, normal: [0, 70],   unit: '%',   label: 'LOAD'        },
};

const FAULT_THRESHOLDS = {
  overTemp:     { key: 'temperature', op: '>',  val: 70 },
  lowPressure:  { key: 'pressure',    op: '<',  val: 28 },
  highPressure: { key: 'pressure',    op: '>',  val: 35 },
  highVib:      { key: 'vibration',   op: '>',  val: 2.5 },
  overLoad:     { key: 'load',        op: '>',  val: 70 },
};

const state = {
  sensors: { temperature: 45, pressure: 30, vibration: 1.2, load: 40 },
  prevSensors: {},
  faults: { overTemp: false, lowPressure: false, highPressure: false, highVib: false, overLoad: false },
  healthScore: 85,
  startTime: Date.now(),
  speed: 72,
  odo: 12540,
  range: 280,
  driveMode: 'NORMAL',
  tyreStatus: { fl: 'good', fr: 'good', rl: 'good', rr: 'good' },
  history: { temperature: [], pressure: [], vibration: [], load: [], health: [] },
};

const scenarios = [
  { name: 'normal',       duration: 12000, target: { temperature: 48, pressure: 31, vibration: 1.0, load: 42 } },
  { name: 'heating',      duration: 10000, target: { temperature: 82, pressure: 33, vibration: 1.8, load: 55 } },
  { name: 'overpressure', duration: 8000,  target: { temperature: 75, pressure: 41, vibration: 2.1, load: 60 } },
  { name: 'critical',     duration: 8000,  target: { temperature: 95, pressure: 42, vibration: 4.5, load: 88 } },
  { name: 'recovery',     duration: 10000, target: { temperature: 55, pressure: 30, vibration: 1.2, load: 45 } },
];
let scenarioIdx = 0;
let scenarioStart = Date.now();

function getCurrentTarget() {
  const sc = scenarios[scenarioIdx];
  const elapsed = Date.now() - scenarioStart;
  if (elapsed >= sc.duration) {
    scenarioIdx = (scenarioIdx + 1) % scenarios.length;
    scenarioStart = Date.now();
  }
  return scenarios[scenarioIdx].target;
}

function interpolateSensor(current, target, speed = 0.06) {
  return current + (target - current) * speed + (Math.random() - 0.5) * 0.5;
}

function clamp(v, min, max) { return Math.min(max, Math.max(min, v)); }

function tickSimulation() {
  const target = getCurrentTarget();

  Object.keys(SENSOR_CONFIG).forEach(key => {
    const cfg = SENSOR_CONFIG[key];
    const raw = interpolateSensor(state.sensors[key], target[key]);
    state.sensors[key] = clamp(raw, cfg.min, cfg.max);
  });

  state.speed = clamp(state.speed + (Math.random() - 0.48) * 3, 55, 120);
  state.odo += state.speed / 3600;
  state.range = Math.max(0, state.range - state.speed / 36000);

  const s = state.sensors;
  state.faults.overTemp     = s.temperature > FAULT_THRESHOLDS.overTemp.val;
  state.faults.lowPressure  = s.pressure < FAULT_THRESHOLDS.lowPressure.val;
  state.faults.highPressure = s.pressure > FAULT_THRESHOLDS.highPressure.val;
  state.faults.highVib      = s.vibration > FAULT_THRESHOLDS.highVib.val;
  state.faults.overLoad     = s.load > FAULT_THRESHOLDS.overLoad.val;

  let penaltyPct = 0;
  if (state.faults.overTemp)     penaltyPct += (s.temperature - 70)  / 50 * 30;
  if (state.faults.highPressure) penaltyPct += (s.pressure - 35)     / 20 * 20;
  if (state.faults.lowPressure)  penaltyPct += (28 - s.pressure)     / 13 * 20;
  if (state.faults.highVib)      penaltyPct += (s.vibration - 2.5)   / 5.5 * 25;
  if (state.faults.overLoad)     penaltyPct += (s.load - 70)         / 60 * 20;
  const targetHealth = clamp(100 - penaltyPct, 0, 100);
  state.healthScore = state.healthScore + (targetHealth - state.healthScore) * 0.08;

  const tempStatus  = s.temperature > 90 ? 'critical' : s.temperature > 70 ? 'warning' : 'good';
  const presStatus  = (s.pressure > 40 || s.pressure < 24) ? 'critical' : (s.pressure > 35 || s.pressure < 28) ? 'warning' : 'good';
  state.tyreStatus.fl = tempStatus;
  state.tyreStatus.fr = presStatus;
  state.tyreStatus.rl = 'good';
  state.tyreStatus.rr = 'good';

  const MAX_HISTORY = 30;
  ['temperature','pressure','vibration','load'].forEach(k => {
    state.history[k].push(state.sensors[k]);
    if (state.history[k].length > MAX_HISTORY) state.history[k].shift();
  });
  state.history.health.push(state.healthScore);
  if (state.history.health.length > MAX_HISTORY) state.history.health.shift();
}

function getSensorStatus(key, value) {
  const cfg = SENSOR_CONFIG[key];
  const [lo, hi] = cfg.normal;
  if (key === 'pressure') {
    if (value < lo - 5 || value > hi + 8) return { label: 'CRITICAL', cls: 'badge-critical' };
    if (value < lo)      return { label: 'LOW',      cls: 'badge-warning' };
    return { label: 'NORMAL', cls: 'badge-normal' };
  }
  if (key === 'load') {
    if (value > 100)  return { label: 'OVERLOAD', cls: 'badge-overload' };
    if (value > hi)   return { label: 'HIGH',     cls: 'badge-high' };
    return { label: 'NORMAL', cls: 'badge-normal' };
  }
  if (value > hi * 1.35) return { label: 'CRITICAL', cls: 'badge-critical' };
  if (value > hi)         return { label: 'HIGH',    cls: 'badge-high' };
  return { label: 'NORMAL', cls: 'badge-normal' };
}

function qs(sel, parent = document) { return parent.querySelector(sel); }
function setTxt(el, txt) { if (el) el.textContent = txt; }

function updateSensorCard(key) {
  const val  = state.sensors[key];
  const status = getSensorStatus(key, val);
  const card = qs(`#card-${key}`);
  if (!card) return;

  const valEl   = qs('.sensor-value',  card);
  const badgeEl = qs('.sensor-badge',  card);

  if (valEl) {
    const decimals = key === 'vibration' ? 2 : key === 'temperature' ? 1 : 0;
    valEl.textContent = val.toFixed(decimals);
  }
  if (badgeEl) {
    badgeEl.textContent = status.label;
    badgeEl.className = 'sensor-badge ' + status.cls;
  }

  if (valEl) {
    const statusColors = {
      'badge-normal':   'var(--green)',
      'badge-warning':  'var(--yellow)',
      'badge-high':     'var(--red)',
      'badge-critical': 'var(--red)',
      'badge-overload': 'var(--orange)',
    };
    /* Sync pressure mapping to target Cyan color when operating safely */
    if(key === 'pressure' && status.cls === 'badge-normal') {
      valEl.style.color = 'var(--blue)';
    } else {
      valEl.style.color = statusColors[status.cls] || 'var(--white)';
    }
  }
}

function updateHealthScore() {
  const pct = state.healthScore;
  const scoreEl  = qs('#health-pct');
  const badgeEl  = qs('#health-badge');
  const canvasEl = qs('#health-gauge-canvas');

  if (scoreEl) scoreEl.textContent = Math.round(pct) + '%';

  let statusLabel, statusColor;
  if      (pct >= 80) { statusLabel = 'EXCELLENT'; statusColor = '#00FF7F'; }
  else if (pct >= 60) { statusLabel = 'GOOD';      statusColor = '#00BFFF'; }
  else if (pct >= 40) { statusLabel = 'WARNING';   statusColor = '#FF8C00'; }
  else                { statusLabel = 'CRITICAL';  statusColor = '#FF3B30'; }

  if (badgeEl) {
    badgeEl.textContent = statusLabel;
    badgeEl.style.background = statusColor + '22';
    badgeEl.style.color = statusColor;
    badgeEl.style.border = `1px solid ${statusColor}44`;
  }
  if (scoreEl) scoreEl.style.color = statusColor;
  if (canvasEl) drawHealthGauge(canvasEl, pct, statusColor);
}

function drawHealthGauge(canvas, pct, color) {
  const dpr = window.devicePixelRatio || 1;
  const W = canvas.clientWidth  || 130;
  const H = canvas.clientHeight || 130;
  canvas.width  = W * dpr;
  canvas.height = H * dpr;
  const ctx = canvas.getContext('2d');
  ctx.scale(dpr, dpr);

  const cx = W / 2, cy = H / 2;
  const r  = Math.min(W, H) * 0.42;
  const startAngle = Math.PI;
  const endAngle   = 2 * Math.PI;

  ctx.clearRect(0, 0, W, H);

  ctx.beginPath();
  ctx.arc(cx, cy, r, startAngle, endAngle);
  ctx.strokeStyle = '#161f30';
  ctx.lineWidth = 10;
  ctx.lineCap = 'round';
  ctx.stroke();

  const grad = ctx.createLinearGradient(cx - r, cy, cx + r, cy);
  grad.addColorStop(0,   '#FF3B30');
  grad.addColorStop(0.4, '#FFD93D');
  grad.addColorStop(1,   '#00FF7F');

  const valueFrac  = pct / 100;
  const valueAngle = startAngle + valueFrac * (endAngle - startAngle);

  ctx.beginPath();
  ctx.arc(cx, cy, r, startAngle, valueAngle);
  ctx.strokeStyle = grad;
  ctx.lineWidth = 10;
  ctx.lineCap = 'round';
  ctx.stroke();

  const nx = cx + r * Math.cos(valueAngle);
  const ny = cy + r * Math.sin(valueAngle);
  ctx.beginPath();
  ctx.arc(nx, ny, 5, 0, Math.PI * 2);
  ctx.fillStyle = color;
  ctx.fill();
}

function updateFaultPanel() {
  const faultMap = {
    overTemp:     'fault-overtemp',
    lowPressure:  'fault-lowpressure',
    highPressure: 'fault-highpressure',
    highVib:      'fault-highvib',
    overLoad:     'fault-overload',
  };

  Object.entries(state.faults).forEach(([key, active]) => {
    const el = qs(`#${faultMap[key]}`);
    if (!el) return;
    el.classList.toggle('active', active);
    const statusIcon = qs('.fault-status-icon', el);
    if (statusIcon) {
      statusIcon.className = 'fault-status-icon ' + (active ? 'fault' : 'ok');
      statusIcon.textContent = active ? '✕' : '✓';
    }
  });
}

function updateWarnings() {
  const container = qs('#warnings-list');
  if (!container) return;

  const warns = [];
  if (state.faults.overTemp)     warns.push({ text: 'Over Temperature Detected', color: 'red' });
  if (state.faults.highPressure) warns.push({ text: 'High Pressure Detected',    color: 'red' });
  if (state.faults.lowPressure)  warns.push({ text: 'Low Pressure Detected',     color: 'yellow' });
  if (state.faults.highVib)      warns.push({ text: 'High Vibration Detected',   color: 'yellow' });
  if (state.faults.overLoad)     warns.push({ text: 'Vehicle Over Load',         color: 'red' });

  container.innerHTML = '';
  if (warns.length === 0) {
    container.innerHTML = '<div style="font-size:11px;color:var(--green);padding:8px 10px;border:1px solid rgba(0,255,127,0.15);border-radius:4px;background:rgba(0,255,127,0.02);">✓ All Systems Normal</div>';
    return;
  }
  warns.forEach(w => {
    const div = document.createElement('div');
    div.className = 'warning-item warning-enter' + (w.color === 'yellow' ? ' warn-yellow' : '');
    div.innerHTML = `<span class="warning-icon">⚠</span>${w.text}`;
    container.appendChild(div);
  });
}

function updateMaintenance() {
  const s = state.sensors;
  const priorities = {
    replaceTyre:        s.temperature > 85 ? 'high' : s.temperature > 70 ? 'medium' : 'low',
    wheelBalancing:     s.vibration > 3.5  ? 'high' : s.vibration > 2.5  ? 'medium' : 'none',
    pressureInspection: (s.pressure < 26 || s.pressure > 38) ? 'medium' : 'low',
    suspensionInspection: s.load > 90 ? 'medium' : 'low',
  };

  const elMap = {
    replaceTyre: '#maint-replace',
    wheelBalancing: '#maint-balance',
    pressureInspection: '#maint-pressure',
    suspensionInspection: '#maint-suspension',
  };

  const labelMap = { none: 'NONE', low: 'LOW', medium: 'MEDIUM', high: 'HIGH' };

  Object.entries(priorities).forEach(([key, priority]) => {
    const el = qs(elMap[key]);
    if (!el) return;
    const pEl = qs('.maint-priority', el);
    if (pEl) {
      pEl.textContent = labelMap[priority];
      pEl.className = `maint-priority priority-${priority}`;
    }
  });
}

function updateTyreStatusPanel() {
  const slots = { fl: 'tyre-fl', fr: 'tyre-fr', rl: 'tyre-rl', rr: 'tyre-rr' };
  const labelMap = { good: 'GOOD', warning: 'WARNING', critical: 'CRITICAL' };

  Object.entries(state.tyreStatus).forEach(([key, status]) => {
    const el = qs(`#${slots[key]}`);
    if (!el) return;
    const oval  = qs('.tyre-oval', el);
    const label = qs('.tyre-slot-status', el);
    if (oval)  oval.className = `tyre-oval status-${status}`;
    if (label) {
      label.textContent = labelMap[status];
      const colors = { good: 'var(--green)', warning: 'var(--yellow)', critical: 'var(--red)' };
      label.style.color = colors[status];
    }
  });
}

function updateVehicleStats() {
  const speedEl = qs('#stat-speed');
  const odoEl   = qs('#stat-odo');
  const rangeEl = qs('#stat-range');
  if (speedEl) speedEl.textContent = Math.round(state.speed);
  if (odoEl)   odoEl.textContent   = Math.round(state.odo).toLocaleString();
  if (rangeEl) rangeEl.textContent = Math.round(state.range);
}

function updateClock() {
  const now    = new Date();
  const timeEl = qs('#header-time');
  const dateEl = qs('#header-date');
  const rteEl  = qs('#header-runtime');

  if (timeEl) {
    const mm = String(now.getMinutes()).padStart(2,'0');
    const ss = String(now.getSeconds()).padStart(2,'0');
    const ampm = now.getHours() >= 12 ? 'PM' : 'AM';
    const h12 = now.getHours() % 12 || 12;
    timeEl.textContent = `${String(h12).padStart(2,'0')}:${mm}:${ss} ${ampm}`;
  }
  if (dateEl) {
    dateEl.textContent = now.toLocaleDateString('en-US', { day:'2-digit', month:'long', year:'numeric' });
  }
  if (rteEl) {
    const elapsed = Math.floor((Date.now() - state.startTime) / 1000);
    const h = String(Math.floor(elapsed / 3600)).padStart(2,'0');
    const m = String(Math.floor((elapsed % 3600) / 60)).padStart(2,'0');
    const s = String(elapsed % 60).padStart(2,'0');
    rteEl.textContent = `UPTIME ${h}:${m}:${s}`;
  }

  setTxt(qs('#sys-uptime'), qs('#header-runtime')?.textContent.replace('UPTIME ', '') || '00:00:00');
  if (qs('#sys-time') && timeEl) qs('#sys-time').textContent = timeEl.textContent;
}

function updateCallouts() {
  const s = state.sensors;
  const callouts = {
    'callout-temp':     { val: s.temperature.toFixed(1) + '°C', alert: state.faults.overTemp,    color: '#FF3B30' },
    'callout-vibration':{ val: s.vibration.toFixed(2) + 'g',    alert: state.faults.highVib,     color: '#FFD93D' },
    'callout-load':     { val: s.load.toFixed(0) + '%',          alert: state.faults.overLoad,    color: '#00FF7F' },
    'callout-pressure': { val: s.pressure.toFixed(1) + ' PSI',   alert: state.faults.highPressure || state.faults.lowPressure, color: '#00BFFF' },
  };

  Object.entries(callouts).forEach(([id, data]) => {
    const el = qs(`#${id}`);
    if (!el) return;
    const valEl   = qs('.callout-value', el);
    const alertEl = qs('.callout-alert', el);
    if (valEl) valEl.textContent = data.val;
    if (alertEl) alertEl.textContent = data.alert ? 'Warning' : 'Normal';
    el.style.borderColor = data.alert ? data.color + 'aa' : 'rgba(255,255,255,0.08)';
  });
}

function updateSparklines() {
  const sparkMap = {
    temperature: { id: 'spark-temp',     color: '#FF3B30' },
    pressure:    { id: 'spark-pressure', color: '#00BFFF' },
    vibration:   { id: 'spark-vibration',color: '#FFD93D' },
    load:        { id: 'spark-load',     color: '#00FF7F' },
  };

  Object.entries(sparkMap).forEach(([key, cfg]) => {
    const canvas = qs(`#${cfg.id}`);
    if (!canvas || !canvas.getContext) return;
    const data = state.history[key];
    if (data.length < 2) return;

    const dpr = window.devicePixelRatio || 1;
    const W = canvas.clientWidth  || 120;
    const H = canvas.clientHeight || 24;
    canvas.width  = W * dpr;
    canvas.height = H * dpr;
    const ctx = canvas.getContext('2d');
    ctx.scale(dpr, dpr);

    const minV = Math.min(...data) * 0.95;
    const maxV = Math.max(...data) * 1.05 || minV + 1;
    const range = maxV - minV || 1;

    ctx.clearRect(0, 0, W, H);
    const grad = ctx.createLinearGradient(0, 0, 0, H);
    grad.addColorStop(0, cfg.color + '33');
    grad.addColorStop(1, cfg.color + '00');
    
    ctx.beginPath();
    data.forEach((v, i) => {
      const x = (i / (data.length - 1)) * W;
      const y = H - ((v - minV) / range) * (H - 4) - 2;
      i === 0 ? ctx.moveTo(x, y) : ctx.lineTo(x, y);
    });
    ctx.lineTo(W, H); ctx.lineTo(0, H); ctx.closePath();
    ctx.fillStyle = grad; ctx.fill();

    ctx.beginPath();
    data.forEach((v, i) => {
      const x = (i / (data.length - 1)) * W;
      const y = H - ((v - minV) / range) * (H - 4) - 2;
      i === 0 ? ctx.moveTo(x, y) : ctx.lineTo(x, y);
    });
    ctx.strokeStyle = cfg.color;
    ctx.lineWidth = 1.2;
    ctx.stroke();
  });
}

function mainUpdate() {
  tickSimulation();
  ['temperature','pressure','vibration','load'].forEach(k => updateSensorCard(k));
  updateHealthScore();
  updateFaultPanel();
  updateWarnings();
  updateMaintenance();
  updateTyreStatusPanel();
  updateVehicleStats();
  updateCallouts();
  updateSparklines();

  if (window.chartSystem) window.chartSystem.update(state);
}

function init() {
  setInterval(mainUpdate, 1000);
  setInterval(updateClock, 500);
  mainUpdate();
}

window.dashboardState = state;
window.dashboardInit  = init;