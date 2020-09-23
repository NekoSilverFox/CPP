#include <vector>
#include "statement.hpp"

void subject3()
{
  std::vector<int> vec;
  int num = NULL;

  /*
  ** input number into the vector
  */
  while (true)
  {
    std::cin >> num;

    if (num == 0)
    {
      break;
    }

    vec.push_back(num);
  }
  vec.push_back(0);

  /*
  ** check
  */
  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::invalid_argument("ERROR! Wrong input, because type must be integer!\n");
  }

  if (vec.empty())
  {
    exit(0);
  }

  if (vec.back() != 0)
  {
    throw std::invalid_argument("ERROR! Wrong input - expected zero before end of the input!\n");
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
        continue;
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
        continue;
      }
    }
  }

  jianing::printData(vec);
}
