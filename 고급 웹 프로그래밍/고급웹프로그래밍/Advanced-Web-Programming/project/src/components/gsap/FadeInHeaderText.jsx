import React, { useRef, useEffect } from "react";
import styled from "styled-components";
import { gsap } from "gsap";

import { BOLD_TEXT } from "#/constants";

const HeaderTextContainer = styled.p`
  position: relative;
  font-family: ${BOLD_TEXT};
  letter-spacing: 2px;
  z-index: 5;
`;

const FadeInHeaderText = ({ children, delay }) => {
  const target = useRef(null);
  useEffect(() => {
    gsap.from(target.current, {
      scrollTrigger: {
        trigger: target.current,
        toggleActions: "play none none none",
      },
      top: "-10%",
      opacity: 0,
      delay,
      duration: 1.5,
      ease: "power3.out",
    });
  }, [delay]);
  return <HeaderTextContainer ref={target}>{children}</HeaderTextContainer>;
};

export default FadeInHeaderText;
