//
// Created by adani on 6/8/22.
//

#ifndef OSEX3_PRODUCER_H
#define OSEX3_PRODUCER_H

#include "BoundedQueue.h"
#include <thread>

class Producer {
    string id;
    int products;
    BoundedQueue queue;
    vector<int> produced;

    // Returns the subject by modulo 3
    string getSubject();

public:
    Producer(int id, int products, int size);
    void produce();
};


#endif //OSEX3_PRODUCER_H
