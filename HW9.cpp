#include "HW9.h"
#include <iostream>

void findAllPermutationsHelper(
  int n, std::vector<bool>& alreadyUsed, std::vector<int>& currPerm,
    std::vector<std::vector<int>>& allPerms) {
if(n == currPerm.size()){
  allPerms.push_back(currPerm);
  return;
}
for(int i = 0; i < n; i++){
  if(!alreadyUsed[i]){
    currPerm.push_back(i+1);
    alreadyUsed[i] = true;
    findAllPermutationsHelper(n, alreadyUsed, currPerm, allPerms);
    currPerm.pop_back();
    alreadyUsed[i] = false;
    }
}
}

/*
 * I appoached this problem by first creating a base case to check whether the currPermutations is the same size as the input n. If that is true then we push back the current permutations to the vector called allPerm which hold the answers. For the recursive case, we enter a for loop that itterates from o to n and immediately checks if the current itteration is already used. The already used vector is orgianlly initialized to false and is necessary to make sure we dont include numbers that we have aleady recursed on. Next, we push back i+1 because we start the for loop at 0 but the numbers start at 1. We mark that number as alreadyUsed as true and recurse. Once currPerm is full we push back the answer in our base case and pop off the last digit. Once the digit is popped we need to updated the alreadyUsed vector to false becuase that number is no longer in the currPerm vec. 
 *
 */
std::vector<std::vector<int>> findAllPermutations(int n) {
  std::vector<bool> alreadyUsed(n, false);
  std::vector<int> currPerm;
  std::vector<std::vector<int>> allPerms;
  findAllPermutationsHelper(n, alreadyUsed, currPerm, allPerms);
  return allPerms;
}

