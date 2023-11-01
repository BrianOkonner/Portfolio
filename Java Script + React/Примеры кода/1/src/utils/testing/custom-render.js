import { useMemo } from "react";
import { ThemeProvider } from "styled-components/macro";
import { render } from "@testing-library/react";
import userEvent from "@testing-library/user-event";

import { createTheme } from "utils/theme";

const AllTheProviders = ({ children }) => {
  const theme = useMemo(() => createTheme("dark"), []);

  return <ThemeProvider theme={theme}>{children}</ThemeProvider>;
};

export const customRender = (ui, options) => ({
  user: userEvent.setup(),
  ...render(ui, { wrapper: AllTheProviders, ...options }),
});
