#include <iostream>

int main(){
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "The original address: " << &string << std::endl
              << "The ptr address: " << &stringPTR << std::endl
              << "The ref address: " << &stringREF << std::endl
              << "The value of three: " 
                    << string << ", " 
                    << *stringPTR << ", " 
                    << stringREF << std::endl;
}