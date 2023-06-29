const User = require("../models/User");
const path = require("path");

module.exports = (req, res) => {
  User.create(req.body, (err, user) => {
    if (err) {
      return res.redirect("/auth/register");
    }
    res.redirect("/");
  });
};
