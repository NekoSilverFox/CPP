#include <iostream>
#include <sstream>
#include "checkStream.hpp"
#include "phoneBook.hpp"
#include "bookmarks.hpp"
#include "commandsPhoneBook.hpp"
#include "info.hpp"

void task1()
{
  jianing::PhoneBook phone_book;
  jianing::Bookmarks marks(&phone_book);
  commands_phone_book::phone_book_mark phone_mark = {phone_book, marks};
  std::string input_com;

  while (std::getline(std::cin, input_com))
  {
    if (checkStream(std::cin) && input_com.empty())
    {
      return;
    }

    std::istringstream std_stream(input_com);
    std::string str_comm;
    std_stream >> str_comm;

    if (commands_phone_book::std_commands.find(str_comm) == commands_phone_book::std_commands.end())
    {
      std::cout << info::ERR_INVALID_COM;
    }
    else
    {
      commands_phone_book::std_commands.at(str_comm)(phone_mark, std_stream);
    }
  }
}
