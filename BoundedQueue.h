// Guy Adani 208642884


#ifndef OSEX3_BOUNDEDQUEUE_H
#define OSEX3_BOUNDEDQUEUE_H

#include <iostream>
#include <string>
#include <queue>
#include <mutex>
#include <semaphore.h>

using namespace std;
class BoundedQueue : public queue<string> {
    queue<string> q;
    mutex m;
    sem_t insem, outsem;

public:
    BoundedQueue(int size);
    ~BoundedQueue();
    void insert(string str);
    string remove();
};


#endif //OSEX3_BOUNDEDQUEUE_H
