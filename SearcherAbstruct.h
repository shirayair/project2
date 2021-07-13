//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_SEARCHERABSTRUCT_H
#define UNTITLED4_SEARCHERABSTRUCT_H


#include "Searcher.h"
#include "MyPriorityQueue.h"

template <class State>
class SearcherAbstruct : public Searcher<State>{

public:
    int getNodEvaluate(){
        return this->numEvaluate;
    }
    int OpenListSize(){
        return this->openList.amountOfElement();
    }
    ~SearcherAbstruct(){
    }


protected:
    int numEvaluate =0;
/*    Step<State> popOpenList(){
        numEvaluate++;
        auto x = this->openList.front();
        this->openList.pop();
        return x;
    }*/

};


#endif //UNTITLED4_SEARCHERABSTRUCT_H
