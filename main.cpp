#include <iostream>
#include "HW9.h"
#include "util.h"


int main() {
  std::cout << "Q3" << std::endl;
  std::cout << (findAllPermutations(1) == std::vector<std::vector<int>>{{1}}) << std::endl;;
  auto allPerms = std::vector<std::vector<int>>{{1, 2}, {2, 1}};
  std::cout << (findAllPermutations(2) == allPerms) << std::endl;;
  allPerms = std::vector<std::vector<int>>{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                           {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  std::cout << (findAllPermutations(3) == allPerms) << std::endl;
  // printVectorOfVectors(allPerms);  // helper to view your answer

}