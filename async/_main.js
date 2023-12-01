var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
function test(s) {
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
        console.log("getValue: " + str);
        return new Promise((resolve) => {
            setTimeout(() => {
                resolve(str);
            }, 1000);
        });
    });
}
test("hello");
