#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Error: invalid number of arguments" << std::endl;
    return EXIT_FAILURE;
  }

  try {
    RPN rpn;
    std::cout << rpn.calc(argv[1]) << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
