//
// Created by adani on 6/8/22.
//

#ifndef OSEX3_SCREENMANAGER_H
#define OSEX3_SCREENMANAGER_H

#include <chrono>
#include <thread>
#include "BoundedQueue.h"


class ScreenManager {
    BoundedQueue* queue;

public:
    ScreenManager(BoundedQueue* q);
    ~ScreenManager();
    void print();
};


#endif //OSEX3_SCREENMANAGER_H
