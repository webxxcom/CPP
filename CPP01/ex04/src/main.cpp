#include <iostream>
#include <fstream>
#include <sstream>

static void start(const char *filename, const char *s1, const char *s2)
{
    std::ofstream ofs((std::string(filename) + ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (!ofs)
    {
        std::cerr << "Unexpected error occured, terminating\n";
        return ;
    }
    std::ifstream ifs(filename, std::ifstream::in);
    if (!ifs)
    {
        std::cerr << "Unexpected error occured, terminating\n";
        return;
    }
    
    std::string buff;
    size_t      i;
    while (ifs.good())
    {
        i = 0;
        do
        {
            buff.push_back(ifs.get());
            if (!ifs.good())
                return ; // EOF has been reached
        } while (buff[i] == s1[i] && s1[++i]);
        if (buff == s1)
            ofs << s2;
        else
            ofs << buff;
        buff.clear();
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "The program must take 4 args: ./prog <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    start(argv[1], argv[2], argv[3]);
    return 0;
}