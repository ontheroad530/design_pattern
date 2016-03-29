#ifndef SIMPLEPATTERN_H
#define SIMPLEPATTERN_H

#include <iostream>

namespace SimplePattern {
    enum CTYPE { COREA, COREB };

    class SingleCore
    {
    public:
        virtual void Show() = 0;
    };

    class SingleCoreA: public SingleCore
    {
    public:
        void Show(){ std::cout << "SingleCore A" << std::endl; }
    };

    class SingleCoreB: public SingleCore
    {
    public:
        void Show() { std::cout << "SingleCore B" << std::endl; }
    };

    class Factory
    {
    public:
        SingleCore* CreateSingleCore(CTYPE type)
        {
            if(COREA == type)
                return new SingleCoreA();
            else if( COREB == type)
                return new SingleCoreB();
            else
                return NULL;
        }
    };
}

#endif // SIMPLEPATTERN_H
