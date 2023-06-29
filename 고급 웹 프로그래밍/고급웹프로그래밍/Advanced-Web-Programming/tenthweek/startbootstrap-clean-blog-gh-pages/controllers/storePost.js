const BlogPost = require("../models/BlogPost");
const path = require("path");

module.exports = (req, res) => {
  const image = req.files.image;

  image.mv(
    path.resolve(__dirname, "..", "public/img", image.name),
    async (error) => {
      if (error) {
        console.error(error);
      }

      await BlogPost.create({
        ...req.body,
        image: "/img/" + image.name,
      });
      res.redirect("/");
    }
  );
};
