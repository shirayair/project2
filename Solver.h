//
// Created by shira on 1/7/19.
//

#ifndef UNTITLED4_SOLVER_H
#define UNTITLED4_SOLVER_H
template <class Problem,class Solution>
        class Solver{
public:
    virtual Solution solve(Problem* problem) = 0;
};

#endif //UNTITLED4_SOLVER_H
