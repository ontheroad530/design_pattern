#ifndef METHODPATTERN
#define METHODPATTERN

#include <iostream>

namespace MethodPattern {

class SingleCore
{
public:
    virtual void Show() = 0;
};

class SingleCoreA : public SingleCore
{
public:
    void Show(){ std::cout << "SingleCore A" << std::endl; }
};

class SingleCoreB: public SingleCore
{
public:
    void  Show(){ std::cout << "SingleCore B" << std::endl; }
};

class Factory
{
public:
    virtual SingleCore* CreateSingleCore() = 0;
};

class FactoryA: public Factory
{
public:
    SingleCore* CreateSingleCore() { return new SingleCoreA(); }
};

class FactoryB: public Factory
{
public:
    SingleCore* CreateSingleCore(){ return new SingleCoreB(); }
};

}

#endif // METHODPATTERN

