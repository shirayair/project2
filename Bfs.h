//
// Created by shira on 1/15/19.
//

#ifndef UNTITLED4_BFS_H
#define UNTITLED4_BFS_H

#include "ContainerQueue.h"
#include "BDFS.h"
template <class State>
class Bfs: public BDFS<State,ContainerQueue<Step<State>>>{

};
#endif //UNTITLED4_BFS_H
