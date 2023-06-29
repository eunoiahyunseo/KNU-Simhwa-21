import React from "react";
import { gsap } from "gsap";
import { ScrollTrigger } from "gsap/dist/ScrollTrigger";
import { CSSPlugin } from "gsap/CSSPlugin";
import { ThemeProvider } from "styled-components";

import GlobalStyle from "#/styles/globalStyles";
import { theme } from "#/styles/theme";

import smoothscroll from "smoothscroll-polyfill";

if (typeof window !== "undefined") {
  gsap.registerPlugin(CSSPlugin);
  gsap.registerPlugin(ScrollTrigger);
  smoothscroll.polyfill();
}

function MyApp({ Component, pageProps }) {
  return (
    <div>
      <ThemeProvider theme={theme}>
        <GlobalStyle />
        <Component {...pageProps} />
      </ThemeProvider>
    </div>
  );
}

export default MyApp;
