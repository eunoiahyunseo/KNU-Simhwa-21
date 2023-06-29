import React from "react";
import styled, { css } from "styled-components";
import palette from "../../lib/styles/palette";
import { Link } from "react-router-dom";

const SubIntoBlock = styled.div`
  position: absolute;
  top: 1rem;
  left: 1rem;
  color: ${palette.cyan[6]};
  font-size: 12px;
  background: ${palette.gray[0]};
  padding: 5px 10px;
  border-radius: 1.5rem;
  font-weight: bold;

  ${(props) =>
    props.hasMarginTop &&
    css`
      margin-top: 1rem;
    `}

  span + span:before {
    color: ${palette.cyan[6]};
    padding: 0px 0.25rem;
    content: "\\B7";
  }

  a {
    text-decoration: none;
  }
`;
const SubInfo = ({ username, publishedDate, hasMarginTop }) => {
  return (
    <SubIntoBlock className="subInfo">
      <span>
        <b>
          <Link to={`/@${username}`}>{username}</Link>
        </b>
      </span>
      <span>{new Date(publishedDate).toLocaleDateString()}</span>
    </SubIntoBlock>
  );
};

export default SubInfo;
