#include <random>
#include <ctime>
#include <cstring>
#include "statement.hpp"

void fillRandom(double* array, int size)
{
  std::mt19937 Rng(time(NULL));
  std::uniform_real_distribution<double> distr(-1.0, 1.0);

  for (int i = 0; i < size; i++)
  {
    array[i] = distr(Rng);
  }
}

void subject4(const char* sort_type, const char* array_size)
{
  int size = atoi(array_size);

  if (size == 0)
  {
    throw std::invalid_argument("Wrong size of this array!\n");
  }

  std::vector<double> vec(size);
  fillRandom(&vec[0], size);

  bool (*comp_method)(double&, double&) = nullptr;

  if (std::strcmp(sort_type, "ascending") == 0)
  {
    comp_method = jianing::greater;
  }
  else if (std::strcmp(sort_type, "descending") == 0)
  {
    comp_method = jianing::less;
  }
  else
  {
    throw std::invalid_argument("Wrong sort type parameter!\n");
  }

  jianing::printData<std::vector<double> >(vec);
  jianing::bubbleSort<jianing::bracketAccess, std::vector<double>>(vec, comp_method);
  jianing::printData<std::vector<double> >(vec);
}
