import styled from "styled-components";

import { BOLD_TEXT, DESKTOP_CONTENT_WIDTH } from "#/constants";

export const Container = styled.section`
  display: flex;
  position: relative;
  width: 100vw;
  background-color: rgba(245, 245, 245);
`;

export const TableOfContent = styled.nav`
  position: sticky;
  top: 0;
  width: 20vw;
  height: 100vh;
`;

export const Contents = styled.article`
  display: flex;
  flex-direction: column;
  width: 80vw;
  padding: 40px;
  color: black;
`;

export const ExperienceContainer = styled.article`
  display: flex;
  width: 80vw;
  flex-direction: column;
  row-gap: 70px;
  margin-top: 70px;
  margin-bottom: 100px;

  @media ${(props) => props.theme.mobile} {
    row-gap: 55px;
  }
`;

export const ExperienceCard = styled.article`
  display: flex;
  flex-direction: column;
  row-gap: 25px;
  position: relative;
  width: ${DESKTOP_CONTENT_WIDTH};
  background-color: rgb(245, 245, 245);

  @media ${(props) => props.theme.tablet} {
    width: 80vw;
  }

  @media ${(props) => props.theme.mobile} {
    width: 80vw;
    row-gap: 15px;
  }
`;

export const ExperienceCardTitleType = styled.span`
  font-size: 24px;

  @media ${(props) => props.theme.mobile} {
    font-size: 20px;
  }
`;

export const ExperienceCardTitle = styled.h2`
  font-size: 45px;
  font-family: ${BOLD_TEXT};
  margin: 0;

  @media ${(props) => props.theme.mobile} {
    font-size: 32px;
  }
`;

export const ExperienceCardTitleImage = styled.img`
  width: 50px;
  height: 50px;
  object-fit: cover;
  margin-right: 20px;
`;

export const ExperienceCardTitleContainer = styled.div`
  display: flex;
  align-items: center;
`;

export const ExperienceCardPeriod = styled.span`
  font-size: 18px;

  @media ${(props) => props.theme.mobile} {
    font-size: 16px;
  }
`;

export const ExperienceCardExplainContainer = styled.article`
  display: flex;
  flex-direction: column;
  row-gap: 7px;
`;

export const CommonArticleContainer = styled.article``;

export const CommonArticleContainerTitle = styled.p`
  display: flex;
  align-item: center;
  column-gap: 5px;
  margin-top: 0;
  font-size: 24px;
  font-family: ${BOLD_TEXT};
`;
