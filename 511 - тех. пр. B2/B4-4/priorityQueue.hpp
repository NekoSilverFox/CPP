#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <list>
#include <map>
#include <cstring>
#include <stdexcept>

namespace jianing
{
  template <typename T>
  class PriorityQueue
  {
  public:
    typedef enum
    {
      HIGH,
      NORMAL,
      LOW
    } ElementPriority;

    void insert(const T &element, ElementPriority priority);
    T get();
    void accelerate();
    bool empty() const;

  private:
    std::map<ElementPriority, std::list<T> > queue_;
  };

  template <typename T>
  void PriorityQueue<T>::insert(const T& element, ElementPriority priority)
  {
    queue_[priority].push_back(element);
  }

  template <typename T>
  T PriorityQueue<T>::get()
  {
    if (empty())
    {
      throw std::out_of_range("ERROR! The priority queue is empty!\n");
    }

    for (auto& i: queue_)
    {
      if (!i.second.empty())
      {
        T element = i.second.front();
        i.second.pop_front();
        return element;
      }
    }
    throw std::runtime_error("ERROE! Unsuccessful assignment when executing [get] function");
  }

  template <typename T>
  void PriorityQueue<T>::accelerate()
  {
    queue_[HIGH].splice(queue_[HIGH].end(), queue_[LOW]);
  }

  template <typename T>
  bool PriorityQueue<T>::empty() const
  {
    for (const auto& i: queue_)
    {
      if (!i.second.empty())
      {
        return false;
      }
    }

    return true;
  }

}

#endif // PRIORITYQUEUE_HPP
