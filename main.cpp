#include <iostream>
#include "BoundedQueue.h"

using namespace std;
int main() {
    BoundedQueue q(5);
    q.insert("hi");
    cout << q.remove() << endl;
}
