#include <iostream>

int main()
{
  //Variable
  int count = 10;
  char grid[10][10] = {
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'},
                        {'-','-','-','-','-','-','-','-','-','-'}
                        };

  //
  std::cout << "This is a treasure hunt game.\n"
            << "You have 3 attempts to find the 5 treasure chests hidden in the grid below.\n\n";

  std::cout << " ";
  for (int column = 0; column < count; column++) {
    std::cout << " "<<column ;
  }

  std::cout <<'\n';

  for (int row = 0; row < count; row++) {
    std::cout  << row << " ";
    for (int j = 0; j < count; j++) {
      std::cout << grid[row][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

  std::cout << "Legend: - (Unknown); E (Empty); T (Treasure)\n\n";


}
