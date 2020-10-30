#include "tasks.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include "commands.hpp"
#include "priorityQueue.hpp"

void task1()
{
  jianing::PriorityQueue<std::string> prior_queue;
  std::string line;

  while (std::getline(std::cin, line))
  {
    if (std::cin.bad())
    {
      throw std::ios_base::failure("ERROR! A serious exception occurred in the import stream (in task1)!\n");
    }

    if (std::cin.fail())
    {
      throw std::invalid_argument("ERROR! The value is too large to processing!\n");
    }

    if (line.empty())
    {
      std::cout << "<INVALID COMMAND>\n";
      continue;
    }

    std::stringstream std_stream(line);
    std::string command;
    std_stream >> command;

    try
    {
      queueCommands::commands.at(command)(prior_queue, std_stream);
    }
    catch (const std::out_of_range&)
    {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}
