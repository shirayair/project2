//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_MYPRIORITYQUEUE_H
#define UNTITLED4_MYPRIORITYQUEUE_H


#include "Step.h"
#include <queue>
#include <iostream>
#include <climits>
#include <sys/param.h>
#include "HashFuncs.h"

using namespace std;
template <class Q>
class MyPriorityQueue{
    std::deque<Q> queue;
public:
    MyPriorityQueue<Q>(){

    }
    void Sort(){

        for (int i = 1; i <= this->queue.size(); i++)
        {
            int min_index = minIndex(int(queue.size() - i));
            insertMinToRear(min_index);
        }
    }
    void insertMinToRear( int min_index) {
        Q min_val;
        unsigned long int n = queue.size();
        for (int i = 0; i < n; i++) {
            Q curr = queue.front();
            queue.pop_front();
            if (i != min_index)
                queue.push_back(curr);
            else
                min_val = curr;
        }
        queue.push_back(min_val);
    }
    int minIndex(int sortedIndex){
        int min_index = -1;
        Q min_val = queue.front();
        int n =int( queue.size());
        for (int i=0; i<n; i++)
        {
            Q curr = queue.front();
            queue.pop_front();  // This is dequeue() in C++ STL
            if (curr <= min_val && i <= sortedIndex)
            {
                min_index = i;
                min_val = curr;
            }
            queue.push_back(curr);  // This is enqueue() in
            // C++ STL
        }
        return min_index;
    }
    void pop(){
        this->queue.pop_front();
    }
    void push(const Q& state){
        queue.push_back(state);
        this->Sort();
    }
    int amountOfElement(){
        return (int)this->queue.size();
    }

    Q* find(const Q& q) {
        auto iter = std::find(queue.begin(), queue.end(), q);
        return (iter != queue.end()) ? &*iter: nullptr;
    }

    Q& front(){
        return this->queue.front();
    }
};


#endif //UNTITLED4_MYPRIORITYQUEUE_H
