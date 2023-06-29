/* eslint-disable @next/next/no-img-element */
import React from "react";
import { UNDER_LINE_COLOR } from "#/colors";

import * as Styled from "#/components/Introduce/styled";
import YellowPoint from "#/components/YellowPoint";
import {
  FadeInContent,
  Underline,
  FadeInBodyText,
  FadeInHeaderText,
} from "#/components/gsap";
import { LAST_UPDATED } from "#/constants";

const Introduce = () => {
  return (
    <Styled.Container>
      <FadeInContent delay={1}>
        <Styled.Sidebar>
          <Styled.LinkContainer>
            <Styled.Link href="#" target="_blank">
              <span>lorem ipsum</span>
              <YellowPoint>.</YellowPoint>
            </Styled.Link>
            <Styled.Link href="#" target="_blank">
              <span>GitHub</span>
              <YellowPoint>.</YellowPoint>
            </Styled.Link>
            <Styled.Link href="#" target="_blank">
              <span>Tistory Blog</span>
              <YellowPoint>.</YellowPoint>
            </Styled.Link>

            <Styled.Link href="#" target="_blank">
              <span>KNU</span>
              <YellowPoint>.</YellowPoint>
            </Styled.Link>
          </Styled.LinkContainer>

          <Styled.BottomContainer>
            <Styled.Email href="#">heart20021010@knu.ac.kr</Styled.Email>
            <Styled.LastUpdate>Last Update: {LAST_UPDATED}</Styled.LastUpdate>
          </Styled.BottomContainer>
        </Styled.Sidebar>
      </FadeInContent>

      <Styled.Main>
        <FadeInHeaderText delay={1.5}>
          <Styled.SubTitle>몰입하고, 협업하는 개발자</Styled.SubTitle>
        </FadeInHeaderText>

        <FadeInHeaderText delay={1.9}>
          <Styled.Title>
            <Underline color={UNDER_LINE_COLOR} delay={2.4}>
              이현서
            </Underline>
          </Styled.Title>
          <Styled.SubTitle>라고 합니다.</Styled.SubTitle>
        </FadeInHeaderText>

        <FadeInBodyText delay={2.6}>
          <Styled.BodyTextContainer>
            <Styled.BodyText>풀스택 개발자를 희망하고 있습니다.</Styled.BodyText>
            <Styled.BodyText>
              동기들과 배운 것을 나누고, 개발하는 것을 좋아합니다.
            </Styled.BodyText>
            <Styled.BodyText>
              정보를 나누고, 매 순간을 기록하며 자기계발을 합니다.
            </Styled.BodyText>
          </Styled.BodyTextContainer>
        </FadeInBodyText>

        <Styled.ImageBox>
          <img src="/hyunseo2.png" alt="hyunseo-background" />
        </Styled.ImageBox>

        <FadeInContent delay={3.5}>
          <Styled.DownAnimatedArrow fontSize="large" />
        </FadeInContent>
      </Styled.Main>
    </Styled.Container>
  );
};

export default Introduce;
