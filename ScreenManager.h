// Guy Adani 208642884

#ifndef OSEX3_SCREENMANAGER_H
#define OSEX3_SCREENMANAGER_H

#include "BoundedQueue.h"


class ScreenManager {
    BoundedQueue* queue;

public:
    ScreenManager(BoundedQueue* q);
    ~ScreenManager();
    void print();
};


#endif //OSEX3_SCREENMANAGER_H
