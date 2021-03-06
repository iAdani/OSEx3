// Guy Adani 208642884

#include "Dispatcher.h"

Dispatcher::Dispatcher(vector<BoundedQueue*> *in, vector<UnboundedQueue*> *out) {
    this->inQueue = in;
    this->outQueue = out;
}

void Dispatcher::dispatch() {
    int i = 0, done = 0;
    int producers = inQueue->size();
    string str;

    vector<bool> isDone;
    for (int j = 0; j < producers; j++) isDone.push_back(false);

    while (done < producers) {
        if (isDone.at(i) == true) {
            i = (i + 1) % producers;
            continue;
        }
        str = inQueue->at(i)->remove();
        if (str == "DONE") {
            done++;
            isDone.at(i) = true;
            i = (i + 1) % producers;
            continue;
        }
        i = (i + 1) % producers;
        outQueue->at(getSubject(str))->insert(str);
    }
    for (i = 0; i < 3; i++) outQueue->at(i)->insert("DONE");
}

Dispatcher::~Dispatcher() { }

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