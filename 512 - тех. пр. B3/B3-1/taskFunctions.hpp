#ifndef TASKFUNCTIONS_HPP
#define TASKFUNCTIONS_HPP
#include <iostream>
#include <sstream>

std::string getName(std::stringstream& string)
{
  std::string external_name = "";

  string.ignore();

  if (string.peek() != '\"')
  {
    return "";
  }

  while (string && (string.peek() != -1))
  {
    const char char_get = string.get();

    if ((char_get == '\"') || (char_get == '\0'))
    {
      continue;
    }
    else if (char_get == '\\')
    {
      const char char_next = string.get();

      if (char_next == '\"')
      {
        external_name += char_next;
      }
      else
      {
        external_name += char_get;
      }
    }
    else
    {
      external_name += char_get;
    }
  }

  return external_name;
}


#endif
