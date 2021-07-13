//
// Created by osnat on 1/10/19.
//

#include "MatrixSearchable.h"

using cell = pair<int,int>;


MatrixSearchable::MatrixSearchable(const vector<vector<int>>& matrix,
        const cell& init, const cell& goal){

    this->goalState = goal;
    this->initState = init;
    this->matrix = matrix;
}

Step<cell> MatrixSearchable:: getInitState()  {
    return Step<cell>(initState);
}

Step<cell> MatrixSearchable:: getGoalState() {
    return Step<cell>(goalState);
}

/**
 * getSuccessors  - return all 4 neighbors states of n in the matrix only if exist and reachable.
 *                  each state's is set as a sum of the n cost and the walk to the neighbor.
 * @param n - current state
 * @return list<State<pair<int,int>>> successors
 */
list<Step<cell>> MatrixSearchable::getSuccessors(Step<cell>& n) {
    list<Step<pair<int,int>>> successors;
    //if there is upper neighbor
    if(n.getState().first > 0) {
        int up = matrix[n.getState().first - 1][n.getState().second];
        //if neighbor is reachable
        if (up != -1) {
            Step<pair<int, int>> s(make_pair(n.getState().first - 1, n.getState().second));
            s.setCost(n.getCost() + up);
            s.setParent(n);
            successors.push_back(s);
        }
    }
    //if there is lower neighbor
    if(n.getState().first < this->matrix.size()-1) {
        int down = matrix[n.getState().first + 1][n.getState().second];
        if (down != -1) {
            Step<pair<int, int>> s(make_pair(n.getState().first + 1, n.getState().second));
            s.setCost(n.getCost() + down);
            s.setParent(n);
            successors.push_back(s);
        }
    }
    //if there is left neighbor
    if(n.getState().second > 0) {
        int left = matrix[n.getState().first][n.getState().second - 1];
        if (left != -1) {
            Step<pair<int, int>> s(make_pair(n.getState().first, n.getState().second - 1));
            s.setCost(n.getCost() + left);
            s.setParent(n);
            successors.push_back(s);
        }
    }
    //if there is right neighbor
    if(n.getState().second < this->matrix.size()-1) {
        int right = matrix[n.getState().first][n.getState().second + 1];
        if (right != -1) {
            Step<pair<int, int>> s(make_pair(n.getState().first, n.getState().second + 1));
            s.setCost(n.getCost() + right);
            s.setParent(n);
            successors.push_back(s);
        }
    }
    return successors;
}

istream& operator>>(istream& is, MatrixSearchable& m) {
    size_t numRows;
    is>>numRows;
    vector<vector<int>> tempMatrix;
    tempMatrix.reserve(numRows);
    for(int i = 0; i < numRows; i++) {
        vector<int> row;
        is>>row;
        tempMatrix.push_back(row);
    }
    cell init, goal;
    is>>init;
    is>>goal;
    m = MatrixSearchable(tempMatrix, init, goal);
    return is;
}




ostream& operator<<(ostream& os,const MatrixSearchable& m) {

    //numRows
    os<<m.matrix.size()<<endl;

    //all vectors of the rows in new line.
    for(int i = 0; i < m.matrix.size(); i++) {
        os<<m.matrix[i]<<endl;
    }
    //initial state
    os<<m.initState<<endl;
    //goal state
    os<<m.goalState<<endl;
    return os;
}

bool MatrixSearchable:: operator==(const MatrixSearchable& m) const{
    return (this->matrix == m.matrix && this->initState == m.initState && this->goalState == m.goalState);
}
