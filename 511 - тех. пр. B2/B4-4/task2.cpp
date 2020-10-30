#include "tasks.hpp"
#include <iostream>
#include <list>
#include "commands.hpp"

const int MIN_VAL = 1;
const int MAX_VAL = 20;
const size_t MAX_SIZE = 20;

void task2()
{
  std::list<int> int_list;
  int int_temp;

  while (std::cin >> int_temp)
  {
    if ((int_temp < MIN_VAL) || (int_temp > MAX_VAL))
    {
      throw std::out_of_range("ERROR! Value field error! Please use number (1, 20)!\n");
    }
    int_list.push_back(int_temp);
  }

  if (std::cin.bad())
  {
    throw std::ios_base::failure("ERROR! A serious exception occurred in the import stream (in task2)!\n");
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("ERROR! Data import is abnormal! Please use number (1, 20)!\n");
  }
  if (int_list.size() > MAX_SIZE)
  {
    throw std::invalid_argument("ERROR! Number of elements exceeds maximum 20!\n");
  }

  auto i = int_list.begin();
  auto j = std::prev(int_list.end());

  if (int_list.size() == 1)
  {
    std::cout << *i << "\n";
  }
  else
  {
    while (i != j)
    {
      std::cout << *i << " " << *j << " ";
      i++;
      if (i == j)
      {
        break;
      }
      j--;
    }
    if (int_list.size() % 2 == 1)
    {
      std::cout << *i;
    }
    std::cout << "\n";
  }
}
