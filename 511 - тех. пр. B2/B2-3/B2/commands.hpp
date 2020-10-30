#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include "priorityQueue.hpp"

namespace queueCommands
{
  using str_pri_queue = jianing::PriorityQueue<std::string>;
  void add(str_pri_queue& queue, std::stringstream& std_stream);
  void get(str_pri_queue& queue, std::stringstream& std_stream);
  void accelerate(str_pri_queue& queue, std::stringstream& std_stream);

  using command = std::function<void(str_pri_queue& queue, std::stringstream& string)>;
  const std::map<std::string, command> commands =
  {
    {"add", add},
    {"get", get},
    {"accelerate", accelerate}
  };

  using priority = str_pri_queue::ElementPriority;
  const std::map<std::string, priority> priorities =
  {
    {"low", str_pri_queue::LOW},
    {"normal", str_pri_queue::NORMAL},
    {"high", str_pri_queue::HIGH}
  };
}

inline void queueCommands::add(str_pri_queue& queue, std::stringstream& std_stream)
{

    std::string str_priority;
    std_stream >> str_priority;

    if (!priorities.count(str_priority))
    {
      std::cout << "<INVALID COMMAND>\n";
    }
    else
    {
      std::string element;
      getline(std_stream >> std::ws, element);

      if (element.empty())
      {
        std::cout << "<INVALID COMMAND>\n";
      }
      else
      {
        queue.insert(element, priorities.at(str_priority));
      }
    }
}

inline void queueCommands::get(str_pri_queue& queue, std::stringstream& std_stream)
{
  std_stream >> std::ws;

  if (!std_stream.eof())
  {
    std::cout << "<INVALID COMMAND>\n";
  }
  else if (queue.empty())
  {
    std::cout << "<EMPTY>\n";
  }
  else
  {
    std::cout << queue.get() << "\n";
  }
}

inline void queueCommands::accelerate(str_pri_queue& queue, std::stringstream& std_stream)
{
  std_stream >> std::ws;

  if(!std_stream.eof())
  {
    std::cout<< "<INVALID COMMAND>\n";
    return;
  }

  queue.accelerate();
}

#endif // COMMANDS_HPP
