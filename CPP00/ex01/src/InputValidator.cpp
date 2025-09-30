/* --- InputValidator.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/21/2025
------------------------------------------ */

#include "inpval.h"

namespace inpval
{
    void cleanBuffer(std::istream &in)
    {
        in.clear(in.goodbit);
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool is_only_whitespaces(std::string const &str)
    {
        for (std::string::size_type i = 0; i < str.size(); ++i)
            if (!std::isspace(str[i]))
                return (false);
        return (true);
    }
}
