import styled from "styled-components/macro";

export const Container = styled.main`
  background-color: ${({ theme }) => theme.background.default};
  color: ${({ theme }) => theme.text.primary};
  padding: 16px 32px;
`;
