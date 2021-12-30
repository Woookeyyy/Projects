#include <iostream>
//Prototype
int getInput();
int getInputValid();


int main()
{
  //Variable7777
  const int SIZE = 7;
  int letter = 1;
  int chars[] = {'A','W','E','S','O','M','E'};
  //
  std::cout << "I'm thinking of a 7 letter word.\n";



  //
  letter = getInputValid();
  while (letter  > 7 ||  letter < 1 ) {

        letter = getInputValid();
    }

  std::cout << "The letter in position " << letter << " is: " << static_cast<char>(chars[letter -1 ]);

}

int getInput()
{
  int num;
  std::cout << "Enter a number from 1 to 7 and I will tell you which letter is at that position: \n";
  std::cin >> num;
  return num;
}

int getInputValid()
{
  int rawInput = getInput();



  while (rawInput > 7 || rawInput < 1 ||std::cin.fail()) {
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(100,'\n');
    }
    std::cout << "Invalid entry. Please try again.\n";
    rawInput = getInput();
  }
  return rawInput;
}
