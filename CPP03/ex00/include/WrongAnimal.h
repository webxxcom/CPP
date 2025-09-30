/* --- WrongAnimal.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#include <string>
#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

class WrongAnimal {
private:
    std::string type;
    
public:
    WrongAnimal(std::string const& type);
    ~WrongAnimal();

    void makeSound() const;
};

#endif // WRONGANIMAL_H
