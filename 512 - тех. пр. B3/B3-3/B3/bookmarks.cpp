#include "bookmarks.hpp"
#include <iostream>
#include <stdexcept>
#include "info.hpp"

jianing::Bookmarks::Bookmarks(jianing::PhoneBook* phone_book) :
  phone_book_pointer_(phone_book)
{
  MarkType mark;

  mark.mark_name = info::MARK_CURRENT;
  mark.iter = phone_book_pointer_->end();
  bookmarks_.push_back(mark);
}

void jianing::Bookmarks::store(std::string& mark_name, std::string& new_mark_name)
{
  std::list<MarkType>::iterator iter_mark;

  for (iter_mark = bookmarks_.begin(); iter_mark != bookmarks_.end(); ++iter_mark)
  {
    if (iter_mark->mark_name == mark_name)
    {
      break;
    }
  }

  MarkType mark;

  if (iter_mark->iter == phone_book_pointer_->end())
  {
    mark.mark_name = new_mark_name;
    mark.iter = phone_book_pointer_->end();
  }
  else
  {
    mark.mark_name = new_mark_name;
    mark.iter = iter_mark->iter;
  }

  bookmarks_.push_back(mark);
}

std::list<jianing::Bookmarks::MarkType>::iterator jianing::Bookmarks::searchIterator(std::string& mark_name)
{
  std::list<MarkType>::iterator iter_mark;

  for (iter_mark = bookmarks_.begin(); iter_mark != bookmarks_.end(); ++iter_mark)
  {
    if (iter_mark->mark_name == mark_name)
    {
      break;
    }
  }

  return iter_mark;
}

void jianing::Bookmarks::insertBefore(std::string& mark_name, std::string& number, std::string& name)
{
  std::list<MarkType>::iterator iter_mark = searchIterator(mark_name);
  iter_mark->iter = phone_book_pointer_->insertBefore({name, number}, iter_mark->iter);
}

void jianing::Bookmarks::insertAfter(std::string& mark_name, std::string& number, std::string& name)
{
  std::list<MarkType>::iterator iter_mark = searchIterator(mark_name);
  iter_mark->iter = phone_book_pointer_->insertAfter({name, number}, iter_mark->iter);
}

void jianing::Bookmarks::remove(std::string& mark_name)
{
  std::list<MarkType>::iterator iter_mark = searchIterator(mark_name);

  auto iter = iter_mark->iter;

  if ((iter == phone_book_pointer_->end()) || (phone_book_pointer_->isEmpty()))
  {
    std::cout << info::ERR_EMPTY;
    return;
  }

  if (std::next(iter_mark->iter) != phone_book_pointer_->end())
  {
    ++iter;
  }
  else if (iter_mark->iter != phone_book_pointer_->begin())
  {
    --iter;
  }
  else
  {
    iter = phone_book_pointer_->end();
  }

  for (auto i = bookmarks_.begin(); i != bookmarks_.end(); ++i)
  {
    if (iter_mark == i)
    {
      continue;
    }

    if (iter_mark->iter == i->iter)
    {
      i->iter = iter;
    }
  }

  phone_book_pointer_->deleteRecord(iter_mark->iter);

  iter_mark->iter = iter;
}

void jianing::Bookmarks::show(std::string& mark_name)
{
  std::list<MarkType>::iterator iter_mark = searchIterator(mark_name);
  phone_book_pointer_->viewCurrentRecord(iter_mark->iter);
}

jianing::Bookmarks::MarkType jianing::Bookmarks::getCurrent()
{
  return *getCurrentIterator();
}

std::list<jianing::Bookmarks::MarkType>::iterator jianing::Bookmarks::getCurrentIterator()
{
  for (auto i = bookmarks_.begin(); i != bookmarks_.end(); ++i)
  {
    if (i->mark_name == info::MARK_CURRENT)
    {
      return i;
    }
  }

  throw std::runtime_error("ERROR! Cant find the mark `current`!\n");
}

void jianing::Bookmarks::replaceCurrent(MarkType& new_mark)
{
  bookmarks_.erase(getCurrentIterator());
  bookmarks_.push_back(new_mark);
}

bool jianing::Bookmarks::findBookmark(std::string& mark_name)
{
  std::list<MarkType>::iterator iter_mark;
  for (iter_mark = bookmarks_.begin(); iter_mark != bookmarks_.end(); ++iter_mark)
  {
    if (iter_mark->mark_name == mark_name)
    {
      return true;
    }
  }

  return false;
}

void jianing::Bookmarks::move(std::string& mark_name, int& step)
{
  std::list<MarkType>::iterator iter_mark = searchIterator(mark_name);

  if (iter_mark->iter == phone_book_pointer_->end())
  {
    std::cout << info::ERR_EMPTY;
    return;
  }

  if (step >= 0)
  {
    while (!(std::next(iter_mark->iter) == phone_book_pointer_->end()) && (step > 0))
    {
      iter_mark->iter = std::next(iter_mark->iter);
      --step;
    }
  }
  else if (step < 0)
  {
    while (!(iter_mark->iter == phone_book_pointer_->begin()) && (step < 0))
    {
      iter_mark->iter = std::prev(iter_mark->iter);
      --step;
    }
  }
  else
  {
    std::cout << info::ERR_INVALIN_STEP;
  }
}

void jianing::Bookmarks::moveFirst(std::string& mark_name)
{
  std::list<MarkType>::iterator iter_mark = searchIterator(mark_name);

  iter_mark->iter = phone_book_pointer_->isEmpty()
    ? phone_book_pointer_->end()
    : phone_book_pointer_->begin();
}

void jianing::Bookmarks::moveLast(std::string& mark_name)
{
  std::list<MarkType>::iterator iter_mark = searchIterator(mark_name);

  iter_mark->iter = phone_book_pointer_->isEmpty()
    ? phone_book_pointer_->end()
    : --phone_book_pointer_->end();
}
