#ifndef CIM_HPP_INCLUDED
#define CIM_HPP_INCLUDED
#include <iostream>
#include <string>

class Cim{
private:
    std::string cim;
public:

    Cim() {}

    Cim(const char* cim): cim(cim){}

    ///cim string tartalm�t adja vissza
    std::string getcim() const {return cim;}

    ///cim string tartalm�t �ll�tja be
    void setcim(std::string s) {cim=s;}

    ~Cim() {}
};

#endif // CIM_HPP_INCLUDED
