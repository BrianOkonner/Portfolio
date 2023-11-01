import { useMemo, useState } from "react";
import { Provider as StoreProvider } from "react-redux";
import { createGlobalStyle, ThemeProvider } from "styled-components/macro";

import Main from "pages/Main";
import { configureAppStore } from "store";
import { createTheme } from "utils/theme";

const GlobalStyle = createGlobalStyle`
  html, body {
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
    background-color: ${({ theme }) => theme.background.default};
    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Oxygen, Ubuntu, Cantarell,
      "Fira Sans", "Droid Sans", "Helvetica Neue", sans-serif;
    height: 100%;
    margin: 0;
  }
`;

const store = configureAppStore();

const App = () => {
  const [mode, setMode] = useState("dark");

  const toggleMode = () => {
    if (mode === "dark") {
      setMode("light");
    } else {
      setMode("dark");
    }
  };

  const theme = useMemo(() => createTheme(mode), [mode]);

  return (
    <StoreProvider store={store}>
      <ThemeProvider theme={theme}>
        <GlobalStyle />
        <Main toggleMode={toggleMode} />
      </ThemeProvider>
    </StoreProvider>
  );
};

export default App;
