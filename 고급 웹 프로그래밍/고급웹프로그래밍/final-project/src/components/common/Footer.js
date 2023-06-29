import React from "react";
import styled from "styled-components";

const Container = styled.footer`
  display: flex;
  flex-direction: column;
  row-gap: 20px;
  justify-content: center;
  align-items: center;
  width: 100%;
  height: 100px;
  background-color: rgb(245, 245, 245);
  color: #858585;
  z-index: 5;
  position: absolute;
  bottom: 0;
`;

const StyledLinkTag = styled.a`
  &:hover {
    color: black;
  }
`;

const StyledLinkContainer = styled.div`
  display: flex;
  align-items: center;
`;
const Footer = () => {
  return (
    <Container>
      Copyright {new Date().getFullYear()}. Hyunseo all rights
      reserved.
      <div
        style={{
          display: "flex",
          flexDirection: "column",
          fontSize: "12px",
          alignItems: "center",
          columnGap: "7px",
        }}
      >
        <StyledLinkContainer>
          <svg
            className="w-6 h-6"
            fill="currentColor"
            viewBox="0 0 20 20"
            xmlns="http://www.w3.org/2000/svg"
            style={{ width: "17px", marginRight: "7px" }}
          >
            <path
              fillRule="evenodd"
              d="M12.586 4.586a2 2 0 112.828 2.828l-3 3a2 2 0 01-2.828 0 1 1 0 00-1.414 1.414 4 4 0 005.656 0l3-3a4 4 0 00-5.656-5.656l-1.5 1.5a1 1 0 101.414 1.414l1.5-1.5zm-5 5a2 2 0 012.828 0 1 1 0 101.414-1.414 4 4 0 00-5.656 0l-3 3a4 4 0 105.656 5.656l1.5-1.5a1 1 0 10-1.414-1.414l-1.5 1.5a2 2 0 11-2.828-2.828l3-3z"
              clipRule="evenodd"
            />
          </svg>
          <StyledLinkTag
            href="https://hyunseo-fullstackdiary.tistory.com"
            target="_blank"
            rel="noreferrer"
          >
            https://hyunseo-fullstackdiary.tistory.com
          </StyledLinkTag>
        </StyledLinkContainer>
        <StyledLinkContainer>
          <svg
            className="w-6 h-6"
            fill="currentColor"
            viewBox="0 0 20 20"
            xmlns="http://www.w3.org/2000/svg"
            style={{ width: "17px", marginRight: "7px" }}
          >
            <path
              fillRule="evenodd"
              d="M12.586 4.586a2 2 0 112.828 2.828l-3 3a2 2 0 01-2.828 0 1 1 0 00-1.414 1.414 4 4 0 005.656 0l3-3a4 4 0 00-5.656-5.656l-1.5 1.5a1 1 0 101.414 1.414l1.5-1.5zm-5 5a2 2 0 012.828 0 1 1 0 101.414-1.414 4 4 0 00-5.656 0l-3 3a4 4 0 105.656 5.656l1.5-1.5a1 1 0 10-1.414-1.414l-1.5 1.5a2 2 0 11-2.828-2.828l3-3z"
              clipRule="evenodd"
            />
          </svg>
          <StyledLinkTag
            href="https://www.instagram.com/eunoia._.hys"
            target="_blank"
            rel="noreferrer"
          >
            @eunoia._.hys
          </StyledLinkTag>
        </StyledLinkContainer>
      </div>
    </Container>
  );
};

export default Footer;
