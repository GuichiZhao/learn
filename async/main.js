// async function test(s) {
//   let i = 0;
//   while (i++ < 5) {
//     const v = await getValue(i + " " + s);
//     console.log(v);
//   }
//   console.log("finish async " + s);
//   return "xx";
// }

// async function getValue(str) {
//   console.log("getValue: " + str);
//   return new Promise((resolve) => {
//     setTimeout(() => {
//       resolve(str);
//     }, 1000);
//   });
// }

// test("hello");

