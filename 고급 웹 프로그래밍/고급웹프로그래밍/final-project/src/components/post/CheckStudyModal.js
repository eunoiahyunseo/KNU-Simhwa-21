import React from "react";
import AskModal from "../common/AskModal";

const CheckStudyModal = ({
  visible,
  onConfirm,
  description,
}) => {
  return (
    <AskModal
      visible={visible}
      onConfirm={onConfirm}
      description={description}
      confirmText="확인"
      title="스터디 인원 확인"
      checker
    />
  );
};

export default CheckStudyModal;
