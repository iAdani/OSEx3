//
// Created by adani on 6/7/22.
//

#include "UnboundedQueue.h"

UnboundedQueue::UnboundedQueue(int size) : q(), m() {
    if(sem_init(outsem, 1, 0) == -1 ){
        cout << "Error in semaphore init" << endl;
    }
}

void UnboundedQueue::insert(string str) {
    m.lock();
    q.push(str);
    m.unlock();
    sem_post(outsem);
}

string UnboundedQueue::remove() {
    sem_wait(outsem);
    m.lock();
    q.pop();
    m.unlock();
}
