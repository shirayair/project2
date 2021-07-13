//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_TO_STRING_H
#define UNTITLED4_TO_STRING_H

#include <string>
#include "Step.h"


/*    template<class T>
    string to_string(Step<T> *state) {
        string concat = to_string(state->getState()) + "," + to_string(state->getCost());
        if(state->getParent() != nullptr) {
            concat += ","+to_string(state->getParent()->getState());
        }
        return concat;
    }*/

    //for the hash function of Step, to string on the pair as his State.
    inline string to_string(pair<int, int> cell) {
        string s ="pair:";
        return s += to_string(cell.first) + "," + to_string(cell.second);
    }


    inline string to_string(const string& s) {
        return s;
    }

#endif //UNTITLED4_TO_STRING_H
