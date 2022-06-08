//
// Created by adani on 6/8/22.
//

#include "Producer.h"

Producer::Producer(int id, int products, BoundedQueue *q) : produced() {
    this->queue = q;
    this->id = to_string(id);
    this->products = products;
    for(int i = 0; i < 3; i++) produced.push_back(0);
}

void Producer::produce() {
    string str;
    while (products > 0) {
        str = "Producer " + this->id + getSubject();
        queue->insert(str);
        products--;
    }
    queue->insert("DONE");
}

string Producer::getSubject() {
    int num = this->products % 3;
    if (num == 0) return " SPORTS " + to_string(produced[0]++);
    if (num == 1) return " NEWS " + to_string(produced[1]++);
    return " WEATHER " + to_string(produced[2]++);
}

BoundedQueue *Producer::getQueue() {
    return this->queue;
}

Producer::~Producer() { }


