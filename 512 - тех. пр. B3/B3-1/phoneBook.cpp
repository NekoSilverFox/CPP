#include "phoneBook.hpp"
#include <iostream>
#include "info.hpp"

jianing::PhoneBook::PhoneBook() :
  iterator_(phone_book_.end())
{}

jianing::PhoneBook::iter jianing::PhoneBook::toNextRecord()
{
  if (!isEmpty())
  {
    if (std::next(iterator_) == phone_book_.end())
    {
      return iterator_;
    }

    ++iterator_;
    return iterator_;
  }

  throw std::runtime_error(info::ERR_EMPTY); // =====================================
}

jianing::PhoneBook::iter jianing::PhoneBook::toPreviousRecord()
{
  if (iterator_ == phone_book_.begin())
  {
    return iterator_;
  }

  --iterator_;
  return iterator_;
}

jianing::PhoneBook::iter jianing::PhoneBook::insertAfter(const jianing::PhoneBook::RecordType& record, iter& position)
{
  if ((position == phone_book_.end()) || (std::next(position) == phone_book_.end()))
  {
    phone_book_.push_back(record);

    return --phone_book_.end();
  }

  auto temp = position;
  ++temp;

  return phone_book_.insert(temp, record);
}

jianing::PhoneBook::iter jianing::PhoneBook::insertBefore(const jianing::PhoneBook::RecordType& record, iter& position)
{
  if ((position != phone_book_.end()) && (position != phone_book_.begin()))
  {
    return phone_book_.insert(position, record);
  }

  phone_book_.push_front(record);
  return phone_book_.begin();
}

void jianing::PhoneBook::viewCurrentRecord(iter& iter)
{
  if ((!isEmpty()) && (iter != phone_book_.end()))
  {
    std::cout << iter->number << " " << iter->name << "\n";
  }
  else
  {
    std::cout << info::ERR_EMPTY;
  }
}

void jianing::PhoneBook::replaceCurrentRecord(const jianing::PhoneBook::RecordType& record)
{
  phone_book_.erase(iterator_);
  PhoneBook::insertBefore(record, iterator_);
}

void jianing::PhoneBook::pushBack(const jianing::PhoneBook::RecordType& record)
{
  phone_book_.push_back(record);

  if (iterator_ == phone_book_.end())
  {
    iterator_ = phone_book_.begin();
  }
}

void jianing::PhoneBook::deleteRecord(iter& element)
{
  if (isEmpty())
  {
    throw std::runtime_error(info::ERR_EMPTY); // ===================================================
  }

  phone_book_.erase(element);
}

bool jianing::PhoneBook::isEmpty() const
{
  return phone_book_.empty();
}

jianing::PhoneBook::iter jianing::PhoneBook::getRecord()
{
  return iterator_;
}

jianing::PhoneBook::iter jianing::PhoneBook::begin()
{
  return phone_book_.begin();
}

jianing::PhoneBook::iter jianing::PhoneBook::end()
{
  return phone_book_.end();
}
