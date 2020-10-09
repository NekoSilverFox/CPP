#include "allSubjects.hpp"
#include "statement.hpp"

void jianing::subject4(const char* sort_type, const char* array_size)
{
  int size = atoi(array_size);

  if (size == 0)
  {
    throw std::invalid_argument("ERROR! Wrong size of this array, need greater than zero!\n");
  }

  std::vector<double> vec(size);
  initArray(&vec[0], size);

  bool (*comp_method)(double&, double&) = nullptr;

  if (std::strcmp(sort_type, "ascending") == 0)
  {
    comp_method = greater;
  }
  else if (std::strcmp(sort_type, "descending") == 0)
  {
    comp_method = less;
  }
  else
  {
    throw std::invalid_argument("ERROR! Wrong sort type parameter, please input [ascending] or [descending]!\n");
  }

  printData<std::vector<double> >(vec);
  bubbleSort<bracketAccess, std::vector<double> >(vec, comp_method);
  printData<std::vector<double> >(vec);
}
