cmake_minimum_required(VERSION 3.13)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled4 main.cpp BestFirstSearch.h CacheManager.h FileCacheManager.h Container.h ContainerQueue.h ContainerStack.h FileCacheManager.h FileCacheManager.cpp HashFuncs.h MatrixSearchable.h MatrixSearchable.cpp MyPriorityQueue.h MyParallelServer.cpp MyParallelServer.h Server.h Searcher.h SearcherAbstruct.h Solver.h SearchSolver.h Step.h Step.cpp StreamOverload.h To_String.h Searchable.h MyMatrixClientHandler.cpp MyMatrixClientHandler.h Server.h ClientHandler.h BDFS.h Bfs.h Dfs.h Astar.h)