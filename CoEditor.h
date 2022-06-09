// Guy Adani 208642884

#ifndef OSEX3_COEDITOR_H
#define OSEX3_COEDITOR_H

#include <chrono>
#include <thread>
#include "UnboundedQueue.h"
#include "BoundedQueue.h"


class CoEditor {
    UnboundedQueue *inQueue;
    BoundedQueue *outQueue;


public:
    CoEditor(UnboundedQueue *in, BoundedQueue *out);
    void edit();
};


#endif //OSEX3_COEDITOR_H
