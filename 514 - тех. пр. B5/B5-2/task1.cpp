#include "tasks.hpp"
#include <iostream>
#include <sstream>
#include <set>
#include <vector>

void jianing::B5::task1(std::istream& istr, std::ostream& ostr)
{
  std::string str_line;
  std::set<std::string> words;

  while (std::getline(istr, str_line))
  {
    std::stringstream stream(str_line);
    std::string word;

    /*
     * 后期这里可以改成 checkStream
     */
    if (istr.fail())
    {
      throw std::ios_base::failure("[ios_base::failure] ERROR! Wrong input!\n");
    }

    while (stream >> word)
    {
      words.insert(word);
    }
  }

  for (auto i : words)
  {
    ostr << i << '\n';
  }
}
