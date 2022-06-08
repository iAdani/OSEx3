//
// Created by adani on 6/8/22.
//

#ifndef OSEX3_COEDITOR_H
#define OSEX3_COEDITOR_H

#include "UnboundedQueue.h"
#include "BoundedQueue.h"
#include <thread>

class CoEditor {
    UnboundedQueue *inQueue;
    BoundedQueue *outQueue;


public:
    CoEditor(UnboundedQueue *in, BoundedQueue *out);
    void edit();
};


#endif //OSEX3_COEDITOR_H
