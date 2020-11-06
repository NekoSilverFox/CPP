#include <iostream>
#include <sstream>
#include "phoneBook.hpp"
#include "bookmarks.hpp"
#include "info.hpp"
#include "taskFunctions.hpp"

void task1()
{
  std::string line;

  jianing::PhoneBook book_phone;
  jianing::Bookmarks marks(&book_phone);

  while (getline(std::cin, line))
  {
    if (std::cin.fail())
    {
      throw std::ios_base::failure("Error reading data.");
    }

    std::stringstream string(line);

    std::string command;

    string >> command;

    if (command == "add")
    {
      std::string external_number;

      string >> external_number;

      std::string external_name = getName(string);

      if (external_name.empty())
      {
        std::cout << "<INVALID COMMAND>\n";
        continue;
      }

      if (book_phone.isEmpty())
      {
        book_phone.pushBack({external_name, external_number});
        auto mark = marks.getCurrent();
        mark.iter = book_phone.getRecord();
        marks.replaceCurrent(mark);
      }
      else
      {
        book_phone.pushBack({external_name, external_number});
      }
    }
    else if (command == "store")
    {
      std::string markName;
      std::string newMarkName;

      string >> markName >> newMarkName;

      if (marks.findBookmark(markName))
      {
        marks.store(markName, newMarkName);
      }
      else
      {
        std::cout << "<INVALID BOOKMARK>\n";
      }
    }
    else if (command == "insert")
    {
      std::string additionalCommand;
      std::string markName;
      std::string external_number;

      string >> additionalCommand;

      string >> markName >> external_number;

      std::string external_name = getName(string);

      if (external_name.empty())
      {
        std::cout << "<INVALID COMMAND>\n";
        continue;
      }

      if (marks.findBookmark(markName))
      {
        if (additionalCommand == "before")
        {
          marks.insertBefore(markName, external_number, external_name);
        }
        else if (additionalCommand == "after")
        {
          marks.insertAfter(markName, external_number, external_name);
        }
        else
        {
          std::cout << "<INVALID COMMAND>\n";
        }
      }
      else
      {
        std::cout << "<INVALID BOOKMARK>\n";
      }
    }
    else if (command == "delete")
    {
      std::string markName;

      string >> markName;

      if (marks.findBookmark(markName))
      {
        marks.remove(markName);
      }
      else
      {
        std::cout << "<INVALID BOOKMARK>\n";
      }
    }
    else if (command == "show")
    {
      std::string markName;

      string >> markName;

      if (marks.findBookmark(markName))
      {
        marks.show(markName);
      }
      else
      {
        std::cout << "<INVALID BOOKMARK>\n";
      }
    }
    else if (command == "move")
    {
      std::string markName;
      std::string externalStep;

      string >> markName >> externalStep;

      if (marks.findBookmark(markName))
      {
        if (externalStep == "first")
        {
          marks.moveFirst(markName);
        }
        else if (externalStep == "last")
        {
          marks.moveLast(markName);
        }
        else
        {
          try
          {
            int step = std::stoi(externalStep);
            marks.move(markName, step);
          }
          catch (std::invalid_argument&)
          {
            std::cout << "<INVALID STEP>\n";
          }
        }
      }
      else
      {
        std::cout << "<INVALID BOOKMARK>\n";
      }
    }
    else
    {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}
