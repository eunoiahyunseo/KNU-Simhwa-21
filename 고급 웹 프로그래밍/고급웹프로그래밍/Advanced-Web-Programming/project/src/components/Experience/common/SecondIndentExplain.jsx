import React from "react";
import styled from "styled-components";
import FiberManualRecordOutlinedIcon from "@mui/icons-material/FiberManualRecordOutlined";

const ExplainContainer = styled.div`
  position: relative;
  left: 30px;
  display: flex;
`;

const ExpperienceCardExplain = styled.div`
  font-size: 1rem;
`;

const ExplainCircleIcon = styled(FiberManualRecordOutlinedIcon)`
  margin-right: 10px;
  color: rgb(255, 174, 0);
`;

const SecondIndentExplain = ({ children }) => {
  return (
    <ExplainContainer>
      <ExplainCircleIcon fontSize="small" />
      <ExpperienceCardExplain>{children}</ExpperienceCardExplain>
    </ExplainContainer>
  );
};

export default SecondIndentExplain;
