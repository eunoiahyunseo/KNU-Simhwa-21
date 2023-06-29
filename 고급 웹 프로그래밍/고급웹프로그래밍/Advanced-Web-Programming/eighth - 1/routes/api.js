const express = require("express");
const axios = require("axios");
const { createClient } = require("redis");
const dotenv = require("dotenv");

dotenv.config();
const redisClient = createClient({
  url: `redis://${process.env.REDIS_HOST}:${process.env.REDIS_PORT}`,
  password: process.env.REDIS_PASSWORD,
});

const router = express.Router();

router.get("/university/turkey", async (req, res) => {
  try {
    const { data: universityData } = await axios.get(
      "http://universities.hipolabs.com/search?name=university&country=turkey"
    );
    await req.redisClient.set(req.redisURL, JSON.stringify(universityData));
    return res.json(universityData);
  } catch (err) {
    console.error(err);
    return res.status(500).json({
      status: 500,
      response: err.message,
    });
  }
});

module.exports = router;
