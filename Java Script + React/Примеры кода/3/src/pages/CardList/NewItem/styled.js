import styled from "styled-components/macro";

export const AddButton = styled.button`
  background: none;
  border-radius: 6px;
  border: none;
  color: ${({ theme }) => theme.text.primary};
  cursor: pointer;
  font-size: 26px;
  padding: 8px 16px;
`;

export const Container = styled.div`
  display: flex;
  margin-top: 16px;
`;

export const Input = styled.input`
  background: none;
  border-radius: 6px;
  border: 1px solid ${({ theme }) => theme.divider};
  color: ${({ theme }) => theme.text.primary};
  display: flex;
  flex: 1;
  font-size: 20px;
  padding: 8px 16px;
  max-width: 200px;
`;

export const InputFile = styled.input`
  background: none;
  color: ${({ theme }) => theme.text.primary};
  display: flex;
  flex: 1;
  font-size: 16px;
  margin-left: 10px;
  padding: 2px 10px;
`;

export const MiniContainer = styled.div`
  display: flex;
  flex: 1;
  flex-direction: column;
  align-items: center;
`;