#include <iostream>
#include <string>

struct Player {
  std::string firstName;
  std::string lastName;
  int homeRun;
};

void getInput(const int, Player[], Player[], Player[]);

int main()
{
  //Variable
  const int SIZE = 3;
  Player playersHomeruns[SIZE];
  Player playersFirstName[SIZE];
  Player playersLastName[SIZE];
  int total = 0;

  //
  std::cout << "This program will ask you to enter the name and home run count for 3 players.\n\n";

  //
  getInput(SIZE, playersHomeruns, playersFirstName,playersLastName);

  for (int i = 0; i < SIZE; i++) {
     total += playersHomeruns[i].homeRun;

  }

  std::cout << "Total home runs hit by all players: "<< total;

}

void getInput(const int S, Player homeruns[], Player plrFirst[], Player plrLast[])
{
  int num;
  std::string First;
  std::string Last;
  for (int i = 0; i < S; i++) {
    std::cout << "First Name: \n" ;
    std::cin >> First;
    std::cout << "Last Name: \n";
    std::cin >> Last;
    std::cout << "Home Runs: \n";
    std::cin >> num;

    plrFirst[i].firstName = First;
    plrLast[i].lastName = Last;
    homeruns[i].homeRun = num;
  }
  std::cout << "\n";
}
