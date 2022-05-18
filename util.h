/* DO NOT CHANGE THE FUNCTIONS IN THIS FILE */
#include <iostream>
#include <vector>
#include <algorithm>


/* Helper for viewing elements of vector of vectors */
template <class T>
void printVectorOfVectors(std::vector<std::vector<T>> x) {
  std::cout << "{";
  bool firstRow = true;
  for (auto a: x) {
    if (firstRow) {
      std::cout << "{";
      firstRow = false;
    } else {
      std::cout << "," << std::endl << "{";
    }
    bool firstCol = true;
    for (auto b: a) {
      if (firstCol) {
        std::cout << b;
        firstCol = false;
      } else {
        std::cout << ", " << b;
      }
    }
    std::cout << "}";
  }
  std::cout << "}" << std::endl;
}
