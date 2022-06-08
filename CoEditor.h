//
// Created by adani on 6/8/22.
//

#ifndef OSEX3_COEDITOR_H
#define OSEX3_COEDITOR_H

#include "UnboundedQueue.h"
#include <thread>

class CoEditor {
    UnboundedQueue queue;

public:
    CoEditor(int size);
    void edit();
};


#endif //OSEX3_COEDITOR_H
