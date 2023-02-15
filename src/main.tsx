import { fetchAndInstantiate } from "./utils";
import url from "./library.wasm?url";

let wasm;
function get_memory() {
  return new Uint8Array(wasm.exports.memory.buffer);
}

function charPtrToString(str: number) {
  const memory = get_memory();
  let length = 0;
  for (; memory[str + length] !== 0; ++length) {}
  console.log(str);
  console.log(memory);
  console.log(length);
  return decoder.decode(memory.subarray(str, str + length));
}
const decoder = new TextDecoder("utf-8");
// const encoder = new TextEncoder("utf-8");
let printString = function (str: string) {
  console.log("str", str);
};
const importObject = {
  env: {
    js_print_string: function (ptr: number) {
      printString(charPtrToString(ptr));
    },
  },
};
fetchAndInstantiate(url, importObject).then(function (instance) {
  wasm = instance;
  console.log(instance.exports);
  instance.exports.print("aaa");
  // instance.exports.helloWorld();
  // const result = instance.exports.add(7, 8);
  // console.log(result);

  // console.log(x);
});
