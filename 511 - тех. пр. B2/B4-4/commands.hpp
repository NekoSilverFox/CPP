#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include "priorityQueue.hpp"

namespace queueCommands
{
  template <typename T>
  void add(jianing::PriorityQueue<T>& queue, std::stringstream& std_stream);

  template <typename T>
  void get(jianing::PriorityQueue<T>& queue, std::stringstream& std_stream);

  template <typename T>
  void accelerate(jianing::PriorityQueue<T>& queue, std::stringstream& std_stream);

  using str_command = std::function<void(jianing::PriorityQueue<std::string>& queue, std::stringstream& string)>;
  const std::map<std::string, str_command> str_commands =
  {
    {"add", add<std::string>},
    {"get", get<std::string>},
    {"accelerate", accelerate<std::string>}
  };

  using str_priority = jianing::PriorityQueue<std::string>::ElementPriority;
  const std::map<std::string, str_priority> str_priorities =
  {
    {"low", jianing::PriorityQueue<std::string>::LOW},
    {"normal", jianing::PriorityQueue<std::string>::NORMAL},
    {"high", jianing::PriorityQueue<std::string>::HIGH}
  };
}

template <typename T>
void queueCommands::add(jianing::PriorityQueue<T>& queue, std::stringstream& std_stream)
{

    std::string str_priority;
    std_stream >> str_priority;

    if (!str_priorities.count(str_priority))
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
        queue.insert(element, str_priorities.at(str_priority));
      }
    }
}

template <typename T>
void queueCommands::get(jianing::PriorityQueue<T>& queue, std::stringstream& std_stream)
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

template <typename T>
void queueCommands::accelerate(jianing::PriorityQueue<T>& queue, std::stringstream& std_stream)
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
