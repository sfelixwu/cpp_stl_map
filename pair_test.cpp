
#include <iostream>
#include <utility>

int main()
{
  // defining a pair
  std::pair<int, char> PAIR1;
  
  // first part of the pair
  PAIR1.first = 100;
  // second part of the pair
  PAIR1.second = 'G';
  
  std::cout << PAIR1.first << " ";
  std::cout << PAIR1.second << std::endl;
  
  return 0;
}
