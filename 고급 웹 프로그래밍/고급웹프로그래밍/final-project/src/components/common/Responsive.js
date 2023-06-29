import React from "react";
import styled from "styled-components";

const ResponsiveBlock = styled.div`
  margin: 0 auto;
  padding-left: 1rem;
  padding-right: 1rem;
`;

const Responsive = ({ children, ...rest }) => {
  return <ResponsiveBlock {...rest}>{children}</ResponsiveBlock>;
};

export default Responsive;
