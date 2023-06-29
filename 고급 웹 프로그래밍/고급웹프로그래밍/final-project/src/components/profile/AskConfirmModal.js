import React from "react";
import AskModal from "../common/AskModal";

const AskConfirmModal = ({ visible, onConfirm, onCancel }) => {
  return (
    <AskModal
      visible={visible}
      onConfirm={onConfirm}
      onCancel={onCancel}
      description="정말로 프로필을 변경하시겠습니까?"
      confirmText="확인"
      title="프로필 변경"
    />
  );
};

export default AskConfirmModal;
