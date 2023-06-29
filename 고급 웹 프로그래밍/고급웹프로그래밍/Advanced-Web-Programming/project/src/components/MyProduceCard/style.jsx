import styled from "styled-components";

export const CardContainer = styled.div`
  background-color: rgba(0, 0, 0, 0.8);
  /* margin: 80px auto 30px 120px; */
  width: 40vw;
  height: 300px;
  color: white;
  display: flex;
  justify-content: space-around;
  align-items: center;
  box-shadow: 0px 0px 15px 1px gray;
  margin: 0px auto;
  cursor: pointer;
  position: relative;
`;

export const FrontCardMainPart = styled.div`
  display: flex;
  flex-direction: column;
  justify-content: center;
  margin-left: 20px;
`;

export const FrontCardSubNameContainer = styled.div`
  display: flex;
  justify-content: space-between;
  margin-top: 10px;
  column-gap: 10px;
  color: #858585;
`;
export const FrontCardName = styled.div`
  color: inherit;
  font-size: 2.1rem;
  margin-bottom: 1px;
`;

export const FrontCardSubName = styled.div`
  color: inherit;
  font-size: 0.85rem;
`;

export const FrontCardDivideVertical = styled.div`
  height: 80%;
  background-color: #ff3a4a;
  width: 3px;
`;

export const FrontCardSubPart = styled.div`
  display: flex;
`;

export const FrontCardSubPartContainer = styled.div`
  display: flex;
  flex-direction: column;
  row-gap: 10px;
`;

export const FrontCardSubPartEleContainer = styled.div`
  display: flex;
  justify-content: flex-start;
  text-align: left;
`;

export const FrontCardSubPartElement = styled.a`
  font-size: 1rem;
  text-decoration: none;
  position: relative;
  padding-bottom: 2px;
  overflow: hidden;

  :after {
    content: "";
    display: block;
    position: absolute;
    width: 100%;
    height: 2px;
    left: -100%;
    bottom: 0px;
    background: rgba(255, 218, 55, 0.9);
    transition: all 0.25s ease;
  }

  :hover {
    color: #858585;
    cursor: pointer;
  }

  :hover {
    :after {
      left: 0px;
    }
  }
`;

export const BackCardNameType = styled.div`
  color: inherit;
  position: absolute;
  font-size: 1.5rem;
  top: 19px;
  left: 40px;
`;

export const BackCardStrip = styled.div`
  position: absolute;
  background-color: #ff3a4a;
  height: 8px;
  width: 100%;
  bottom: 30px;
`;

export const BackCardName = styled.div`
  color: inherit;
  font-size: 1.3rem;
  margin: 2px;
  text-align: right;
`;

export const BackCardNameContainer = styled.div`
  display: flex;
  flex-direction: column;
  row-gap: 10px;
  position: absolute;
  bottom: 50px;
  right: 20px;
`;
