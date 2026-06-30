/* ============================================================
   SMART TYRE INTELLIGENCE ECU — car.js
   Vehicle visual behavior: wheel color/glow, suspension,
   shake/vibration, smoke particles, headlights
   ============================================================ */

'use strict';

(function () {
  let smokeIntervalFL = null;
  const wheelScale = { fl: 1, fr: 1 };
  const wheelRotation = { fl: 0, fr: 0 };

  /* Map temperature → wheel/tyre color stop */
  function tempToColor(temp) {
    if (temp < 50)  return { fill: '#0a0f1d', stroke: '#1e293b', glow: null };
    if (temp < 65)  return { fill: '#22252a', stroke: '#334155', glow: null };
    if (temp < 75)  return { fill: '#FFD93D', stroke: '#FFD93D', glow: 'rgba(255,217,61,0.4)' };
    if (temp < 85)  return { fill: '#FF8C00', stroke: '#FF8C00', glow: 'rgba(255,140,0,0.5)' };
    if (temp < 95)  return { fill: '#FF3B30', stroke: '#FF3B30', glow: 'rgba(255,59,48,0.6)' };
    return { fill: '#7f1d1d', stroke: '#FF3B30', glow: 'rgba(255,0,0,0.8)' };
  }

  /* Map pressure → tyre scale (radius) */
  function pressureToScale(pressure) {
    /* 15 psi -> flat (0.88), 30 psi -> normal (1.0), 50 psi -> overinflated (1.08) */
    const clamped = Math.min(50, Math.max(15, pressure));
    return 0.88 + ((clamped - 15) / (50 - 15)) * 0.20;
  }

  function applyWheelTransform(side) {
    const rotor = document.getElementById(side === 'fl' ? 'wheel-fl-rotor' : 'wheel-fr-rotor');
    if (!rotor) return;
    rotor.style.transform = `scale(${wheelScale[side]}) rotate(${wheelRotation[side]}deg)`;
  }

  function setWheelVisual(side, rubberId, temp, pressure) {
    const tyre = document.getElementById(rubberId);
    if (!tyre) return;
    const color = tempToColor(temp);

    tyre.style.fill = color.fill;
    tyre.style.stroke = color.stroke;
    tyre.style.filter = color.glow ? `drop-shadow(0 0 6px ${color.glow})` : 'none';
    tyre.style.transition = 'fill 0.6s ease, stroke 0.6s ease, filter 0.6s ease';

    wheelScale[side] = pressureToScale(pressure);
    applyWheelTransform(side);
  }

  function spawnSmoke(containerId, intensity = 1) {
    const container = document.getElementById(containerId);
    if (!container) return;
    const count = Math.min(2, Math.ceil(intensity));
    for (let i = 0; i < count; i++) {
      const puff = document.createElement('div');
      puff.className = 'smoke-particle';
      const size = 6 + Math.random() * 8;
      puff.style.width = size + 'px';
      puff.style.height = size + 'px';
      puff.style.left = (Math.random() * 8 - 4) + 'px';
      puff.style.bottom = '10px';
      puff.style.animationDelay = (Math.random() * 0.2) + 's';
      container.appendChild(puff);
      setTimeout(() => puff.remove(), 1500);
    }
  }

  function updateSuspension(load) {
    const stage = document.getElementById('vehicle-stage');
    if (!stage) return;
    /* Translate load shifts directly into subtle backdrop sizing or structural position adjustments if needed */
    /* Compressed under high load profiles (>70%) */
    const offset = ((load - 40) / 90) * 2;
    stage.style.backgroundPosition = `center calc(50% + ${Math.max(-1, Math.min(3, offset))}px)`;
    stage.style.transition = 'background-position 0.8s cubic-bezier(0.25, 1, 0.5, 1)';
  }

  function updateVibrationShake(vibration) {
    const stage = document.getElementById('vehicle-scene');
    if (!stage) return;
    stage.classList.remove('shake-mild', 'shake-strong');
    if (vibration > 4.5) {
      stage.classList.add('shake-strong');
    } else if (vibration > 2.5) {
      stage.classList.add('shake-mild');
    }
  }

  function updateDashboardShake(vibration) {
    const main = document.getElementById('main');
    if (!main) return;
    if (vibration > 5.5) {
      main.style.animation = 'shake 0.25s ease-in-out infinite';
    } else {
      main.style.animation = 'none';
    }
  }

  function onDataUpdate(state) {
    const { temperature, pressure, vibration, load } = state.sensors;

    /* Apply telemetry profiles with slight variance for real-world environmental rendering simulation */
    setWheelVisual('fl', 'wheel-fl-rubber', temperature * 1.02, pressure * 0.98);
    setWheelVisual('fr', 'wheel-fr-rubber', temperature * 0.95, pressure * 1.02);

    /* Inject dynamic micro smoke streams if the thermal thresholds shift toward a critical bracket */
    if (temperature * 1.02 > 90) {
      if (!smokeIntervalFL) {
        smokeIntervalFL = setInterval(() => spawnSmoke('smoke-fl', 1.5), 500);
      }
    } else if (smokeIntervalFL) {
      clearInterval(smokeIntervalFL);
      smokeIntervalFL = null;
    }

    updateSuspension(load);
    updateVibrationShake(vibration);
    updateDashboardShake(vibration);

    /* Toggle wheel instability indicator states during vibration faults */
    document.querySelectorAll('[data-wheel-group]').forEach(g => {
      g.classList.toggle('wheel-wobble-active', vibration > 3.5);
    });
  }

  /* Continual wheel rotation cycle tied directly into running speedometer speeds */
  function animateWheelRotation() {
    const state = window.dashboardState;
    const speed = state ? state.speed : 70;
    const delta = speed * 0.05;
    wheelRotation.fl = (wheelRotation.fl + delta) % 360;
    wheelRotation.fr = (wheelRotation.fr + delta) % 360;
    applyWheelTransform('fl');
    applyWheelTransform('fr');
    requestAnimationFrame(animateWheelRotation);
  }

  window.carAnimation = { onDataUpdate };
  requestAnimationFrame(animateWheelRotation);
})();