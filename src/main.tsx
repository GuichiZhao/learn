import { fetchAndInstantiate } from "./utils";
import url from "./howold.wasm?url";

var memory = new WebAssembly.Memory({ initial: 10, maximum: 100 });
var importObject = {
  js: { mem: memory },
};
fetchAndInstantiate(url, importObject).then(function (instance) {
  console.log(instance.exports);

  // console.log(x);
});
