//
// Created by shira on 1/15/19.
//

#ifndef UNTITLED4_DFS_H
#define UNTITLED4_DFS_H

#include "ContainerStack.h"
#include "BDFS.h"

template <class State>
class Dfs: public BDFS<State,ContainerStack<Step<State>>>{

};
#endif //UNTITLED4_DFS_H
