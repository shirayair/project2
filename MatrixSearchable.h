//
// Created by osnat on 1/10/19.
//

#ifndef UNTITLED4_MATRIXSEARCHABLE_H
#define UNTITLED4_MATRIXSEARCHABLE_H


#include <vector>
#include "Searchable.h"
#include "StreamOverload.h"

using cell = pair<int,int>;

class MatrixSearchable: public Searchable<cell> {
    vector<vector<int>> matrix;
    cell initState;
    cell goalState;

public:
    MatrixSearchable(const vector<vector<int>>& matrix, const cell& init, const cell& goal);
    MatrixSearchable() = default;
    Step<cell> getInitState() override;

    Step<cell> getGoalState() override;
    list<Step<cell>> getSuccessors( Step<cell>& n) override;
    friend istream& operator>>(istream& is, MatrixSearchable& m);
    friend ostream& operator<<(ostream& os, const MatrixSearchable& m);
    bool operator==(const MatrixSearchable& m) const;
};


#endif //UNTITLED4_MATRIXSEARCHABLE_H
