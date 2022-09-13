const abc = process.argv.slice(2);
const fs = require("fs");
for (i in abc) {
  fs.readFile(abc[i], "utf8", (err, data) => {
    if (err) {
      console.error(err);
      return;
    }
    console.log(data);
  });
}
