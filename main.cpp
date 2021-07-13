#include <iostream>
#include <vector>
#include "MatrixSearchable.h"
#include "Searcher.h"
#include "Solver.h"
#include "SearchSolver.h"
#include "BestFirstSearch.h"
#include "StreamOverload.h"
#include "MyMatrixClientHandler.h"
#include "CacheManager.h"
#include "MyParallelServer.h"
#include "Server.h"
#include "Bfs.h"
#include "Dfs.h"
#include "Astar.h"


using namespace std;
using cell = pair<int,int>;
int main(int argc, char* argv[]) {
    if(argc !=2){
        throw "No Port Received";
    }
    CacheManager<MatrixSearchable, vector<cell>>* cm =
            new FileCacheManager<MatrixSearchable, vector<cell>>("cachFile.txt");

    Searcher<cell>* astar = new Astar<cell>();

    ClientHandler* clientHandler = new MyMatrixClientHandler(astar, cm);

    server_side::Server* server = new MyParallelServer();
    server->open(stoi(argv[1]), clientHandler);
    server->stop();
    delete server;
    delete clientHandler;
    delete astar;
    delete cm;
    return 0;
}