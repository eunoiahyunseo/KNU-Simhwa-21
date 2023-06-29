const mongoose = require("mongoose");

const BlogPost = require("./models/BlogPost");

mongoose.connect(
  "mongodb://hyunseo:gustj486!!@localhost:27017",
  {
    dbName: "awp",
  }
);

(async () => {
  console.log("Strat Querying ...");
  await BlogPost.create(
    {
      title: "What is Lorem Ipsum",
      body: "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.",
    },
    (error, blogPost) => {
      console.log(error ? error : "", blogPost);
    }
  );

  BlogPost.find(
    {
      title: "What is Lorem Ipsum",
    },
    (error, blogpost) => {
      console.log(error ? error : "", blogpost);
    }
  );

  BlogPost.find({}, (error, blogpost) => {
    console.log(error ? error : "", blogpost);
  });

  BlogPost.find(
    {
      title: /Lorem/,
    },
    (error, blogpost) => {
      console.log(error ? error : "", blogpost);
    }
  );

  const id = "6282fab9c5222f2a2ac682a5";

  BlogPost.findById(id, (error, blogpost) => {
    console.log(error ? error : "", blogpost);
  });

  BlogPost.findByIdAndUpdate(
    id,
    {
      title: "Updated title Lorem v2",
    },
    (error, blogpost) => {
      console.log(error ? error : "", blogpost);
    }
  );

  BlogPost.findByIdAndDelete(id, (error, blogpost) => {
    console.log(error ? error : "", blogpost);
  });

  console.log("Done Querying");
})();
