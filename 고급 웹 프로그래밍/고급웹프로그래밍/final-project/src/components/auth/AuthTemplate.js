import React from "react";
import styled from "styled-components";
import palette from "../../lib/styles/palette";
import { Link } from "react-router-dom";

import KeyboardArrowDownIcon from "@mui/icons-material/KeyboardArrowDown";

/**
 * 회원가입/로그인 페이지의 레이아웃을 담당하는 컴포넌트 입니다.
 */

const AuthTemplateBlock = styled.div`
  position: absolute;
  left: 0;
  top: 0;
  bottom: 0;
  right: 0;
  display: flex;
  justify-content: center;
  align-items: center;
  background: ${palette.gray[2]};
`;

const PaddingBox = styled.div`
  box-shadow: 0 0 8px rgba(0, 0, 0, 0.025);
  border-radius: 2px;
  background: white;
  padding: 2rem;
  width: 360px;
  border-radius: 7px;
  .logo {
    display: flex;
    flex-direction: column;
    align-items: center;

    padding-bottom: 2rem;
    text-align: center;
    font-weight: bold;
    letter-spacing: 2px;
    a {
      color: black;
      text-underline-offset: 4px;
      &:hover {
        color: ${palette.cyan[9]};
      }
    }
  }
`;

const SubTitleOfPaddingBox = styled.p`
  font-size: 10px;
  letter-spacing: 1px;
  color: ${palette.gray[6]};
`;

const DownAnimatedArrow = styled(KeyboardArrowDownIcon)`
  display: block;
  margin-bottom: 20px;
  animation: bounce 1.5s ease infinite;
  color: black;

  @keyframes bounce {
    0%,
    20%,
    50%,
    80%,
    100% {
      transfrom: translateY(0);
    }

    40% {
      transform: translateY(-27%);
    }

    60% {
      transform: translateY(-10px);
    }
  }
`;

const AuthTemplate = ({ children }) => {
  return (
    <AuthTemplateBlock>
      <PaddingBox>
        <div className="logo">
          <DownAnimatedArrow />
          <Link to="/">Welcome Back</Link>
          <SubTitleOfPaddingBox>
            Enter your credentials to access your account.
          </SubTitleOfPaddingBox>
        </div>
        {children}
      </PaddingBox>
    </AuthTemplateBlock>
  );
};

export default AuthTemplate;
