import React, { useRef, useEffect } from "react";
import styled from "styled-components";
import { gsap } from "gsap";

import { REGULAR_TEXT } from "#/constants";

const BodyTextContainer = styled.div`
  font-family: ${REGULAR_TEXT};
  color: white;
  z-index: 5;
`;

const FadeInBodyText = ({ children, delay }) => {
  const target = useRef(null);

  useEffect(() => {
    gsap.from(target.current, {
      scrollTrigger: {
        trigger: target.current,
        toggleActions: "play none none none",
      },
      top: "-15%",
      opacity: 0,
      delay,
      duration: 1.5,
      ease: "power3.out",
    });
  }, [delay]);
  return <BodyTextContainer ref={target}>{children}</BodyTextContainer>;
};

export default FadeInBodyText;
