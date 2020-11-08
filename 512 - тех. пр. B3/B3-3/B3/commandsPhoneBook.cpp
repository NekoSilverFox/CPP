#include "commandsPhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "info.hpp"

std::string commands_phone_book::getName(std::istringstream& str_stream)
{
  std::string external_name = "";

  str_stream.ignore();

  if (str_stream.peek() != '\"')
  {
    return "";
  }

  while (str_stream && (str_stream.peek() != -1))
  {
    const char char_get = str_stream.get();

    if ((char_get == '\"') || (char_get == '\0'))
    {
      continue;
    }
    else if (char_get == '\\')
    {
      const char char_next = str_stream.get();

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

void commands_phone_book::comAdd(phone_book_mark& phone_mark, std::istringstream& str_stream)
{
  std::string external_number;
  str_stream >> external_number;
  std::string external_name = commands_phone_book::getName(str_stream);

  if (external_name.empty())
  {
    std::cout << info::ERR_INVALID_COM;
    return;
  }

  if (phone_mark.first.isEmpty())
  {
    phone_mark.first.pushBack({external_name, external_number});
    auto mark = phone_mark.second.getCurrent();
    mark.iter = phone_mark.first.getRecord();
    phone_mark.second.replaceCurrent(mark);
  }
  else
  {
    phone_mark.first.pushBack({external_name, external_number});
  }
}

void commands_phone_book::comStore(phone_book_mark& phone_mark, std::istringstream& str_stream)
{
  std::string mark_name;
  std::string new_mark_name;

  str_stream >> mark_name >> new_mark_name;

  if (phone_mark.second.findBookmark(mark_name))
  {
    phone_mark.second.store(mark_name, new_mark_name);
  }
  else
  {
    std::cout << info::ERR_INVALID_BOOKMARK;
  }
}

void commands_phone_book::comInsert(phone_book_mark& phone_mark, std::istringstream& str_stream)
{
  std::string additional_command;
  std::string mark_name;
  std::string external_number;

  str_stream >> additional_command;
  str_stream >> mark_name >> external_number;

  std::string external_name = commands_phone_book::getName(str_stream);

  if (external_name.empty())
  {
    std::cout << info::ERR_INVALID_COM;
    return;
  }

  if (phone_mark.second.findBookmark(mark_name))
  {
    if (additional_command == "before")
    {
      phone_mark.second.insertBefore(mark_name, external_number, external_name);
    }
    else if (additional_command == "after")
    {
      phone_mark.second.insertAfter(mark_name, external_number, external_name);
    }
    else
    {
      std::cout << info::ERR_INVALID_COM;
    }
  }
  else
  {
    std::cout << info::ERR_INVALID_COM;
  }
}

void commands_phone_book::comDelete(phone_book_mark& phone_mark, std::istringstream& str_stream)
{
  std::string mark_name;

  str_stream >> mark_name;

  if (phone_mark.second.findBookmark(mark_name))
  {
    phone_mark.second.remove(mark_name);
  }
  else
  {
    std::cout << info::ERR_INVALID_BOOKMARK;
  }
}

void commands_phone_book::comShow(phone_book_mark& phone_mark, std::istringstream& str_stream)
{
  std::string mark_name;

  str_stream >> mark_name;

  if (phone_mark.second.findBookmark(mark_name))
  {
    phone_mark.second.show(mark_name);
  }
  else
  {
    std::cout << info::ERR_INVALID_BOOKMARK;
  }
}

void commands_phone_book::comMove(phone_book_mark& phone_mark, std::istringstream& str_stream)
{
  std::string mark_name;
  std::string external_step;

  str_stream >> mark_name >> external_step;

  if (phone_mark.second.findBookmark(mark_name))
  {
    if (external_step == "first")
    {
      phone_mark.second.moveFirst(mark_name);
    }
    else if (external_step == "last")
    {
      phone_mark.second.moveLast(mark_name);
    }
    else
    {
      try
      {
        int step = std::stoi(external_step);
        phone_mark.second.move(mark_name, step);
      }
      catch (std::invalid_argument&)
      {
        std::cout << info::ERR_INVALIN_STEP;
      }

    }
  }
  else
  {
    std::cout << info::ERR_INVALID_BOOKMARK;
  }
}
