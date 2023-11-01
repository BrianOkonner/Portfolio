import styled from "styled-components/macro";

export const Container = styled.div`
  display: flex;
  flex-direction: column;
  flex: 1;
  margin: auto;
  max-width: 500px;
`;

export const SubTitle = styled.p`
  color: ${({ theme }) => theme.text.secondary};
  font-size: 18px;
  align-self: center;
`;

export const Title = styled.h1`
  font-size: 24px;
  text-align: center;
`;