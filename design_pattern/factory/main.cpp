#include "simplePattern.h"
#include "methodPattern.h"
#include "abstractPattern.h"

int main()
{
    SimplePattern::Factory simplePattern;
    simplePattern.CreateSingleCore(SimplePattern::COREA)->Show();

    MethodPattern::FactoryA factoryA;
    MethodPattern::FactoryB factoryB;
    factoryA.CreateSingleCore()->Show();
    factoryB.CreateSingleCore()->Show();

    AbstractPattern::FactoryA absFactoryA;
    absFactoryA.CreateSingleCore()->Show();
    absFactoryA.CreateMultiCore()->Show();

    return 0;
}

