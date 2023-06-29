/* eslint-disable jsx-a11y/anchor-is-valid */
import React from "react";
import styled from "styled-components";
import Responsive from "./Responsive";
import ArticleIcon from "@mui/icons-material/Article";
import styles from "./common.module.scss";
import { Link } from "react-router-dom";

const NavBarContainer = styled.div`
  position: fixed;
  height: 100%;
  width: 15rem;
  background: rgb(30, 35, 39);
  left: -15rem;
  transition: all 0.5s ease;
  top: 4rem;
  display: flex;
  flex-direction: column;
  align-items: center;
  z-index: 102;
`;

const Wrapper = styled(Responsive)`
  height: auto;
  width: 100%;
  color: #a7adb2;
  padding: 20px 20px;
  background: rgb(44, 50, 56);
  font-size: 1.2rem;

  a {
    transition: all 0.5s ease;
    font-weight: 700;
  }

  div + div {
    margin-top: 23px;
  }

  a:hover {
    color: white;
    text-decoration: underline;
    text-underline-offset: 4px;
    cursor: pointer;
  }
`;

const Wrapper2 = styled(Responsive)`
  height: auto;
  width: 100%;
  color: white;
  padding: 20px 20px;
  font-size: 1.1rem;
  flex-grow: 1;
  display: flex;
  flex-direction: column;
  align-items: center;
`;

const ContentWithIcon = ({
  IconComponent,
  text,
  children,
  ...rest
}) => {
  return (
    <div {...rest} className={styles.iconOuter}>
      <IconComponent style={{ fontSize: 20 }} />
      <span>{text}</span>
      {children}
    </div>
  );
};

const MenuButton = () => {
  return (
    <>
      <input type="checkbox" id="menuicon" />
      <label htmlFor="menuicon">
        <span></span>
        <span></span>
        <span></span>
      </label>
    </>
  );
};

const NavBar = ({ navItemList, isLoggedIn, onLogout, user }) => {
  return (
    <>
      <MenuButton />
      <NavBarContainer>
        {navItemList.map((item) => {
          if (item === "HomePage") {
            return (
              <Wrapper key={item}>
                <Link to="/">홈</Link>
              </Wrapper>
            );
          } else if (isLoggedIn && item === "MyPost") {
            return (
              <Wrapper key={item}>
                <Link to={`/?username=${user?.username}`}>
                  내 스터디 확인하기
                </Link>
              </Wrapper>
            );
          } else if (isLoggedIn && item === "EditProfile") {
            return (
              <Wrapper key={item}>
                <Link to="/profile">프로필 수정</Link>
              </Wrapper>
            );
          } else if (!isLoggedIn && item === "Login") {
            return (
              <Wrapper key={item}>
                <Link to="/login">로그인</Link>
              </Wrapper>
            );
          } else if (!isLoggedIn && item === "Register") {
            return (
              <Wrapper key={item}>
                <Link to="/register">회원가입</Link>
              </Wrapper>
            );
          } else if (isLoggedIn && item === "Logout") {
            return (
              <Wrapper key={item}>
                <a
                  onClick={onLogout}
                  style={{ cursor: "pointer" }}
                >
                  로그아웃
                </a>
              </Wrapper>
            );
          }
          return null;
        })}
        <Wrapper2>
          <ContentWithIcon
            text={"Study"}
            IconComponent={ArticleIcon}
          />
        </Wrapper2>
      </NavBarContainer>
    </>
  );
};

export default NavBar;
