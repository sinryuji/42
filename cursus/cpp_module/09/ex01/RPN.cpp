#include "RPN.hpp"

/*
 * -------------------------- Constructor --------------------------
 */

RPN::RPN(void) {}

RPN::RPN(const RPN& origin) {
  (void)origin;
}

/*
 * -------------------------- Destructor ---------------------------
 */

RPN::~RPN(void) {}

/*
 * -------------------------- Operator -----------------------------
 */

RPN& RPN::operator=(const RPN& origin) {
  if (this != &origin) {}
  return *this;
}

/*
 * ----------------------- Member Function -------------------------
 */

int RPN::calc(std::string input) {
  std::stack<int> s;

  for (size_t i = 0; i < input.length(); i++) {
    if (!validateInput(input[i])) {
      std::string str(1, input[i]);
      throw std::invalid_argument("invalid input => " + str);
    }
    if (std::isdigit(input[i]))
      s.push(input[i] - '0');
    if (isOperator(input[i])) {
      if (s.size() < 2)
        throw std::invalid_argument(k_exp_err_msg);
      s.push(calcOp(ft_pop(s), ft_pop(s), input[i]));
    }
  }
  if (s.size() != 1)
    throw std::invalid_argument(k_exp_err_msg);
  return ft_pop(s);
}

bool RPN::validateInput(char c) {
  if (!(isOperator(c) || std::isdigit(c) || std::isspace(c)))
    return false;
  return true;
}

bool RPN::isOperator(char c) {
  if (!(c == '+' || c == '-' || c == '*' || c == '/'))
    return false;
  return true;
}

int RPN::calcOp(int a, int b, char op) {
  if (op == '+')
    return b + a;
  if (op == '-')
    return b - a;
  if (op == '*')
    return b * a;
  return b / a;
}

int RPN::ft_pop(std::stack<int>& s) {
  if (s.empty())
    throw std::invalid_argument(k_exp_err_msg);
  int ret = s.top();
  s.pop();
  return ret;
}
