#include "statement.hpp"

void subject3()
{
  std::vector<int> vec;
  int num = 1;

  /*
  ** input number into the vector
  */
  while (std::cin >> num)
  {
    vec.push_back(num);
  }

  /*
  ** check
  */
  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::invalid_argument("ERROR! Input type must be integer!\n");
  }

  if (vec.empty())
  {
    exit(0);
  }

  if (vec.back() != 0)
  {
    throw std::invalid_argument("ERROR! Input should end with zero!");
  }
  else
  {
    vec.pop_back();
  }

  std::vector<int>::iterator iter = vec.begin();

  /*
  ** Start operation
  */
  if (vec.back() == 1)
  {
    for (; iter != vec.end(); iter++)
    {
      if (*iter % 2 == 0)
      {
        iter = vec.erase(iter);
        --iter;
      }
    }
  }
  else if (vec.back() == 2)
  {
    for (; iter != vec.end(); iter++)
    {
      if (*iter % 3 == 0)
      {
        ++iter;
        iter = vec.insert(iter, 3, 1);
        iter += 3; // x x x 3 1 1 @ x x (+3)
        --iter;
      }
    }
  }

  jianing::printData(vec);
}
