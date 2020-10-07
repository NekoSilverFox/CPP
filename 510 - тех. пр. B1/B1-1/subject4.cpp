#include "statement.hpp"
#include <random>

void initArray(double* array, int size)
{
  std::random_device rd; //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_real_distribution<> distr(-1.0, 1.0);

  for (int i = 0; i < size; i++)
  {
    array[i] = distr(gen);
  }
}

void subject4(const char* sort_type, const char* array_size)
{
  int size = atoi(array_size);

  if (size == 0)
  {
    throw std::invalid_argument("ERROR! Wrong size of this array!\n");
  }

  std::vector<double> vec(size);
  initArray(&vec[0], size);

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
    throw std::invalid_argument("ERROR! Wrong sort type parameter!\n");
  }

  jianing::printData<std::vector<double> >(vec);
  jianing::bubbleSort<jianing::bracketAccess, std::vector<double> >(vec, comp_method);
  jianing::printData<std::vector<double> >(vec);
}
