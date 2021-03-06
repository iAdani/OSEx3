// Guy Adani 208642884

#ifndef OSEX3_PRODUCER_H
#define OSEX3_PRODUCER_H

#include <thread>
#include "BoundedQueue.h"

class Producer {
    string id;
    int products;
    BoundedQueue *queue;
    vector<int> produced;

    // Returns the subject by modulo 3
    string getSubject(int num);

public:
    Producer(int id, int products, BoundedQueue *q);
    ~Producer();
    BoundedQueue* getQueue();
    void produce();


};


#endif //OSEX3_PRODUCER_H
