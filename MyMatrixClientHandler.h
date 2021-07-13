//
// Created by shira on 1/12/19.
//

#ifndef UNTITLED4_CLIENTHANDLE_H
#define UNTITLED4_CLIENTHANDLE_H

#include "ClientHandler.h"
#include "Searchable.h"
#include "SearchSolver.h"
#include "MatrixSearchable.h"


using namespace std;
using cell = pair<int,int>;

class MyMatrixClientHandler: public ClientHandler {

    SearchSolver<cell>* solver = nullptr;
    CacheManager<MatrixSearchable, vector<cell>>* cm = nullptr;
    MatrixSearchable parseBuffer(const string& buffer);
public:
    MyMatrixClientHandler(Searcher<cell>* searcher, CacheManager<MatrixSearchable, vector<cell>>* cm);
    void handleClient(int sock_id) override;
    static string fromREsultToString(const vector<cell>& result);
    ~MyMatrixClientHandler() {
        delete this->solver;
    }

};


#endif //UNTITLED4_CLIENTHANDLE_H
