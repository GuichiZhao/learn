var __awaiter =
  (this && this.__awaiter) ||
  function (thisArg, _arguments, P, generator) {
    function adopt(value) {
      console.log("Adopt");

      if (value instanceof P) {
        return value;
      } else {
        return new P(function (resolve) {
          resolve(value);
        });
      }
    }
    return new (P || (P = Promise))(function (resolve, reject) {
      function fulfilled(value) {
        try {
          step(generator.next(value));
        } catch (e) {
          reject(e);
        }
      }
      function rejected(value) {
        try {
          step(generator["throw"](value));
        } catch (e) {
          reject(e);
        }
      }
      function step(result) {
        console.log("step");
        result.done
          ? resolve(result.value)
          : adopt(result.value).then(fulfilled, rejected);
      }
      generator = generator.apply(thisArg, _arguments || []);
      const x = generator.next();
      step(x);
    });
  };
function test(s) {
  debugger;
  return __awaiter(this, void 0, void 0, function* () {
    let i = 0;
    while (i++ < 5) {
      const v = yield getValue(i + " " + s);
      console.log(v);
    }
    console.log("finish async " + s);
    return "xx";
  });
}
function getValue(str) {
  return __awaiter(this, void 0, void 0, function* () {
    return str;
  });
}
test("hello");
