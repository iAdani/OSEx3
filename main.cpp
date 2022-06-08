#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "BoundedQueue.h"
#include "UnboundedQueue.h"
#include "Producer.h"
#include "Dispatcher.h"
#include "CoEditor.h"

using namespace std;

void producers() {

}

// Reads the configuration file
void writeToScreen() {
//    int done = 0, produced;
//
//    while(done < 3) {
//        if (produced == 2) produced = 0;
//
//
//        produced++;
//    }
}

int main() {
    vector<Producer*> prod;
    vector<thread> threads;
    vector<BoundedQueue*> *bQueue = new vector<BoundedQueue*>;
    vector<UnboundedQueue*> *uQueue = new vector<UnboundedQueue*>;
    vector<CoEditor*> editors;
    Dispatcher* dispatcher;
    BoundedQueue* toPrint = new BoundedQueue(17);

    bQueue->push_back(new BoundedQueue(3));
    for (int i = 0; i < 3; i++) {
        uQueue->push_back(new UnboundedQueue());
        editors.push_back(new CoEditor(uQueue->at(i), toPrint));
    }

    prod.push_back(new Producer(1,5,bQueue->at(0)));
    threads.push_back(thread([prod]() { prod[0]->produce(); }));


    dispatcher = new Dispatcher(bQueue, uQueue);
    threads.push_back(thread([dispatcher](){ dispatcher->dispatch(); }));

    for (CoEditor* editor : editors) {
        threads.push_back(thread([editor](){ editor->edit(); }));
    }
//
//    std::chrono::seconds time(10);
//    this_thread::sleep_for(time);
    for (thread &t : threads) if (t.joinable()) t.join();       // Join all threads

    for (int i = 0; i < 8; i++) cout << toPrint->remove() << endl;
    prod.clear();
    delete dispatcher;
    editors.clear();
    delete toPrint;
}
