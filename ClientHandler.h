//
// Created by osnat on 1/15/19.
//

#ifndef UNTITLED4_CLIENTHANDLER_H
#define UNTITLED4_CLIENTHANDLER_H

#include "Solver.h"
#include "FileCacheManager.h"

class ClientHandler{

public:
    virtual void handleClient(int sock_id) = 0;
    virtual ~ClientHandler() = default;

};

#endif //UNTITLED4_CLIENTHANDLER_H
