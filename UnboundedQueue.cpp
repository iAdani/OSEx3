// Guy Adani 208642884

#include "UnboundedQueue.h"

UnboundedQueue::UnboundedQueue() : q(), m() {
    if(sem_init(&outsem, 1, 0) == -1 ){
        cout << "Error in semaphore init" << endl;
    }
}

void UnboundedQueue::insert(string str) {
    m.lock();
    q.push(str);
    m.unlock();
    sem_post(&outsem);
}

string UnboundedQueue::remove() {
    string str;
    sem_wait(&outsem);
    m.lock();
    str = q.front();
    q.pop();
    m.unlock();
    return str;
}
