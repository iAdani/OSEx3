//
// Created by adani on 6/7/22.
//

#include "BoundedQueue.h"

BoundedQueue::BoundedQueue(int size) : q(), m() {
    if(sem_init(insem, 1, size) == -1 ){
        cout << "Error in semaphore init" << endl;
    }
    if(sem_init(outsem, 1, 0) == -1 ){
        cout << "Error in semaphore init" << endl;
    }
}

void BoundedQueue::insert(string str) {
    sem_wait(insem);
    m.lock();
    q.push(str);
    m.unlock();
    sem_post(outsem);
}

string BoundedQueue::remove() {
    string str;
    sem_wait(outsem);
    m.lock();
    str = q.front();
    q.pop();
    m.unlock();
    sem_post(insem);
    return str;
}
