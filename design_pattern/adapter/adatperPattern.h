#ifndef ADATPERPATTERN
#define ADATPERPATTERN

#include <iostream>

template<typename T>
class Deque
{
public:
    void push_back(const T&) { std::cout << "Deque push_back" << std::endl; }
    void push_front(const T&) { std::cout << "Deque push_front" << std::endl; }
    void pop_back(){ std::cout << "Deque pop_back" << std::endl; }
    void pop_front(){ std::cout << "Deque pop_front" << std::endl; }
};

template<typename T>
class Sequence
{
public:
    virtual void push(const T&) = 0;
    virtual void pop() = 0;
};

template<typename T, typename Container = Deque<T> >
class Stack: public Sequence<T>
{
public:
    void push(const T &x){ mContainer.push_back(x);}
    void pop(){ mContainer.pop_back(); }
private:
    Container   mContainer;
};

template<typename T, typename Container = Deque<T> >
class Queue: public Sequence<T>
{
public:
    void push(const T &x){ mContainer.push_back(x); }
    void pop(){ mContainer.pop_front(); }

private:
    Container   mContainer;
};

#endif // ADATPERPATTERN

