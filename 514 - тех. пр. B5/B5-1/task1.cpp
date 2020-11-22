#include <iostream>
#include <sstream>
#include <set>
#include <vector>

void task1()
{
  std::string line;
  std::set<std::string> words;

  while (std::getline(std::cin, line))
  {
    std::stringstream stream(line);
    std::string word;
    if (std::cin.fail()) 
    {
      throw std::ios_base::failure("Wrong input!\n");
    }
    while (stream >> word)
    {
      words.insert(word);
    }
  }

  for (auto i : words)
  {
    std::cout << i << '\n';
  }
}