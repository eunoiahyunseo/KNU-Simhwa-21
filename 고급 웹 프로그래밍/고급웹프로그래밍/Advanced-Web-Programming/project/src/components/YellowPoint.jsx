import React from "react";
import styled from "styled-components";

import { UNDER_LINE_COLOR } from "#/colors";

const Text = styled.span`
  color: ${UNDER_LINE_COLOR};
`;

const YellowPoint = ({ children, ...rest }) => {
  return <Text {...rest}>{children}</Text>;
};

export default YellowPoint;
