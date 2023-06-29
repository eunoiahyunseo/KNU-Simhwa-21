import React from "react";
import styled from "styled-components";
import { Link } from "react-router-dom";
import palette from "../../lib/styles/palette";
import styles from "./auth.module.scss";

import EmailIcon from "@mui/icons-material/Email";
import HttpsIcon from "@mui/icons-material/Https";

import Button from "../common/Button";

/**
 * 에러를 보여주기 위한 컴포넌트 입니다.
 */

const ErrorMessage = styled.div`
  color: red;
  text-align: center;
  font-size: 0.6124rem;
  margin-top: 0.3rem;
  font-weight: 700;
`;

/**
 * 회원가입과 로그인 폼을 보여주는 컴포넌트 입니다.
 */
const AuthFormContainer = styled.div``;

const StyledInput = styled.input.attrs((props) => ({}))`
  font-size: 10px;
  background-color: white;
  padding: 10px 20px;
  border: 1px solid ${palette.gray[4]};
  border-radius: 10px;
  padding-left: 30px;
  width: 100%;
  color: ${palette.gray[9]};
  outline: none;
  transition: all 0.5s ease;
`;

const EmailComponent = styled(EmailIcon)`
  position: absolute;
  color: rgb(52, 155, 235);
  display: flex;
  justify-content: center;
  align-items: center;
  margin-left: 8px;
`;

const PasswordComponent = styled(HttpsIcon)`
  position: absolute;
  color: rgb(52, 155, 235);
  display: flex;
  justify-content: center;
  align-items: center;
  margin-left: 8px;
`;

const StyledInputWithIconContainer = styled.div`
  position: relative;
  display: flex;
  align-items: center;
  width: 100%;
`;

const StyledInputLabel = styled.label`
  position: absolute;
  font-size: 10px;
  display: flex;
  align-items: center;
  justify-content: center;
  left: 32px;
  font-size: 8px;
  color: ${palette.gray[5]};
  transition: all 1s ease;
`;

const StyledInputWithIcon = ({
  label,
  IconComponent,
  ...rest
}) => {
  return (
    <StyledInputWithIconContainer
      className={styles.styledinputWithIcon}
    >
      <IconComponent style={{ fontSize: 16 }} />
      <StyledInput className={styles.styledinput} {...rest} />
      <StyledInputLabel
        htmlfor={rest.name}
        className={styles.styledlabel}
      >
        <span>{label}</span>
      </StyledInputLabel>
    </StyledInputWithIconContainer>
  );
};

const FormContainer = styled.form`
  display: flex;
  flex-direction: column;
  row-gap: 10px;
`;

const ButtonMarginTop = styled(Button)`
  margin-top: 1rem;
`;

const Footer = styled.div`
  margin-top: 1.4rem;
  text-align: right;
  font-size: 10px;

  a {
    color: ${palette.gray[6]};
    text-decoration: none;
    &:hover {
      color: ${palette.gray[9]};
    }
  }
`;

const TitleOfPage = styled.div`
  text-align: right;
  font-size: 14px;
  margin-bottom: 10px;
  color: ${palette.gray[6]};
`;

const textDictionary = {
  login: "login",
  register: "register",
};

const AuthForm = ({ type, form, onChange, onSubmit, error }) => {
  const typeofText = textDictionary[type];

  return (
    <AuthFormContainer>
      <TitleOfPage>{textDictionary[type]}</TitleOfPage>
      <FormContainer onSubmit={onSubmit}>
        <div
          style={{
            display: "flex",
            flexDirection: "column",
            rowGap: "20px",
          }}
        >
          <StyledInputWithIcon
            authComplete="email"
            name="email"
            IconComponent={EmailComponent}
            label="Email"
            value={form.email}
            onChange={onChange}
            required
          />
          <StyledInputWithIcon
            authComplete="password"
            type="password"
            IconComponent={PasswordComponent}
            name="password"
            label="Password"
            value={form.password}
            onChange={onChange}
            required
          />
          {type === "register" && (
            <StyledInputWithIcon
              authComplete="newpassword"
              password
              type="password"
              IconComponent={PasswordComponent}
              label="check password"
              value={form.passwordConfirm}
              name="passwordConfirm"
              onChange={onChange}
              required
            />
          )}
        </div>
        {error && <ErrorMessage>*{error}*</ErrorMessage>}
        <ButtonMarginTop cyan fullWidth>
          {typeofText}
        </ButtonMarginTop>
      </FormContainer>
      <Footer>
        {type === "login" ? (
          <Link to="/register">register</Link>
        ) : (
          <Link to="/login">login</Link>
        )}
      </Footer>
    </AuthFormContainer>
  );
};

export default AuthForm;
