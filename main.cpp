// Guy Adani 208642884

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include "BoundedQueue.h"
#include "UnboundedQueue.h"
#include "Producer.h"
#include "Dispatcher.h"
#include "CoEditor.h"
#include "ScreenManager.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Checking for conf file
    if (argc < 2) {
        cout << "Not enough arguments!" << endl;
        return 1;
    }

    // Initialize
    vector<Producer*> prod;
    vector<thread> threads;
    vector<BoundedQueue*> *bQueue = new vector<BoundedQueue*>;
    vector<UnboundedQueue*> *uQueue = new vector<UnboundedQueue*>;
    vector<CoEditor*> editors;
    Dispatcher* dispatcher;

    // Reading the configurations
    string input1, input2, input3;
    ifstream stream(argv[1]);
    do {
        getline(stream, input1);
        if(!getline(stream, input2)) {      // EOF
            break;
        }
        getline(stream, input3);

        bQueue->push_back(new BoundedQueue(stoi(input3)));
        prod.push_back(new Producer(stoi(input1), stoi(input2), bQueue->back()));
        getline(stream, input1);
    } while(true);

    // Last input
    BoundedQueue* toPrint = new BoundedQueue(stoi(input1));
    ScreenManager* scrMan = new ScreenManager(toPrint);
    stream.close();

    // Co-Editors init
    for (int i = 0; i < 3; i++) {
        uQueue->push_back(new UnboundedQueue());
        editors.push_back(new CoEditor(uQueue->at(i), toPrint));
    }

    // Running the Producers
    for (int j = 0; j < prod.size(); j++) {
        threads.push_back(thread([prod, j]() { prod[j]->produce(); }));
    }

    // Running the Dispatcher
    dispatcher = new Dispatcher(bQueue, uQueue);
    threads.push_back(thread([dispatcher](){ dispatcher->dispatch(); }));

    // Running the Co-Editors
    for (CoEditor* editor : editors) {
        threads.push_back(thread([editor](){ editor->edit(); }));
    }

    // Running the Screen Manager
    threads.push_back(thread([scrMan](){ scrMan->print(); }));

    // Join all threads
    for (thread &t : threads) if (t.joinable()) t.join();

    // Cleaning
    for (Producer* p : prod) delete p;
    delete dispatcher; // also deletes all used queues
    for (BoundedQueue* bq : *bQueue) delete bq;
    delete bQueue;
    for (UnboundedQueue* uq : *uQueue) delete uq;
    delete uQueue;
    for (CoEditor* e : editors) delete e;
    delete toPrint; // also deletes the last queue
    delete scrMan;
    return 0;
}
