import Document, { Html, Head, Main, NextScript } from "next/document";
import { ServerStyleSheet } from "styled-components";
import { renderToString } from "react-dom/server";

class MyDocument extends Document {
  static async getInitialProps(ctx) {
    const initialProps = await Document.getInitialProps(ctx);
    const sheet = new ServerStyleSheet();
    const page = ctx.renderPage(
      (App) => (props) => sheet.collectStyles(<App {...props} />)
    );
    const styleTags = sheet.getStyleElement();
    return { ...initialProps, ...page, styleTags };
  }

  render() {
    return (
      <Html>
        <Head />
        <title>Hyunseo&apos;s Resume</title>
        {this.props.styleTags}
        <meta property="og:description" content="고웹프 프로젝트입니다."></meta>
        <meta
          property="op:image"
          content="https://github.com/LE123123/MyResumeProject/blob/main/public/hyunseo2.png?raw=true"
        ></meta>
        <meta property="og:type" content="website" />
        <meta property="og:title" content="이현서 포트폴리오" />
        <meta property="og:locale" content="ko" />
        <meta property="og:url" content="https://hyunseo-resume.vercel.app/" />
        <meta name="viewport" content="width=device-width, initial-scale=1"></meta>
        <link
          rel="stylesheet"
          href="https://fonts.googleapis.com/icon?family=Material+Icons"
        />
        <meta charSet="utf-8"></meta>
        <body className="bg-white">
          <Main />
          <NextScript />
        </body>
      </Html>
    );
  }
}

export default MyDocument;
