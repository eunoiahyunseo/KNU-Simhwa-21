import React from "react";
import styled from "styled-components";
import palette from "../../lib/styles/palette";
import { Link } from "react-router-dom";

const TagsBox = styled.div`
  display: flex;
  flex-direction: row;
  justify-content: center;
  column-gap: 10px;
  position: relative;
  margin-top: 10px;

  .tag {
    color: ${palette.gray[6]};
    font-size: 0.9rem;
    text-decoration: none;

    &:hover {
      font-size: 1rem;
      color: ${palette.gray[8]};
    }
  }
`;

const Tags = ({ tags }) => {
  return (
    <TagsBox>
      {tags.map((tag) => (
        <Link className="tag" to={`/?tag=${tag}`} key={tag}>
          #{tag}
        </Link>
      ))}
    </TagsBox>
  );
};

export default Tags;
