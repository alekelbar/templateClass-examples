#include "./../include/Array.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  Array<int> array{1, 2, 3};
  Array<std::string> array2{"Alexander", "Joss", "Mel"};

  for (auto &&v : array2) {
    std::cout << v << std::endl;
  }

  for (auto &&v : array) {
    std::cout << v << std::endl;
  }

  std::cout << "How many elements: " << array2.size() << std::endl;
  array2[1] = "Alex";

  try {
    std::cout << "The element for example: " << array2[3] << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "Alexander its there: " << *(array2.search("Alexander"))
            << std::endl;

  std::cout << "Trying to delete " << array2[1] << " from the array: "
            << (array2.remove("Alex") ? "Successfully removed"
                                      : "Not successfully removed")
            << std::endl;

  for (auto &&v : array2) {
    std::cout << v << std::endl;
  }

  return 0;
}
