const { createClient } = require("redis");

const client = createClient();

client.on("error", (err) => console.log("Redis Client Error", err));

(async () => {
  await client.connect();
  await client.set("key", "value");
  const value = await client.get("key");
  console.log(value);
})();
