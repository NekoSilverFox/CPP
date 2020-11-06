#include <iostream>
#include <algorithm>

#include "containerFactorial.hpp"

void task2()
{
  jianing::ContainerFactorial factorialContainer;

  std::copy(factorialContainer.begin(), factorialContainer.end(), std::ostream_iterator<long>(std::cout, " "));
  std::cout << "\n";

  std::reverse_copy(factorialContainer.begin(), factorialContainer.end(), std::ostream_iterator<long>(std::cout, " "));
  std::cout << "\n";

}
