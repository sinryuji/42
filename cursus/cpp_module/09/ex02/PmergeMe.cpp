#include "PmergeMe.hpp"

/*
 * -------------------------- Constructor --------------------------
 */

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& origin) {
  (void)origin;
}

/*
 * -------------------------- Destructor ---------------------------
 */

PmergeMe::~PmergeMe(void) {}

/*
 * -------------------------- Operator -----------------------------
 */

PmergeMe& PmergeMe::operator=(const PmergeMe& origin) {
  if (this != &origin) {}
  return *this;
}

/*
 * ----------------------- Member Function -------------------------
 */

void PmergeMe::sort(char** argv) {
  std::deque<int> d;
  std::vector<int> v;

  parseContainer(d, argv);
  parseContainer(v, argv);
  std::cout << "Before:  ";
  printContainer(d);

  clock_t start_deque = clock();
  sortContainer(d, 0, d.size() - 1);
  clock_t finish_deque = clock();
  clock_t start_vector = clock();
  sortContainer(v, 0, v.size() - 1);
  clock_t finish_vector = clock();
  std::cout << "After:   ";
  printContainer(d);
  if (!isSorted(d))
    std::cout << "deque is not sorted" << std::endl;
  else
    std::cout << "deque is sorted" << std::endl;
  if (!isSorted(v))
    std::cout << "vector is not sorted" << std::endl;
  else
    std::cout << "vector is sorted" << std::endl;
  std::cout << "Time to process a range of " << d.size() << " elements with std::[deque] : " << (double)(finish_deque - start_deque) / 1000 << " us" << std::endl;
  std::cout << "Time to process a range of " << v.size() << " elements with std::[vector] : " << (double)(finish_vector - start_vector) / 1000  << " us" << std::endl;
}

void PmergeMe::validateInput(std::string input) {
  for (size_t i = 0; input[i]; i++) {
    if (!std::isdigit(input[i]))
      throw std::invalid_argument("invalid argument => " + input);
  }
  long tmp = std::atol(input.c_str());
  if (tmp > std::numeric_limits<int>::max())
    throw std::invalid_argument("input is greater than max value of int => " + input);
}
