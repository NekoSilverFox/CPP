#ifndef COMMANDS_PHONE_BOOK_HPP
#define COMMANDS_PHONE_BOOK_HPP
#include <functional>
#include <map>
#include "phoneBook.hpp"
#include "bookmarks.hpp"

namespace commands_phone_book
{
  std::string getName(std::istringstream& str_stream);
  using phone_book_mark = std::pair<jianing::PhoneBook&, jianing::Bookmarks&>;
  void comAdd(phone_book_mark& phone_mark, std::istringstream& str_stream);
  void comStore(phone_book_mark& phone_mark, std::istringstream& str_stream);
  void comInsert(phone_book_mark& phone_mark, std::istringstream& str_stream);
  void comDelete(phone_book_mark& phone_mark, std::istringstream& str_stream);
  void comShow(phone_book_mark& phone_mark, std::istringstream& str_stream);
  void comMove(phone_book_mark& phone_mark, std::istringstream& str_stream);

  using std_command = std::function<void(phone_book_mark& phone_mark, std::istringstream& str_stream)>;
  const std::map<std::string, std_command> std_commands =
  {
    {"add", comAdd},
    {"store", comStore},
    {"insert", comInsert},
    {"delete", comDelete},
    {"show", comShow},
    {"move", comMove},
  };
}

#endif // COMMANDS_PHONE_BOOK_HPP
