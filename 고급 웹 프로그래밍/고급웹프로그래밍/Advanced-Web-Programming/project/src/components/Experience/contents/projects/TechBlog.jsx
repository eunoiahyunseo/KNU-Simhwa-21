import React from "react";
import * as Styled from "../../styled";

import { Explain, ExperienceCardTitle, Links, Skills } from "../../common";

import EXPLAIN from "./explains";

const LINKS = [
  {
    text: "이현서 기술 블로그",
    href: "https://hyunseo-fullstackdiary.tistory.com",
  },
  {
    text: "이현서 기술 블로그2",
    href: "https://hyunseo-fullstackdiary.tistory.com",
  },
];

const SKILLS = [
  {
    skill: "React",
    explain: EXPLAIN.react,
    image: {
      src: "/react.png",
      alt: "react image",
    },
  },
  {
    skill: "Next.JS",
    explain: EXPLAIN.nextjs,
    image: {
      src: "/next.png",
      alt: "next image",
    },
  },
  {
    skill: "Emotion",
    explain:
      "CSS-in-JS를 사용한 이유는 블로그에는 빠른 유저 인터렉션을 요구하는 애니메이션이 많이 있지 않고, 같은 JS로 개발할 수 있다는 점 그리고 className을 신경쓰지 않아도 된다는 점과 같은 것들로 인해 사용하게 되었습니다.\n\nNext.JS에서 styled-components를 사용하면 추가적으로 SSR과 관련하여 처리를 해주어야 하는데, emotion은 추가적인 설정이 필요없어서 emotion을 선택했습니다.\n\n그리고 styled-components와 비교해 번들 사이즈가 비슷하고, 추가적으로 사용할 수 있는 기능(emotion/css)이 있다는 것이 styled-components 대신에 emotion을 사용한 이유입니다.",
    image: {
      src: "/emotion.png",
      alt: "emotion image",
    },
  },
  {
    skill: "Chakra UI",
    explain: `NextJS + 다크모드를 구현할 때 편리한 기능들(system prefer color scheme, ColorModeScript등등)을 제공해줍니다. 커스터마이징이 가능한 컴포넌트를 제공해주고, 호불호가 크게 갈리지 않는 디자인이라서 적용했습니다.`,
  },
  {
    skill: "ESLint",
    explain: EXPLAIN.eslint,
  },
  {
    skill: "Prettier",
    explain: EXPLAIN.prettier,
  },
  {
    skill: "Vercel",
    explain: EXPLAIN.vercel,
  },
];

const TechBlog = () => {
  return (
    <Styled.ExperienceCard>
      <Styled.ExperienceCardTitleType>개인 프로젝트</Styled.ExperienceCardTitleType>
      <ExperienceCardTitle title="이현서 기술 블로그" id="techblog" />
      <Styled.ExperienceCardPeriod>2021년 3월 - current</Styled.ExperienceCardPeriod>
      <Styled.ExperienceCardExplainContainer>
        <Explain>나만의 블로그를 통해서 TIL을 실천하기 위함</Explain>
        <Explain>SoftWare MaeStro를 위한 Java Algorithm</Explain>
        <Explain>웹 개발을 위한 React.js, Next.js 기술들</Explain>
        <Explain>서버 운영을 위한 Docker, Kubernetes 기술</Explain>
        <Explain>자기 자신을 되돌아 보기 위한 회고록</Explain>
      </Styled.ExperienceCardExplainContainer>
      <Links links={LINKS} />
      <Skills skills={SKILLS} />
    </Styled.ExperienceCard>
  );
};

export default TechBlog;
