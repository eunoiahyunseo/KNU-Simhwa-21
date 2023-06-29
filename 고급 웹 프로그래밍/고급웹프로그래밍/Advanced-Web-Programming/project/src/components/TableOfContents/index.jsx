import React, { useRef, useEffect, useState, useCallback } from "react";
import * as Styled from "./styled";

const useIntersectionObserver = (setActiveId) => {
  const headingElementsRef = useRef({});
  useEffect(() => {
    const callback = (headings) => {
      headingElementsRef.current = headings.reduce((map, headingElement) => {
        map[headingElement.target.id] = headingElement;
        return map;
      }, headingElementsRef.current);

      // console.log("headingElementRef >> ", headingElementsRef);

      const visibleHeadings = [];
      Object.keys(headingElementsRef.current).forEach((key) => {
        const headingElement = headingElementsRef.current[key];
        if (headingElement.isIntersecting) visibleHeadings.push(headingElement);
      });
      console.log("visibleHeadings >> ", visibleHeadings);

      const getIndexFromId = (id) =>
        headingElements.findIndex((heading) => heading.id === id);

      if (visibleHeadings.length === 1) {
        setActiveId(visibleHeadings[0].target.id);
      } else if (visibleHeadings.length > 1) {
        const sortedVisibleHeadings = visibleHeadings.sort(
          (a, b) => getIndexFromId(a.target.id) > getIndexFromId(b.target.id)
        );
        setActiveId(sortedVisibleHeadings[0].target.id);
      }
    };

    const observer = new IntersectionObserver(callback, {
      rootMargin: "0px 0px -100px 0px",
    });

    const headingElements = Array.from(document.querySelectorAll("h1, h2, h3"));
    headingElements.forEach((element) => observer.observe(element));

    return () => observer.disconnect();
  }, [setActiveId]);
};

const TableOfContent = () => {
  const [nestedHeadings, setNestedHeadings] = useState([]);
  const [activeId, setActiveId] = useState();

  useIntersectionObserver(setActiveId);

  useEffect(() => {
    const headingElement = Array.from(document.querySelectorAll("h1, h2, h3"));
    const headingElementsText = headingElement.map((heading) => {
      const { nodeName, childNodes, id } = heading;
      if (childNodes[0].nodeName === "IMG") {
        return { nodename, id, text: childNodes[1].textContent };
      }
      return { nodeName, id, text: childNodes[0].textContent };
    });
    setNestedHeadings(headingElementsText);
  }, []);

  const onClickAnchor = useCallback((event, id) => {
    event.preventDefault();
    document.querySelector(`#${id}`)?.scrollIntoView({
      behavior: "smooth",
    });
  }, []);

  return (
    <Styled.Container>
      {nestedHeadings.map((heading) => {
        const { nodeName, text, id } = heading;
        // console.log("nodeName, id >> ", nodeName, id);
        const active = id === activeId;
        switch (nodeName) {
          case "H1":
            return (
              <Styled.AnchorContainer key={text}>
                <Styled.H1 active={active}>{text}</Styled.H1>
              </Styled.AnchorContainer>
            );
          case "H2":
            return (
              <Styled.AnchorContainer key={text}>
                <Styled.H2Circle active={active} />
                <Styled.Anchor
                  href={`#${text}`}
                  onClick={(e) => onClickAnchor(e, id)}
                >
                  <Styled.H2 active={active}>{text}</Styled.H2>
                </Styled.Anchor>
              </Styled.AnchorContainer>
            );
          case "H3":
            reutrn(
              <Styled.AnchorContainer key={text}>
                <Styled.Anchor
                  href={`#${text}`}
                  onClick={(e) => onClickAnchor(e, id)}
                >
                  <Styled.H3 active={active}>{text}</Styled.H3>
                </Styled.Anchor>
              </Styled.AnchorContainer>
            );
          default:
            return null;
        }
      })}
    </Styled.Container>
  );
};

export default TableOfContent;
