import React from "react";
import styled from "styled-components";

import CheckIcon from "@mui/icons-material/Check";

const ExplainContainer = styled.div`
  display: flex;
`;

const ExperienceCardExplain = styled.div`
  font-size: 20px;
`;

const ExplainCheckIcon = styled(CheckIcon)`
  margin-right: 10px;
  color: rgb(255, 174, 0);
`;

const Explain = ({ children }) => {
  return (
    <ExplainContainer>
      <ExplainCheckIcon />
      <ExperienceCardExplain>{children}</ExperienceCardExplain>
    </ExplainContainer>
  );
};

export default Explain;
