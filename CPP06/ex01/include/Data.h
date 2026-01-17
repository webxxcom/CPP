/* --- Data.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/17/2026
------------------------------------------ */

#ifndef DATA_H
#define DATA_H

#include <string>

class Data {
public:
    Data();
    Data(std::string const& name, int num);
    Data(Data const& name);
    Data &operator=(Data const& name);
    ~Data();
    
    const std::string& getName() const;
    void setName(std::string name);
    
    int getNum() const;
    void setNum(int num);
private:
    std::string name;
    int num;

};

#endif // DATA_H
