import React from "react";
import styled from "styled-components";

import LinkOutlinedIcon from "@mui/icons-material/LinkOutlined";

const HyperLink = styled.div`
  display: flex;
  column-gap: 10px;
`;

const HyperLinkIcon = styled(LinkOutlinedIcon)``;

const HyperLinkText = styled.a`
  text-underline-offset: 5px;
  font-size: 20px;
`;

const Link = ({ children, href }) => {
  return (
    <HyperLink>
      <HyperLinkIcon />
      <HyperLinkText href={href} target="_blank">
        {children}
      </HyperLinkText>
    </HyperLink>
  );
};

export default Link;
