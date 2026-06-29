#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Error: invalid number of arguments" << std::endl;
    return EXIT_FAILURE;
  }
  
  try {
    PmergeMe pm;
    pm.sort(++argv);
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
