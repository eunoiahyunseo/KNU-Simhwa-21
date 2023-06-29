import React from "react";
import styled from "styled-components";
import Button from "../common/Button";

const WriteActionButtonsBlock = styled.div`
  margin: 1rem;
  button + button {
    margin-left: 0.5rem;
  }
`;

const StyledButton = styled(Button)`
  height: 2.1rem;
  & + & {
    margin-left: 0.5rem;
  }
`;

const WriteActionButtons = ({ onCancel, onPublish, isEdit }) => {
  return (
    <WriteActionButtonsBlock>
      <StyledButton cyan onClick={onPublish}>
        {isEdit ? "스터디 수정하기" : "스터디 등록하기"}
      </StyledButton>
      <StyledButton onClick={onCancel}>취소하기</StyledButton>
    </WriteActionButtonsBlock>
  );
};

export default WriteActionButtons;
