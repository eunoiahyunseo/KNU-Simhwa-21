import React from "react";
import styled from "styled-components";
import Responsive from "./Responsive";
import Button from "./Button";
import { Link } from "react-router-dom";

const HeaderBlock = styled.div`
  width: 100%;
  position: fixed;
  box-shadow: 0px 2px 4px rgba(0, 0, 0, 0.08);
  z-index: 100;
  background: rgba(255, 255, 255, 0.8);
`;

/**
 * Responsive 컴포넌트의 속성에 스타일을 추가해서 새로운 컴포넌트 생성
 */
const Wrapper = styled(Responsive)`
  height: 4rem;
  display: flex;
  align-items: center;
  justify-content: space-between;

  a {
    text-decoration: none;
  }

  .logo {
    font-size: 1.125rem;
    font-weight: 800;
    letter-spacing: 2px;
    color: black;
    margin-left: 60px;
  }

  .right {
    display: flex;
    align-items: center;
  }
`;

/**
 * 헤더가 fixed로 되어 있기 때문에 페이지의 콘텐츠가 4rem아래에 나타나도록 해 주는 콘텐츠
 */
const Spacer = styled.div`
  height: 4rem;
`;

const UserInfo = styled.div`
  font-weight: 800;
  margin-right: 1rem;
`;

const Header = ({ user, onLogout }) => {
  return (
    <>
      <HeaderBlock>
        <Wrapper>
          <Link to="/" className="logo">
            STUIK &#40; Study In Kert &#41;
          </Link>
          {user ? (
            <div className="right">
              <UserInfo>{user.username}</UserInfo>
              <Button onClick={onLogout}>로그아웃</Button>
            </div>
          ) : (
            <div className="right">
              <Button to="/login">로그인</Button>
            </div>
          )}
        </Wrapper>
      </HeaderBlock>
      <Spacer />
    </>
  );
};

export default Header;
