//
// Created by shira on 1/15/19.
//

#ifndef UNTITLED4_CONTAINERSTACK_H
#define UNTITLED4_CONTAINERSTACK_H

#include "Container.h"
using namespace std;
#include <stack>
template <class E>
class ContainerStack :public Container<E>{
    stack<E> stack1;
public:
    void pop(){
        this->stack1.pop();
    }
    void push(const E& element){
        this->stack1.push(element);
    }
    E& look(){
        return this->stack1.top();
    }
    bool empty() {
        return this->stack1.empty();
    }
};


#endif //UNTITLED4_CONTAINERSTACK_H
