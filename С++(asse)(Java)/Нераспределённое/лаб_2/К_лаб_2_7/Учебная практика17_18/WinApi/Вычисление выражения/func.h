#ifndef FUNC_H
#define FUNC_H

#include <string>

const std::string OPERATORS = "+-*/^";
std::string toPosfix(std::string infix);
float compute(const std::string& str);

#endif