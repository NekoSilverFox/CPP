#ifndef STATEMENT_HPP
#define STATEMENT_HPP
#include <iostream>
#include <functional>
#include <cstring>
#include <random>

namespace jianing
{
  template <typename T>
  bool greater(T left, T right)
  {
    return left > right;
  }

  template <typename T>
  bool less(T left, T right)
  {
    return left < right;
  }

  /*
  ** Local specialization
  */
  template <typename TT>
  struct bracketAccess
  {
    typedef typename TT::size_type indexType;

    static typename TT::reference getElement(TT& data, indexType index)
    {
      return data[index];
    };

    static std::size_t getBegin(const TT&)
    {
      return 0;
    };

    static std::size_t getEnd(const TT& data)
    {
      return data.size();
    };
  };

  template <typename TT>
  struct atAccess
  {
    typedef typename TT::size_type indexType;

    static typename TT::reference getElement(TT& data, indexType index)
    {
      return data.at(index);
    };

    static indexType getBegin(TT&)
    {
      return 0;
    };

    static indexType getEnd(const TT& data)
    {
      return data.size();
    };
  };

  template <typename TT>
  struct iteratorAccess
  {
    typedef typename TT::iterator indexType;

    static typename TT::reference getElement(TT&, indexType index)
    {
      return *index;
    };

    static indexType getBegin(TT& data)
    {
      return data.begin();
    };

    static indexType getEnd(TT& data)
    {
      return data.end();
    };
  };

  template <template <typename TT> class Traits, typename TT, typename Cmp>
  void bubbleSort(TT& data, Cmp compare)
  {
    typedef typename Traits<TT>::indexType index;

    for (index i = Traits<TT>::getBegin(data); i != Traits<TT>::getEnd(data); i++)
    {
      for (index j = i; j != Traits<TT>::getEnd(data); j++)
      {
        if (compare(Traits<TT>::getElement(data, i), Traits<TT>::getElement(data, j)))
        {
          std::swap(Traits<TT>::getElement(data, i), Traits<TT>::getElement(data, j));
        }
      }
    }
  }


  template <typename TT>
  std::function<bool(TT, TT)> defineSortType(const char* sort_type)
  {
    if (!std::strcmp(sort_type, "ascending"))
    {
      return std::function<bool(TT, TT)>(std::greater<TT>());
    }
    else if (!std::strcmp(sort_type, "descending"))
    {
      return std::function<bool(TT, TT)>(std::less<TT>());
    }
    else
    {
      throw std::invalid_argument("ERROR! Wrong sort type parameter, please input [ascending] or [descending]!\n");
    }
  }

  template <typename TT>
  void printData(const TT& data)
  {
    for (typename TT::const_iterator it = data.begin(); it != data.end(); it++)
    {
      std::cout << *it << " ";
    }

    std::cout << "\n";
  }

  inline void initArray(double* array, int size) // Remind myself not to make same mistake here :P
  {
    std::random_device rd; //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> distr(-1.0, 1.0);

    for (int i = 0; i < size; i++)
    {
      array[i] = distr(gen);
    }
  }

}

#endif // STATEMENT_HPP
