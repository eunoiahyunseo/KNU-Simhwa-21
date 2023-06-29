import React from "react";
import * as Styled from "../../styled";
import {
  Explain,
  InlineLinkText,
  SecondIndentExplain,
  ExperienceCardTitle,
} from "../../common";

const Kert = () => {
  return (
    <Styled.ExperienceCard>
      <Styled.ExperienceCardTitleType>동아리</Styled.ExperienceCardTitleType>
      <ExperienceCardTitle
        image
        src="/kert.png"
        title="경북대 정보보안 연구회"
        id="kert"
      />
      <Styled.ExperienceCardPeriod>2021/3/12 - current</Styled.ExperienceCardPeriod>
      <Styled.ExperienceCardExplainContainer>
        <Explain>
          <InlineLinkText>정보보안 연구회 KERT</InlineLinkText>에서 주최
        </Explain>
        <Explain>부회장 (2022/3/20 - current)</Explain>
        <SecondIndentExplain>
          <InlineLinkText href="#">Trash-Fi1</InlineLinkText>
        </SecondIndentExplain>
        <Explain>다양한 스터디 진행 (2021/3/20 - current)</Explain>
        <SecondIndentExplain>
          <InlineLinkText href="#">개발 - 보안</InlineLinkText>
        </SecondIndentExplain>
        <Explain>기초보안 교육 (2022/4/20 - current)</Explain>
        <SecondIndentExplain>리눅스</SecondIndentExplain>
      </Styled.ExperienceCardExplainContainer>
    </Styled.ExperienceCard>
  );
};

export default Kert;
