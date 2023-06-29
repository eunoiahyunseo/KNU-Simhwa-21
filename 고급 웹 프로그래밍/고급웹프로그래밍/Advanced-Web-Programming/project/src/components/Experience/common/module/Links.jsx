import styled from "styled-components";
import LinkOutlinedIcon from "@mui/icons-material/LinkOutlined";

import { Explain, InlineLinkText } from "../index";

import {
  CommonArticleContainer,
  CommonArticleContainerTitle,
} from "#/components/Experience/styled";

const LinksContainer = styled.div`
  display: flex;
  flex-direction: column;
  row-gap: 7px;
`;

const Links = ({ links }) => {
  return (
    <CommonArticleContainer>
      <CommonArticleContainerTitle>
        <LinkOutlinedIcon />
        관련 링크들
      </CommonArticleContainerTitle>
      <LinksContainer>
        {links.map(({ text, href }, index) => (
          <Explain key={`${index + 1}-${text}`}>
            <InlineLinkText href={href}>{text}</InlineLinkText>
          </Explain>
        ))}
      </LinksContainer>
    </CommonArticleContainer>
  );
};

export default Links;
