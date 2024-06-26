const uiFuncs = {
  slider: genSlider,
};

function noop() {}

function genSlider(object, ui) {
  const changeFn = ui.change || noop;
  ui.name = ui.name || ui.key;
  ui.value = object[ui.key];
  ui.slide =
    ui.slide ||
    function (event, uiInfo) {
      object[ui.key] = uiInfo.value;
      changeFn();
    };
  return makeSlider(ui);
}
function makeSlider(options) {
  const div = document.createElement("div");
  return createSlider(div, options);
}

function createSlider(parent, options) {
  var precision = options.precision || 0;
  var min = options.min || 0;
  var step = options.step || 1;
  var value = options.value || 0;
  var max = options.max || 1;
  var fn = options.slide;
  var name = options.name;
  var uiPrecision =
    options.uiPrecision === undefined ? precision : options.uiPrecision;
  var uiMult = options.uiMult || 1;

  min /= step;
  max /= step;
  value /= step;

  parent.innerHTML = `
    <div class="gman-widget-outer">
      <div class="gman-widget-label">${name}</div>
      <div class="gman-widget-value"></div>
      <input class="gman-widget-slider" type="range" min="${min}" max="${max}" value="${value}" />
    </div>
  `;
  var valueElem = parent.querySelector(".gman-widget-value");
  var sliderElem = parent.querySelector(".gman-widget-slider");

  function updateValue(value) {
    valueElem.textContent = (value * step * uiMult).toFixed(uiPrecision);
  }

  updateValue(value);

  function handleChange(event) {
    var value = parseInt(event.target.value);
    updateValue(value);
    fn(event, { value: value * step });
  }

  sliderElem.addEventListener("input", handleChange);
  sliderElem.addEventListener("change", handleChange);

  return {
    elem: parent,
    updateValue: (v) => {
      v /= step;
      sliderElem.value = v;
      updateValue(v);
    },
  };
}
/**
 *
 * @param {*} parent
 * @param {*} object
 * @param {*} uiInfos
 * @returns
 */
export function setupUI(parent, object, uiInfos) {
  const widgets = {};
  uiInfos.forEach(function (ui) {
    const widget = uiFuncs[ui.type](object, ui);
    parent.appendChild(widget.elem);
    widgets[ui.key] = widget;
  });
  return widgets;
}
