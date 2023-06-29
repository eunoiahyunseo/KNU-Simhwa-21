import React from "react";
import AskModal from "../common/AskModal";

const AskRemoveModal = ({ visible, onConfirm, onCancel }) => {
  return (
    <AskModal
      visible={visible}
      onConfirm={onConfirm}
      onCancel={onCancel}
      description="정말 스터디를 삭제 하시겠습니까?"
      confirmText="삭제"
      title="스터디 삭제"
    />
  );
};

export default AskRemoveModal;
