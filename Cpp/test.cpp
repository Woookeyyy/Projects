#include <iostream>

int main() {
int in;
std::string num[10] = {"Greater than 9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

std::cin >> in;

if(in > 9){
    std::cout << num[0];
}
else{
    std::cout << num[in];
}

return 0;
}
