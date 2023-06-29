import React from "react";
import * as Styled from "../../styled";
import {
  Explain,
  InlineLinkText,
  SecondIndentExplain,
  ExperienceCardTitle,
} from "../../common";

const LikeLion = () => {
  return (
    <Styled.ExperienceCard>
      <Styled.ExperienceCardTitleType>동아리</Styled.ExperienceCardTitleType>
      <ExperienceCardTitle
        image
        src="/likelion.jpg"
        title="멋쟁이 사자처럼"
        id="likelion"
      />
      <Styled.ExperienceCardPeriod>2022/3/12 - current</Styled.ExperienceCardPeriod>
      <Styled.ExperienceCardExplainContainer>
        <Explain>
          <InlineLinkText>멋쟁이 사자처럼 대학</InlineLinkText>에서 주최
        </Explain>
        <Explain>첫번째 아이디어톤 진행 (2022/3/20 - 202/3/26)</Explain>
        <SecondIndentExplain>
          <InlineLinkText href="#">Trash-Fi</InlineLinkText>
        </SecondIndentExplain>
        <Explain>두번째 아이디어톤 진행 (2022/3/20 - 202/3/26)</Explain>
        <SecondIndentExplain>
          <InlineLinkText href="#">Trash-Fi1</InlineLinkText>
        </SecondIndentExplain>
        <Explain>세번째 아이디어톤 진행 (2022/3/20 - 202/3/26)</Explain>
        <SecondIndentExplain>
          <InlineLinkText href="#">Trash-Fi2</InlineLinkText>
        </SecondIndentExplain>
      </Styled.ExperienceCardExplainContainer>
    </Styled.ExperienceCard>
  );
};

export default LikeLion;
