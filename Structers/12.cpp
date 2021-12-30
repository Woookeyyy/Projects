#include <iostream>
#include <string>
#include <iomanip>

struct Plumber {
  std::string plumberName;
  std::string phoneNum;
  float estimate;
};

void getInput(const int, Plumber[],Plumber[],Plumber[]);
void printSummary(const int,Plumber[],Plumber[],Plumber[],Plumber[]);


int main()
{
  //Variable
  const int SIZE = 2;
  Plumber firstCompanyName[SIZE];
  Plumber firstCompanyPhoneNumer[SIZE];
  Plumber firstCompanyEstimate[SIZE];

  Plumber secondCompanyName[SIZE];
  Plumber secondtCompanyPhoneNumer[SIZE];
  Plumber secondCompanyEstimate[SIZE];

  //Prompt
  std::cout << "This program will compare estimates from two different plumbers.\n\n";
  //Get date from ther user
  getInput(SIZE,firstCompanyName,firstCompanyPhoneNumer,firstCompanyEstimate);
  getInput(SIZE,secondCompanyName,secondtCompanyPhoneNumer,secondCompanyEstimate);

  //
  printSummary(SIZE,firstCompanyName,secondCompanyName,firstCompanyEstimate,secondCompanyEstimate);

}

void getInput(const int SIZE, Plumber Names[], Plumber PhoneNum[], Plumber Est[])
{
  std::string tempName;
  std::string tempNum;
  float tempEst;
  std::cout << "Enter the company/plumber name: \n";
  std::getline (std::cin, tempName);
  std::cout << "Enter the phone number: \n";
  std::getline (std::cin, tempNum);
  std::cout << "Enter the estimate received: \n";
  std::cin >> tempEst;
  // Clear input stream
  std::cin.clear();
  std::cin.ignore(100, '\n');

  for (int i = 0; i < SIZE; i++) {
    Names[i].plumberName = tempName;
    PhoneNum[i].phoneNum = tempNum;
    Est[i].estimate = tempEst;
  }

}

void printSummary(const int SIZE, Plumber nameOne[], Plumber nameTwo[], Plumber NumOne[], Plumber NumTwo[])
{
  //Variable
  float LowestOne = 1000;
  float LowestTwo = 1000;
  float total = 0;
  std::string indexOne = " ";
  std::string indexTwo = " ";
  std::string name;


  for (int i = 0; i < SIZE; i++) {
    if (NumOne[i].estimate < LowestOne)
    {
      LowestOne = NumOne[i].estimate;
      indexOne = nameOne[i].plumberName;
    }
  }

  for (int i = 0; i < SIZE; i++) {
    if (NumTwo[i].estimate < LowestTwo)
    {
      LowestTwo = NumTwo[i].estimate;
      indexTwo = nameTwo[i].plumberName;


    }
  }

  if (LowestOne > LowestTwo)
   {
     total = LowestOne - LowestTwo;
     name = indexTwo;
    }
  else if (LowestOne < LowestTwo)
  {
     total = LowestTwo - LowestOne;
     name = indexOne;
  }


  if (total == 0)
  {
    std::cout << "Both plumbers gave the same estimate. Go with either." << std::endl;
  }
  else
  {
    std::cout <<  std::fixed << std::setprecision(2) << name << " is cheaper by $" << total << std::endl;
  }
}
