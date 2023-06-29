import React from "react";
import Head from "next/head";
import styled from "styled-components";
import Introduce from "#/components/Introduce";
import Experience from "#/components/Experience";
import Footer from "#/components/Footer";
import ScrollTopButton from "#/components/ScrollTopButton";

const Section = styled.section`
  position: relative;
  display: flex;
  flex-direction: column;
`;

export default function Home() {
  return (
    <>
      <main>
        <Section>
          <Introduce />
          <Experience />
          <Footer />
          <ScrollTopButton />
        </Section>
      </main>
    </>
  );
}
