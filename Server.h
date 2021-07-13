//
// Created by shira on 1/12/19.
//

#ifndef UNTITLED4_SERVER_H
#define UNTITLED4_SERVER_H

#include "MyMatrixClientHandler.h"

namespace server_side{
    class Server{
    public:
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void stop() = 0;
        virtual ~Server() = default;
    };
}

#endif //UNTITLED4_SERVER_H
