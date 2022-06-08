//
// Created by adani on 6/8/22.
//

#include "ScreenManager.h"

ScreenManager::ScreenManager(BoundedQueue *q) {
    this->queue = q;
}

ScreenManager::~ScreenManager() { delete queue; }

void ScreenManager::print() {
    int done = 0;
    string str;

    while (done < 3) {
        str = queue->remove();
        if (str == "DONE") {
            done++;
            continue;
        }
        cout << str << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
