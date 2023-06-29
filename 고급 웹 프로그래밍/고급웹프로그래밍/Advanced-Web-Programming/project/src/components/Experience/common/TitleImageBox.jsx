import react from "react";
import * as Style from "../styled";

const ExperienceCardTitle = ({ image, src, title, id, children }) => {
  return (
    <Style.ExperienceCardTitleContainer>
      {image && src && <Style.ExperienceCardTitleImage src={src} alt="image" />}
      <Style.ExperienceCardTitle id={id}>
        {title ? title : children}
      </Style.ExperienceCardTitle>
    </Style.ExperienceCardTitleContainer>
  );
};

export default ExperienceCardTitle;
