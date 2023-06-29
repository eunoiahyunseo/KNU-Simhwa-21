import React, { useState } from "react";
import styled, { css } from "styled-components";
import ReactCardFlip from "react-card-flip";
import * as Styled from "./style";
import RedPoint from "#/components/RedPoint";

import GitHubIcon from "@mui/icons-material/GitHub";
import EmailIcon from "@mui/icons-material/Email";
import PublicIcon from "@mui/icons-material/Public";

import CallIcon from "@mui/icons-material/Call";

import Tilt from "react-parallax-tilt";

const GitHubIconContainer = styled(GitHubIcon)`
  font-size: large;
  margin-right: 10px;
`;

const EmailIconContainer = styled(EmailIcon)`
  font-size: large;
  margin-right: 10px;
`;

const PublicIconContainer = styled(PublicIcon)`
  font-size: large;
  margin-right: 10px;
`;

const CallIcon_ = styled(CallIcon)`
  font-size: large;
  margin-right: 10px;
`;

const CallIconContainer = styled.div`
  display: flex;
  justify-content: center;
`;

const MyProduceCard = () => {
  const [isFlipped, setFlipped] = useState(false);

  return (
    <>
      <Tilt
        perspective={1000}
        glearEnable={true}
        glearMaxOpacity={0.8}
        scale={1.12}
        tiltReverse={true}
        glareColor="#ffffff"
        glarePosition="bottom"
        glareBorderRadius="20px"
      >
        <ReactCardFlip
          isFlipped={isFlipped}
          flipDirection="horizontal"
          flipSpeedBackToFront={1}
          flipSpeedFrontToBack={1}
        >
          <Styled.CardContainer onClick={() => setFlipped((prev) => !prev)}>
            <Styled.FrontCardMainPart>
              <Styled.FrontCardName>
                이현서
                <RedPoint>.</RedPoint>
              </Styled.FrontCardName>
              <Styled.FrontCardSubNameContainer>
                <Styled.FrontCardSubName>
                  Junior
                  <RedPoint>.</RedPoint>
                </Styled.FrontCardSubName>

                <Styled.FrontCardSubName>
                  KNU
                  <RedPoint>.</RedPoint>
                </Styled.FrontCardSubName>
              </Styled.FrontCardSubNameContainer>
            </Styled.FrontCardMainPart>
            <Styled.FrontCardDivideVertical />
            <Styled.FrontCardSubPart>
              <Styled.FrontCardSubPartContainer>
                <Styled.FrontCardSubPartEleContainer>
                  <GitHubIconContainer />
                  <Styled.FrontCardSubPartElement href="#" target="_blank">
                    Github <RedPoint>.</RedPoint>
                  </Styled.FrontCardSubPartElement>
                </Styled.FrontCardSubPartEleContainer>
                <Styled.FrontCardSubPartEleContainer>
                  <PublicIconContainer />
                  <Styled.FrontCardSubPartElement href="#" target="_blank">
                    TiStory <RedPoint>.</RedPoint>
                  </Styled.FrontCardSubPartElement>
                </Styled.FrontCardSubPartEleContainer>
                <Styled.FrontCardSubPartEleContainer>
                  <PublicIconContainer />
                  <Styled.FrontCardSubPartElement href="#" target="_blank">
                    Velog <RedPoint>.</RedPoint>
                  </Styled.FrontCardSubPartElement>
                </Styled.FrontCardSubPartEleContainer>
                <Styled.FrontCardSubPartEleContainer>
                  <EmailIconContainer />
                  <Styled.FrontCardSubPartElement href="#" target="_blank">
                    heart2002101@knu.ac.kr <RedPoint>.</RedPoint>
                  </Styled.FrontCardSubPartElement>
                </Styled.FrontCardSubPartEleContainer>
              </Styled.FrontCardSubPartContainer>
            </Styled.FrontCardSubPart>
          </Styled.CardContainer>
          <Styled.CardContainer onClick={() => setFlipped((prev) => !prev)}>
            <Styled.BackCardNameType>FullStack Developer</Styled.BackCardNameType>
            <Styled.BackCardStrip />
            <Styled.BackCardNameContainer>
              <Styled.BackCardName>이현서</Styled.BackCardName>
              <CallIconContainer>
                <CallIcon_ /> 010-2488-4113
              </CallIconContainer>
            </Styled.BackCardNameContainer>
          </Styled.CardContainer>
        </ReactCardFlip>
      </Tilt>
    </>
  );
};

export default MyProduceCard;
