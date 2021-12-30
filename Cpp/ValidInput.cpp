#include <iostream>
//Prototype
int getInput();
int getValidInput();

int main()
{
  // Var
  int userInput = 0;

  //Get userInput
  //while()
  //{
    userInput = getValidInput();
//  }
}

int getInput()
{
  int num;
  std::cout << "User input: ";
  std::cin >> num;
  return num;
}

int num;
int getValidInput()
{
  int rawInput = getInput();
  while(std::cin.fail())
  {
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(100, '\n');
    }
    std::cout << "Error: \n";
    rawInput = getInput();
  }
  return rawInput;
}
