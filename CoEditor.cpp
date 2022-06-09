// Guy Adani 208642884


#include "CoEditor.h"

CoEditor::CoEditor(UnboundedQueue *in, BoundedQueue *out) {
    this->inQueue = in;
    this->outQueue = out;
}

void CoEditor::edit() {
    string str;
    while(str != "DONE") {
        str = inQueue->remove();
        this_thread::sleep_for(chrono::milliseconds(100));
        outQueue->insert(str);
    }
}