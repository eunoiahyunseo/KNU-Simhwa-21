import React, { useCallback } from "react";
import * as Styled from "./styled";

import ArrowUpwardOutlinedIcon from "@mui/icons-material/ArrowUpwardOutlined";

const ScrollTopButton = () => {
  const scrollToTop = useCallback(
    () => window.scroll({ top: 0, behavior: "smooth" }),
    []
  );
  return (
    <Styled.Button onClick={scrollToTop}>
      <ArrowUpwardOutlinedIcon />
    </Styled.Button>
  );
};

export default ScrollTopButton;
