import styled from "styled-components/macro";

export const Container = styled.div`
  align-items: center;
  cursor: pointer;
  display: flex;
  justify-content: space-between;
  margin: 4px 0;
  padding: 4px;
  border: 2px solid ${({ theme }) => theme.primary.dark};

`;

export const Content = styled.div`
  align-items: center;
  display: flex;
  flex: 1;
  flex-direction: column;
  
`;
export const Image = styled.img`
  align-self: center;
  height: 441px;
  width: 345px;
`;

export const Text = styled.p`
  margin: 8px;
  user-select: none;
  font-size: 24px;
  align-items: center;
  
`;