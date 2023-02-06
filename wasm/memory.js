var u32arr = new Uint32Array(10);
u32arr[0] = 257;
console.log(u32arr);
console.log("u32arr length: " + u32arr.length);
var u32buf = u32arr.buffer;
var u8arr = new Uint8Array(u32buf);
console.log(u8arr);
console.log("u8arr length: " + u8arr.length);
