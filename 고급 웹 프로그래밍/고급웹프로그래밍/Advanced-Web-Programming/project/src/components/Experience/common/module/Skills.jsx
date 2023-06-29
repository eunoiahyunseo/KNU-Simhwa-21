/* eslint-disable @next/next/no-img-element */
import * as React from "react";
import Accordion from "@mui/material/Accordion";
import AccordionSummary from "@mui/material/AccordionSummary";
import AccordionDetails from "@mui/material/AccordionDetails";
import Typography from "@mui/material/Typography";
import ExpandMoreIcon from "@mui/icons-material/ExpandMore";

import BorderColorOutlinedIcon from "@mui/icons-material/BorderColorOutlined";

import { CommonArticleContainer, CommonArticleContainerTitle } from "../../styled";

const Skills = ({ skills }) => {
  return (
    <CommonArticleContainer>
      <CommonArticleContainerTitle>
        <BorderColorOutlinedIcon />
        사용기술들
      </CommonArticleContainerTitle>
      {skills.map(({ skill, explain, image }, index) => (
        <Accordion key={`${index + 1}-${skill}`}>
          <AccordionSummary
            expandIcon={<ExpandMoreIcon />}
            aria-controls="panel1a-content"
            id="panel1a-header"
          >
            <Typography>{skill}</Typography>
          </AccordionSummary>
          <AccordionDetails>
            <Typography>{explain}</Typography>
          </AccordionDetails>
          {image ? (
            <AccordionDetails>
              <img
                style={{ width: "100%", objectFit: "contain" }}
                src={image.src}
                alt={image.alt}
              />
            </AccordionDetails>
          ) : null}
        </Accordion>
      ))}
    </CommonArticleContainer>
  );
};

export default Skills;
