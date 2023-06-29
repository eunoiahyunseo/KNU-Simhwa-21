import React, { useEffect, useState } from "react";
import styled from "styled-components";
import Responsive from "../common/Responsive";
import palette from "../../lib/styles/palette";
import Button from "../common/Button";
import AskConfirmModal from "./AskConfirmModal";

const OuterContainer = styled.div`
  margin-top: 60px;
`;

const EditProfileBlock = styled(Responsive)`
  display: flex;
  flex-direction: column;
  align-items: space-between;
  row-gap: 60px;
  padding: 0px 40px;
  position: relative;
`;

const SubInfo = styled.div`
  position: absolute;
  top: -15px;
  left: 50%;
  transform: translateX(-50%);
  background: white;
  padding: 5px 10px;
  border: 1px solid black;
  border-radius: 10px;
`;

const FormContainer = styled.form`
  border: 0.5px solid black;
  border-radius: 0.5rem;
  padding: 20px;
  height: 250px;
  width: 100%;
  border-radius: 0.5rem;
  position: relative;
  display: flex;
  flex-direction: column;
  box-shadow: 0px 2px 10px 10px #eee;
`;

const CheckContainer = styled.div`
  border: 0.5px solid black;
  border-radius: 0.5rem;
  padding: 20px;
  height: 250px;
  width: 100%;
  box-shadow: 0px 2px 10px 10px #eee;
  position: relative;
  display: flex;
`;

const HeadTitle = styled.div`
  text-align: center;
  font-size: 2rem;
  color: ${palette.gray[7]};
  margin-bottom: 30px;
`;

const CheckTable = styled.table`
  border: 1px solid black;
  border-collapse: collapse;
  width: 90%;
  margin: auto;

  td {
    border: 1px solid black;
    padding: 10px;

    &.info {
      padding: 15px 20px;
      background-color: ${palette.gray[4]};
    }
  }
`;

const StyledInput = styled.input`
  width: 100%;
  height: 100%;
  padding: 10px;
  &:focus {
    outline: 2px solid ${palette.cyan[3]};
  }
`;

const ButtonContainer = styled.div`
  display: flex;
  justify-content: center;
  column-gap: 20px;
  position: absolute;
  bottom: 3%;
  left: 50%;
  transform: translateX(-50%);
`;

const ErrorMessage = styled.div`
  color: red;
  font-size: 0.8rem;
  text-align: center;
  position: relative;
  top: 30px;
`;

const EditProfile = ({
  user,
  onChangeField,
  profile,
  onConfirm,
  onBackClick,
  errorMessage,
}) => {
  // 현재 user의 profile을 바꾸는 것이다. username을 바꿀 수 있으려면
  // 현재의 user를 참조할 수 있어야 한다.
  const { email, username } = user;
  let { email: profileEmail, username: profileUserName } =
    profile;

  const onChange = (e) => {
    const {
      target: { value, name },
    } = e;
    onChangeField({ key: name, value });
  };

  useEffect(() => {
    const { email, username } = user;
    const email_ = email || "";
    const username_ = username || "";
    onChangeField({ key: "email", value: email_ });
    onChangeField({ key: "username", value: username_ });
  }, [email, onChangeField, user]);

  const [modal, setModal] = useState(false);

  const onConfirmClick = () => {
    setModal(true);
  };

  const onCancelModal = () => {
    setModal(false);
  };

  const onConfirmModal = () => {
    setModal(false);
    onConfirm();
  };

  return (
    <OuterContainer>
      <HeadTitle>프로필 정보</HeadTitle>
      <EditProfileBlock>
        <CheckContainer>
          <SubInfo>프로필 확인</SubInfo>
          <CheckTable>
            <tbody>
              <tr>
                <td className="info">email</td>
                <td>{email}</td>
              </tr>
              <tr>
                <td className="info">username</td>
                <td>{username}</td>
              </tr>
            </tbody>
          </CheckTable>
        </CheckContainer>
        <FormContainer>
          <SubInfo>프로필 수정</SubInfo>
          <ErrorMessage>{errorMessage}</ErrorMessage>

          <CheckTable>
            <tbody>
              <tr>
                <td className="info">email</td>
                <td>
                  <StyledInput
                    disabled
                    value={profileEmail}
                    name="email"
                    onChange={onChange}
                    placeholder={email}
                  />
                </td>
              </tr>
              <tr>
                <td className="info">username</td>
                <td>
                  <StyledInput
                    name="username"
                    value={profileUserName}
                    onChange={onChange}
                    placeholder={username}
                  />
                </td>
              </tr>
            </tbody>
          </CheckTable>
        </FormContainer>
        <ButtonContainer>
          <Button cyan onClick={onConfirmClick}>
            확인
          </Button>
          <Button cyan onClick={onBackClick}>
            뒤로가기
          </Button>
        </ButtonContainer>
      </EditProfileBlock>
      <AskConfirmModal
        visible={modal}
        onConfirm={onConfirmModal}
        onCancel={onCancelModal}
      />
    </OuterContainer>
  );
};

export default EditProfile;
