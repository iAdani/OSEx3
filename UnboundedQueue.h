// Guy Adani 208642884

#ifndef OSEX3_UNBOUNDEDQUEUE_H
#define OSEX3_UNBOUNDEDQUEUE_H

#include <iostream>
#include <string>
#include <queue>
#include <mutex>
#include <semaphore.h>

using namespace std;
class UnboundedQueue : public queue<string> {
    queue<string> q;
    mutex m;
    sem_t outsem;

public:
    UnboundedQueue();
    void insert(string str);
    string remove();
};


#endif //OSEX3_UNBOUNDEDQUEUE_H
