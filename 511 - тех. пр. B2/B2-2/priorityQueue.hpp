#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <list>
#include <cstring>
#include <stdexcept>

typedef enum
{
  LOW,
  NORMAL,
  HIGH,
  NONE
} ElementPriority;

template <typename T>
class PriorityQueue
{
public:
  PriorityQueue();
  ~PriorityQueue() = default;

  void insert(const T &element, ElementPriority priority);
  T get();
  void accelerate();
  bool empty() const;

private:
  std::list<T> queue_;
  typename std::list<T>::iterator high_it_;
  typename std::list<T>::iterator normal_it_;
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
  T dummy_element;
  high_it_ = queue_.insert(queue_.end(), dummy_element);
  normal_it_ = queue_.insert(queue_.end(), dummy_element);
}

template <typename T>
void PriorityQueue<T>::insert(const T& element, ElementPriority priority)
{
  switch (priority)
  {
  case LOW:
    queue_.insert(queue_.end(), element);
    break;

  case NORMAL:
    queue_.insert(normal_it_, element);
    break;

  case HIGH:
    queue_.insert(high_it_, element);
    break;

  default:
    std::cout << "<INVALID COMMAND>\n";
  }
}

template <typename T>
T PriorityQueue<T>::get()
{
  if (empty())
  {
    throw std::invalid_argument("ERROR! The priority queue is empty!\n");
  }

  if (queue_.begin() != high_it_)
  {
    T front_elem = queue_.front();
    queue_.pop_front();
    return front_elem;
  }

  else if (std::next(high_it_) != normal_it_)
  {
    T front_elem = *std::next(high_it_);
    queue_.erase(std::next(high_it_));
    return front_elem;
  }

  else
  {
    T front_elem = *std::next(normal_it_);
    queue_.erase(std::next(normal_it_));
    return front_elem;
  }
}

template <typename T>
void PriorityQueue<T>::accelerate()
{
  auto it = std::next(normal_it_);

  while (it != queue_.end())
  {
    queue_.insert(high_it_, *it);
    it++;
    queue_.erase(std::prev(it));
  }
}

template <typename T>
bool PriorityQueue<T>::empty() const
{
  if ((queue_.begin() == high_it_)
    && (std::next(high_it_) == normal_it_)
    && (std::next(normal_it_) == queue_.end()))
  {
    return true;
  }
  else
  {
    return false;
  }
}

ElementPriority StringPriority2Enum(const char* str_priority)
{
  if (strcmp(str_priority, "high") == 0)
  {
    return ElementPriority::HIGH;
  }
  else if (strcmp(str_priority, "normal") == 0)
  {
    return ElementPriority::NORMAL;
  }
  else if (strcmp(str_priority, "low") == 0)
  {
    return ElementPriority::LOW;
  }
  else
  {
    return ElementPriority::NONE;
  }
}

#endif // PRIORITYQUEUE_HPP
