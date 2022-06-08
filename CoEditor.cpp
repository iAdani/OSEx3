//
// Created by adani on 6/8/22.
//

#include "CoEditor.h"

CoEditor::CoEditor(UnboundedQueue *in, BoundedQueue *out) {
    this->inQueue = in;
    this->outQueue = out;
}

void CoEditor::edit() {
    string str;
    while(str != "DONE") {
        str = inQueue->remove();
        outQueue->insert(str);
    }
}