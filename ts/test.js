const aNormalMap = new Map();
function pushToMap() {
  for (let i = 0; i < 10; i++) {
    aNormalMap.set({}, i);
  }
}

const aWeakMap = new WeakMap();
function pushToWeakMap() {
  for (let i = 0; i < 10; i++) {
    aWeakMap.set({}, i);
  }
}

function main() {
  pushToMap();
  /**
   * after the call the pushToMap
   */
  pushToWeakMap();
    /**
   * after the call the pushToWeakMap
   */
}
