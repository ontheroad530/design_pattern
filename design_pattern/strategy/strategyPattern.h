#ifndef STRATEGYPATTERN
#define STRATEGYPATTERN

#include <iostream>

class ReplaceAlgorithm
{
public:
    virtual ~ReplaceAlgorithm(){}
    virtual void Replace() = 0;
};

class LRU_ReplaceAlgorithm: public ReplaceAlgorithm
{
public:
    virtual void Replace(){ std::cout << "LRU_ReplaceAlgorithm" << std::endl; }
};

class FIFO_ReplaceAlgorithm: public ReplaceAlgorithm
{
public:
    void Replace(){ std::cout << "FIFO_ReplaceAlgorithm" << std::endl; }
};

class Random_ReplaceAlgorithm: public ReplaceAlgorithm
{
public:
    void Replace(){ std::cout << "Random_ReplaceAlgorithm" << std::endl; }
};

class Cache
{
public:
    enum RA{ LRU, FIFO, RANDOM };

    Cache(RA ra)
    {
        switch (ra) {
        case LRU:
            mRa = new LRU_ReplaceAlgorithm();
            break;
        case FIFO:
            mRa = new FIFO_ReplaceAlgorithm();
            break;
        case RANDOM:
            mRa = new Random_ReplaceAlgorithm();
            break;
        default:
            mRa = NULL;
            break;
        }
    }

    ~Cache(){ delete mRa; }

    void Replace()
    {
        if(mRa)
            mRa->Replace();
    }

private:
    ReplaceAlgorithm    *mRa;
};

#endif // STRATEGYPATTERN

