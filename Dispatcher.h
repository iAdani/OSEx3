// Guy Adani 208642884

#ifndef OSEX3_DISPATCHER_H
#define OSEX3_DISPATCHER_H

#include <thread>
#include "BoundedQueue.h"
#include "UnboundedQueue.h"


class Dispatcher {
    vector<BoundedQueue*> *inQueue;
    vector<UnboundedQueue*> *outQueue;

    int getSubject(string str);

public:
    Dispatcher(vector<BoundedQueue*> *in, vector<UnboundedQueue*> *out);
    ~Dispatcher();
    void dispatch();
};


#endif //OSEX3_DISPATCHER_H
