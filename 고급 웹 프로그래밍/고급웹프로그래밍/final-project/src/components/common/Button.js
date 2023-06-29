import React from "react";
import styled, { css } from "styled-components";
import palette from "../../lib/styles/palette";
import { Link } from "react-router-dom";

const buttonStyle = css`
  border: none;
  border-radius: 4px;
  font-size: 1rem;
  font-weight: bold;
  padding: 0.25rem 1rem;
  color: white;
  outline: none;
  cursor: pointer;
  margin-top: 0px !important;
  background: ${palette.gray[8]};
  transition: all 0.5s ease;
  &:hover {
    background: ${palette.gray[6]};
  }

  ${(props) =>
    props.cyan &&
    css`
      background: ${palette.cyan[7]};
      &:hover {
        background: ${palette.cyan[6]};
      }
    `}

  ${(props) =>
    props.yellow &&
    css`
      background: #f5d922;
      &:hover {
        background: #f5cb22;
      }
    `}

  ${(props) =>
    props.fullWidth &&
    css`
      padding: 0.5rem 0rem;
      width: 100%;
      font-size: 0.9rem;
    `}

	&:disabled {
    background: ${palette.gray[3]};
    color: ${palette.gray[5]};
    cursor: not-allowed;
  }
`;

const StyledButton = styled.button`
  ${buttonStyle}
`;

const StyledLink = styled(Link)`
  ${buttonStyle}
`;

const Button = (props) => {
  return props.to ? (
    <StyledLink {...props} cyan={props.cyan ? 1 : 0} />
  ) : (
    <StyledButton {...props} />
  );
};

export default Button;
