#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <algorithm> // std::find
#include <iostream>

const int MAX = 1000;

template <typename arrType> class Array {
private:
  arrType arr[MAX];
  int tam;

public:
  /**
   * @brief get an iterator from the firts  element into the array
   *
   * @return arrType*
   */
  arrType *begin();

  /**
   * @brief get an iterator from the last element into the array
   *
   * @return arrType*
   */
  arrType *end();

  /**
   * @brief remove an element from the array
   *
   * @return true, if it's successfully removed
   * @return false, if it's not in the array
   */
  bool remove(arrType);

  /**
   * @brief Search an element into an array
   *
   * @return true, if it's there
   * @return false, if it's not
   */
  arrType *search(arrType);

  /**
   * @brief Get the number of elements
   *
   * @return int, tamanio
   */
  int size();

  /**
   * @brief Construct a new Array object with a pack of arguments
   *
   * @tparam Args, generic elements
   * @param args
   */
  template <typename... Args> Array(Args... args) {
    tam = 0;
    for (auto &v : {args...}) {
      arr[tam] = v;
      tam++;
    }
  }
  /**
   * @brief overloading operator to set, and get the elements
   *
   * @param index
   * @return arrType&
   */
  arrType &operator[](int index) {
    if (index < 0 or index >= tam)
      throw std::invalid_argument("Invalid index");
    return arr[index];
  }
};

template <typename arrType> arrType *Array<arrType>::begin() {
  arrType *beg = arr;
  return beg;
}

template <typename arrType> arrType *Array<arrType>::end() {
  arrType *end = arr + tam;
  return end;
}

template <typename arrType> bool Array<arrType>::remove(arrType target) {
  // code
  auto match = search(target);
  if (match == (arr + tam))
    return false;

  while (match != (arr + tam)) {
    *match = *(match + 1);
    match++;
  }
  tam--;
  return true;
}

template <typename arrType> arrType *Array<arrType>::search(arrType target) {
  // code
  arrType *result = std::find(arr, (arr + tam), target);
  if (result != (arr + tam)) {
    return result;
  }
  return (arr + tam);
}

template <typename arrType> int Array<arrType>::size() { return tam; }

#endif // __ARRAY_H__