import styled from "styled-components";

export const Button = styled.button`
  position: fixed;
  right: 0;
  bottom: 0;
  background-color: #efefef;
  border-radius: 10px;
  border: none;
  z-index: 100;
  margin: 20px;
  padding-top: 5px;
  transition: all 0.3s ease;

  :hover {
    cursor: pointer;
    background-color: #c7c7c7;
  }
`;
