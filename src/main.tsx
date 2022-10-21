import { fetchAndInstantiate } from "./util";
fetchAndInstantiate("hello.wasm",{}).then(function (instance) {
  var ho = instance.exports.how_old(2021, 2000);
  console.log(ho)
  // var ageEl = document.getElementById("age");
  // ageEl.innerText = ho;e
});
