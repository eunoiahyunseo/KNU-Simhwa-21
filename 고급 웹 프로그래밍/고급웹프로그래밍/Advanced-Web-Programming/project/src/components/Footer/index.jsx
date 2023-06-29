import React from "react";
import * as Styled from "./styled";

const Footer = () => {
  return (
    <Styled.Container>
      &copy;CopyRight {new Date().getFullYear()}. hyunseo all rights reserved.
    </Styled.Container>
  );
};

export default Footer;
