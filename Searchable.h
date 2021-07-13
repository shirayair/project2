//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_SEARCHABLE_H
#define UNTITLED4_SEARCHABLE_H

#include <list>
#include "Step.h"

using namespace std;

template<class State>
class Searchable {
public:
    virtual Step<State> getInitState() = 0;
    virtual Step<State> getGoalState() = 0;
    virtual list<Step<State>> getSuccessors(Step<State>& n) = 0;
    virtual ~Searchable()= default;

};

#endif //UNTITLED4_SEARCHABLE_H
