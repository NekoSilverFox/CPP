#include "tasks.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include "priorityQueue.hpp"

void task1()
{
  PriorityQueue<std::string> prior_queue;
  std::string line;

  while (std::getline(std::cin, line))
  {
    std::stringstream std_stream(line);
    std::string command;
    std_stream >> command;

    if (command == "add")
    {
      std::string str_priority;
      std_stream >> str_priority;

      ElementPriority enum_priority = StringPriority2Enum(str_priority.c_str());

      std::string data;
      std_stream.ignore();
      std::getline(std_stream, data);

      while (data[0] == ' ' || data[0] == '\t')
      {
        data.erase(0, 1);
      }

      if (data.empty() || (enum_priority == ElementPriority::NONE))
      {
        std::cout << "<INVALID COMMAND>\n";
      }
      else
      {
        prior_queue.insert(data, enum_priority);   
      }
    }

    else if (command == "accelerate")
    {
      prior_queue.accelerate();
    }

    else if (command == "get")
    {
      if (prior_queue.empty())
      {
        std::cout << "<EMPTY>\n";
      }
      else
      {
        std::cout << prior_queue.get() << std::endl;
      }
    }

    else
    {
      std::cout << "<INVALID COMMAND>\n";
    }

    if (std::cin.eof())
    {
      break;
    }
  }
}
