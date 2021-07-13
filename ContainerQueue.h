//
// Created by shira on 1/15/19.
//

#ifndef UNTITLED4_CONTAINERQUEUE_H
#define UNTITLED4_CONTAINERQUEUE_H

using namespace std;

#include <queue>
#include "Container.h"
template <class E>
class ContainerQueue : public Container<E>{
    queue<E> queue1;
public:
     void pop() override{
         this->queue1.pop();
     }
     void push(const E& element) override{
         this->queue1.push(element);
     }
     E& look() override{
        return this->queue1.front();
     }
     bool empty() override{
         return this->queue1.empty();
     }
};


#endif //UNTITLED4_CONTAINERQUEUE_H
