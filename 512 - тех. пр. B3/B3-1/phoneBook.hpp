#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <list>
#include <string>


namespace jianing
{

  class PhoneBook
  {
  public:

    struct RecordType
    {
      std::string name;
      std::string number;
    };

    using container = std::list<RecordType>;
    using iter = container::iterator;

    PhoneBook();

    iter toNextRecord();
    iter toPreviousRecord();

    PhoneBook::iter insertAfter(const RecordType& record, iter& position);
    PhoneBook::iter insertBefore(const RecordType& record, iter& position);

    void viewCurrentRecord(iter& iter);
    void replaceCurrentRecord(const RecordType& record);
    void pushBack(const RecordType& record);
    void deleteRecord(iter& element);
    bool isEmpty() const;

    iter getRecord();
    iter begin();
    iter end();

  private:
    container phone_book_;
    iter iterator_;
  };
}
#endif
