#ifndef BOOKMARKS_HPP
#define BOOKMARKS_HPP
#include "phoneBook.hpp"

namespace jianing
{
  class Bookmarks
  {
  public:
    using container = std::list<PhoneBook::RecordType>;

    struct MarkType
    {
      std::string mark_name;
      container::iterator iter;
    };

    Bookmarks() = default;
    Bookmarks(PhoneBook* phone_book);

    void store(std::string& mark_name, std::string& new_mark_name);
    void insertBefore(std::string& mark_name, std::string& number, std::string& name);
    void insertAfter(std::string& mark_name, std::string& number, std::string& name);
    void remove(std::string& mark_name);
    void show(std::string& mark_name);
    void move(std::string& mark_name, int& step);
    MarkType getCurrent();
    void replaceCurrent(MarkType& new_mark);
    bool findBookmark(std::string& mark_name);
    void moveFirst(std::string& mark_name);
    void moveLast(std::string& mark_name);

  private:
    std::list<MarkType>::iterator getCurrentIterator();
    std::list<MarkType>::iterator searchIterator(std::string& mark_name);

    std::list<MarkType> bookmarks_;
    PhoneBook* phone_book_pointer_;

  };
}
#endif
