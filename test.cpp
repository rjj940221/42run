//
// Created by Robert JONES on 2016/12/01.
//

#include <iostream>

class Base{
public:
    void foo(){std::cout<<"base";}
};

class Derived : public Base
{
public:

};

int main()
{
    Derived bar;
    //call Base::foo() from bar here?
    bar.Base::foo(); // using a qualified-id
    return 0;
}