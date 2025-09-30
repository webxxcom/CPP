
#include <string>
#include <iostream>
#include <limits>

namespace inpval
{
    void cleanBuffer(std::istream &in);
    bool is_only_whitespaces(std::string const &str);

    template <typename Field>
    void getValidInput(std::string const &prompt, Field &field)
    {
        std::cout << prompt;
        while (1)
        {
            if (std::getline(std::cin, field))
            {
                if (is_only_whitespaces(field))
                    std::cout << "\nThe field can't be empty\n";
                else
                    break;
            }
            else
            {
                std::cout << "\nEOF can't be entered here\n";
                cleanBuffer(std::cin);
                return;
            }
        }
    }
}