//
// Created by shira on 1/10/19.
//

#ifndef UNTITLED4_SOLVESEARCH_H
#define UNTITLED4_SOLVESEARCH_H


#include "Solver.h"
#include "Searcher.h"
template <class State>
class SearchSolver : public Solver<Searchable<State>, vector<State>>{
    Searcher<State>* searcher;
public:
    explicit SearchSolver(Searcher<State>* searcher) {
        this->searcher = searcher;
    }
     vector<State> solve(Searchable<State>* searchable) override {
        return this->searcher->search(searchable);
    }
};


#endif //UNTITLED4_SOLVESEARCH_H
