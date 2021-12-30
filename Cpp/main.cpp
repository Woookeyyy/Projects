#include <iostream>

//Prototype
int getIntput();
void printPrompt();
float getAvgerage(int, int);
int getValidInput();

int main ()
{
  // Var
  const int SENTINEL = -1;
  int userInput = 0;
  float userAverage = 0;
  int count = 0;
  int score = 0;

  //Start
  printPrompt();
  //Keep getting input from user until user enter -1
  userInput = getValidInput();
  while ( userInput != SENTINEL) {
    count++;
    score += userInput;

    userInput = getValidInput();
  }
  // get the average
  userAverage = getAvgerage( score, count );
  std::cout << "Exam average, including extra credit, is: " << userAverage;
  //

}
//
void printPrompt()
{
  std::cout << "This program will calculate the average(%) of exam grades. \n"
            << "It will also add extra credit points to the exam average given the course difficulty. \n"
            << "Enter all of the grades for one student. Type (-1) when finished with that student. \n"
            << "If you have additional students, you will be prompted to repeat the program at the end. \n \n";
}
//
int getIntput()
{
  int num = 0;
  std::cout << "Enter an exam grade (type -1 to quit): ";
  std::cin >> num;
  return num;
}
//
float getAvgerage(int total, int count)
{

  const float EXTRA_CREDIT = 3.0;
  float average = total / static_cast<float>(count);
  return average + EXTRA_CREDIT;
}

int getValidInput()
{
  int grade = getIntput();

  while (grade < -1 || std::cin.fail()) {
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(100,'\n');
    }
    std::cout << "Error: Grades must be an integer 0 or higher. \n";
    grade = getIntput();
  }
  return grade;
}
