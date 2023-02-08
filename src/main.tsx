import { fetchAndInstantiate } from "./utils";
import url from "./add.wasm?url";

var memory = new WebAssembly.Memory({ initial: 10, maximum: 100 });
var importObject = {
  js: { mem: memory },
};
fetchAndInstantiate(url, importObject).then(function (instance) {
  const x = instance.exports.howOld(100, 10);
  console.log(x);
});
