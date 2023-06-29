import React from "react";
import * as Styled from "../../styled";

import { Explain, ExperienceCardTitle } from "../../common";

const University = () => {
  return (
    <Styled.ExperienceCard>
      <Styled.ExperienceCardTitleType>대학교</Styled.ExperienceCardTitleType>
      <ExperienceCardTitle image src="/knu.jpeg" title="경북대학교" id="knu" />
      <Styled.ExperienceCardExplainContainer>
        <Explain>2021 ~ current 심화컴퓨터학과 재학중</Explain>
        <Explain>학점 4.1 / 4.3</Explain>
        <Explain>KERT Vice Chairman 활동중.</Explain>
        <Explain>멋쟁이 사자처럼 활동중</Explain>
      </Styled.ExperienceCardExplainContainer>
    </Styled.ExperienceCard>
  );
};

export default University;
