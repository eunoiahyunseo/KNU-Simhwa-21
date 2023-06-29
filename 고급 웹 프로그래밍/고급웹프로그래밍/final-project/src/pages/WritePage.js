import React from "react";
import Responsive from "../components/common/Responsive";
import WriteActionButtonContainer from "../containers/write/WriteActionButtonsContainer";
import EditorContainer from "../containers/write/EditorContainer";
import TagBoxContainer from "../containers/write/TagBoxContainer";
import { useNavigate } from "react-router-dom";
import { Helmet } from "react-helmet-async";

const WritePage = () => {
  return (
    <Responsive>
      <Helmet>
        <title>Write - STUIK</title>
      </Helmet>
      <EditorContainer />
      <TagBoxContainer />
      <WriteActionButtonContainer navigate={useNavigate()} />
    </Responsive>
  );
};

export default WritePage;
