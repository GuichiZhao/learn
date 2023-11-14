import { locale } from "./locale-us";

const getUserLocale = () => Promise.resolve("us");
async function main() {
  let userLocale = await getUserLocale();
  let path = `./locale-${userLocale}`;
  let localeUS: typeof locale = await import(path);
  const x = Foo;
  Network.get<string>('https://api.github.com/repos/Microsoft/typescript')
}
