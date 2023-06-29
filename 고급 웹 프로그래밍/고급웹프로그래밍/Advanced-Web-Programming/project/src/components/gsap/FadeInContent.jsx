import React, { useRef, useEffect } from "react";
import { gsap } from "gsap";

const FadeInContent = ({ children, delay }) => {
  const target = useRef(null);
  useEffect(() => {
    gsap.from(target.current, {
      scrollTrigger: {
        trigger: target.current,
        toggleActions: "play none none none",
      },
      opacity: 0,
      delay,
      duration: 1.5,
      ease: "power3.out",
    });
  }, [delay]);
  return <div ref={target}>{children}</div>;
};

export default FadeInContent;
