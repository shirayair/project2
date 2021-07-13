//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_BESTFIRSTSEARCH_H
#define UNTITLED4_BESTFIRSTSEARCH_H

#include <utility>
#include <bits/stdc++.h>
#include "SearcherAbstruct.h"
using namespace std;

namespace std {
    template<class State>
    struct equal_to<Step<State>*> {
        bool operator()(const Step<State> *x, const Step<State> *y) const { return *x == *y; }
    };
}

template <class State>
class BestFirstSearch : public  SearcherAbstruct<State>{

    vector<State> traceBack(const Step<State>& goalState, const unordered_set<Step<State>*>& closed) const{
        vector<State> traceSolution;
        const Step<State>* current = &goalState;
        while(current != nullptr) {
            traceSolution.push_back(current->getState());
            current = current->getParent();
        }
        reverse(traceSolution.begin(), traceSolution.end());
        freeClosed(closed);
        return traceSolution;
    }



    void updatePriority(Step<State>& s, MyPriorityQueue<Step<State>>& openList) const{
        Step<State>* findS = openList.find(s);
        findS->setParent(*s.getParent());
        findS->setCost(s.getCost());
        openList.Sort();
    }



public:
    vector<State> search(Searchable<State>* searchable) const{
        unordered_set<Step<State>*> closed ;
        MyPriorityQueue<Step<State>> openList;
        openList.push(searchable->getInitState());
        while(openList.amountOfElement() > 0) {
            Step<State> n = openList.front();
            //this->numEvaluate++;
            openList.pop();
            auto pointerToN = new Step<State>(n);
            closed.insert(pointerToN);
            if(*pointerToN == searchable->getGoalState()) {
                return traceBack(*pointerToN, closed);
            }
            list<Step<State>> successors = searchable->getSuccessors(*pointerToN);
            for(Step<State>& s: successors) {
                if(closed.find(&s) != closed.end()){
                    continue;
                } else if(Step<State>* spos = openList.find(s)){
                    if( s.getCost() < spos->getCost()) {
                        updatePriority(s, openList);
                    }
                } else {
                    openList.push(s);
                }
            }
        }
        vector<State> NoSolution = {};
        freeClosed(closed);
        return NoSolution;

    }

    void freeClosed(const unordered_set<Step<State>*>& closed) const{
        if(!closed.empty()) {
            for (Step<State>* x: closed) {
                delete x;
            }
        }
    }
};



#endif //UNTITLED4_BESTFIRSTSEARCH_H
