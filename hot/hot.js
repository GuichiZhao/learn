const fs = require("fs");
const parseTitle = (text) => {
  let open = "",
    content = "",
    close = "";
  for (let i = 0; i < text.length; i++) {
    if ("<title>" === text.slice(i, i + 7)) {
      open = i + 7;
      i += 7;
    }
    if ("</title>" === text.slice(i, i + 8)) {
      close = i;
      break;
    }
  }
  content = text.slice(open, close);
  return content;
};

async function run() {
  let result = "";
  const from = 500,
    to = 600;
  for (let i = from; i <= to; i++) {
    const url = "https://njav.tv/ja/v/tokyo-hot-n0" + i;

    await fetch(url).then((e) => {
      if (e.status !== 404) {
        console.log(url);
        e.text().then((text) => {
          result += url;
          result += "\n";
          result += parseTitle(text);
          result += "\n";
          result += "\n";
        });
      } else {
        console.log("404", url);
      }
    });
  }
  fs.writeFileSync(`${from}-${to}.md`, result);
  console.log("done");
}

run();
