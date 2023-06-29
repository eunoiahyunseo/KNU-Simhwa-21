import React from "react";
import styled from "styled-components";

const Text = styled.span`
  color: #ff3a4a;
`;

const RedPoint = ({ children, ...rest }) => {
  return <Text {...rest}>{children}</Text>;
};

export default RedPoint;
