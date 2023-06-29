const pixelToRem = (size) => `${size / 16}rem`;

const size = {
  mobile: pixelToRem(600),
  desktop: pixelToRem(1080),
};

const theme = {
  mobile: `screen and (max-width: ${size.mobile})`,
  tablet: `screen and (max-width: ${size.desktop})`,
  desktop: `screen and (min-width: ${size.desktop})`,
};

export { theme };
