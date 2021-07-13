//
// Created by shira on 1/15/19.
//

#ifndef UNTITLED4_CONTAINER_H
#define UNTITLED4_CONTAINER_H
template <class E>
class Container{

public:

    virtual void pop() = 0;

    virtual void push(const E& element) = 0;

    virtual  E& look() = 0;
    virtual bool empty() = 0 ;
};
#endif //UNTITLED4_CONTAINER_H
