//
// Created by adani on 6/8/22.
//

#include "Dispatcher.h"

Dispatcher::Dispatcher(vector<BoundedQueue*> *in, vector<UnboundedQueue*> *out) {
    this->inQueue = in;
    this->outQueue = out;
}

void Dispatcher::dispatch() {
    int i = 0, done = 0;
    int producers = inQueue->size();
    string str;

    while (done < producers) {
        str = inQueue->at(i)->remove();
        if (str == "DONE") {
            done++;
            continue;
        }
        i++;
        if (i == producers) i -= producers;
        outQueue->at(getSubject(str))->insert(str);
    }
    for (i = 0; i < 3; i++) outQueue->at(i)->insert("DONE");
}

Dispatcher::~Dispatcher() {
    inQueue->clear();
    delete inQueue;
    outQueue->clear();
    delete outQueue;
}

int Dispatcher::getSubject(string str) {
    int spaces = 0, i = 0;
    while (spaces < 2) {
        if (str[i] == ' ') {
            spaces++;
        }
        i++;
    }
    if (str[i] == 'S') return 0;
    return (str[i] == 'N') ? 1 : 2;
}