import React from "react";
import useMediaQuery from "@mui/material/useMediaQuery";
import { FadeInContent } from "#/components/gsap";
import { ExperienceTitle } from "./common";
import TableOfContent from "../TableOfContents";
import * as Styled from "./styled";
import * as Content from "./contents";

import MyProduceCard from "../MyProduceCard";

const CONTENT_DELAY_TIME = 0.3;

const Experience = () => {
  const isOver1100px = useMediaQuery(`(min-width: 1100px)`);

  return (
    <Styled.Container>
      {isOver1100px && (
        <Styled.TableOfContent>
          <TableOfContent />
        </Styled.TableOfContent>
      )}
      <Styled.Contents>
        <Styled.ExperienceContainer>
          <FadeInContent delay={CONTENT_DELAY_TIME}>
            <ExperienceTitle title="Education" />
          </FadeInContent>

          <FadeInContent delay={CONTENT_DELAY_TIME}>
            <Content.University />
          </FadeInContent>

          <FadeInContent delay={CONTENT_DELAY_TIME}>
            <Content.Kert />
          </FadeInContent>

          <FadeInContent delay={CONTENT_DELAY_TIME}>
            <Content.LikeLion />
          </FadeInContent>
        </Styled.ExperienceContainer>

        <Styled.ExperienceContainer>
          <FadeInContent delay={CONTENT_DELAY_TIME}>
            <ExperienceTitle title="Project" />
          </FadeInContent>

          <FadeInContent delay={CONTENT_DELAY_TIME}>
            <Content.TechBlog />
          </FadeInContent>

          <FadeInContent delay={CONTENT_DELAY_TIME}>
            <Content.knuLocker />
          </FadeInContent>

          {isOver1100px && (
            <>
              <FadeInContent delay={CONTENT_DELAY_TIME}>
                <ExperienceTitle title="Contact" />
              </FadeInContent>
              <FadeInContent delay={CONTENT_DELAY_TIME}>
                <MyProduceCard />
              </FadeInContent>
            </>
          )}
        </Styled.ExperienceContainer>
      </Styled.Contents>
    </Styled.Container>
  );
};

export default Experience;
