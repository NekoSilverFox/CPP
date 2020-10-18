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
      std::string priority;
      std_stream >> priority;

      std::string data;
      std_stream.ignore();
      std::getline(std_stream, data);

      while (data[0] == ' ' || data[0] == '\t')
      {
        data.erase(0, 1);
      }

      if (data.empty())
      {
        std::cout << "<INVALID COMMAND>\n";
      }
      else if (priority == "high")
      {
        prior_queue.insert(data, ElementPriority::HIGH);
      }
      else if (priority == "normal")
      {
        prior_queue.insert(data, ElementPriority::NORMAL);
      }
      else if (priority == "low")
      {
        prior_queue.insert(data, ElementPriority::LOW);
      }
      else
      {
        std::cout << "<INVALID COMMAND>\n";
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
