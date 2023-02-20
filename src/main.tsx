import { fetchAndInstantiate } from "./utils";
import url from "./library.wasm?url";

let wasm;
function get_memory() {
  return new Uint8Array(wasm.exports.memory.buffer);
}

function charPtrToString(pointer: number) {
  const memory = get_memory();
  let length = 0;
  for (; memory[pointer + length] !== 0; ++length) {}
  console.log(pointer);
  console.log(memory);
  console.log(length);
  return decoder.decode(memory.subarray(pointer, pointer + length));
}
const decoder = new TextDecoder("utf-8");

let printString = function (str: string) {
  console.log("str", str);
};
const importObject = {
  env: {
    js_print_string: function (ptr: number) {
      printString(charPtrToString(ptr));
    },
    wasi_snapshot_preview1:()=>{}
  },
};
fetchAndInstantiate(url, importObject).then(function (instance) {
  wasm = instance;
  console.log(instance.exports);
  // instance.exports.print("aaa");
  instance.exports.helloWorld();
  // const result = instance.exports.add(7, 8);
  // console.log(result);

  // console.log(x);
});

// import { WASI, File, PreopenDirectory } from "@bjorn3/browser_wasi_shim";

// let args = ["bin", "arg1", "arg2"];
// let env = ["FOO=bar"];
// let fds = [
//   new File([]), // stdin
//   new File([]), // stdout
//   new File([]), // stderr
//   // new PreopenDirectory(".", {
//   //   "example.c": new File(new TextEncoder("utf-8").encode(`#include "a"`)),
//   //   "hello.rs": new File(
//   //     new TextEncoder("utf-8").encode(`fn main() { println!("Hello World!"); }`)
//   //   ),
//   // }),
// ];
// let wasi = new WASI(args, env, fds);

// let wasm = await WebAssembly.compileStreaming(fetch(url));
// let inst = await WebAssembly.instantiate(wasm, {
//   wasi_snapshot_preview1: wasi.wasiImport,
// });
// wasi.start(inst);
