module.exports = (req, res) => {
  if (req.session.userId) {
    return res.render("create");
  }
  return res.redirect("/auth/login");
};
