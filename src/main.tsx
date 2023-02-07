import { fetchAndInstantiate } from "./utils";
import url from "./memory2.wasm?url";

var memory = new WebAssembly.Memory({ initial: 10, maximum: 100 });
var importObject = {
  js: { mem: memory },
};
fetchAndInstantiate("url", importObject).then(function (instance) {
  var fibNum = 20;
  instance.exports.fibonacci(fibNum);
  var i32 = new Uint32Array(memory.buffer);
  var container = document.getElementById("container");
  for (var i = 0; i < fibNum; i++) {
    container.innerText += `Fib[${i}]: ${i32[i]}\n`;
  }
});
