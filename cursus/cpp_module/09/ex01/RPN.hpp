#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <stdexcept>
# include <cstdlib>

const static std::string k_exp_err_msg = "invalid polish mathematical expression";

class RPN {
  public:
    RPN(void);
    RPN(const RPN& origin);
    ~RPN(void);
    RPN& operator=(const RPN& origin);
    int calc(std::string input);

  private:
    bool validateInput(char c);
    bool isOperator(char c);
    int calcOp(int a, int b, char op);
    int ft_pop(std::stack<int>& s);
};

#endif
