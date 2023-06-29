import React from "react";
import * as Styled from "../../styled";

import {
  Explain,
  ExperienceCardTitle,
  Links,
  Skills,
  InlineLinkText,
} from "../../common";

import EXPLAIN from "./explains";

const LINKS = [
  {
    text: "knu locker apply server",
    href: "http://errdoc.gabia.net/503.html",
  },
];

const SKILLS = [
  {
    skill: "NodeJS",
    explain: EXPLAIN.nodejs,
    image: {
      src: "/nodejs.png",
      alt: "nodejs image",
    },
  },
  {
    skill: "Python",
    explain: EXPLAIN.python,
    image: {
      src: "/python.png",
      alt: "python image",
    },
  },
  {
    skill: "ESLint",
    explain: EXPLAIN.eslint,
  },
  {
    skill: "Prettier",
    explain: EXPLAIN.prettier,
  },
];

const knuLocker = () => {
  return (
    <Styled.ExperienceCard>
      <Styled.ExperienceCardTitleType>팀 프로젝트</Styled.ExperienceCardTitleType>
      <ExperienceCardTitle id="knulocker">
        <InlineLinkText href="#">Knu Locker</InlineLinkText>
      </ExperienceCardTitle>
      <Styled.ExperienceCardPeriod>
        2022년 1월 - 2022년 3월
      </Styled.ExperienceCardPeriod>
      <Styled.ExperienceCardExplainContainer>
        <Explain>NODE를 기반으로 서버 구축 계획</Explain>
        <Explain>DB설계와 python 알고리즘을 활용</Explain>
        <Explain>Gabia를 활용하여 배포하고, 전교생들에게 메일로 사물함 배정</Explain>
      </Styled.ExperienceCardExplainContainer>
      <Links links={LINKS} />
      <Skills skills={SKILLS} />
    </Styled.ExperienceCard>
  );
};

export default knuLocker;
