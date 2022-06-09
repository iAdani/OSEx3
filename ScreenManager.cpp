// Guy Adani 208642884

#include "ScreenManager.h"

ScreenManager::ScreenManager(BoundedQueue *q) {
    this->queue = q;
}

ScreenManager::~ScreenManager() { }

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
    }
    cout << "DONE" << endl;
}
