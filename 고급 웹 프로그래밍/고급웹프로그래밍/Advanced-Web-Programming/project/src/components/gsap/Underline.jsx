import React, { useRef, useEffect } from "react";
import styled from "styled-components";
import { gsap } from "gsap";

const UnderlineContainer = styled.span`
  background-image: linear-gradient(transparent 80%, ${(props) => props.color} 20%);
  background-size: 0% 100%;
  background-repeat: no-repeat;
  z-index: -1;
`;

const Underline = ({ delay, children, color }) => {
  const target = useRef(null);
  useEffect(() => {
    gsap.to(target.current, {
      scrollTrigger: {
        trigger: target.current,
        toggleActions: "play none none none",
      },
      backgroundImage: `linear-gradient(transparent 80%, ${color} 20%)`,
      backgroundSize: "100% 100%",
      delay,
      duration: 0.6,
      ease: "expo.out",
    });
  }, [delay, color]);
  return (
    <UnderlineContainer color={color} ref={target}>
      {children}
    </UnderlineContainer>
  );
};

export default Underline;
