//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef NODE_H
#define NODE_H

#include "BangDiem.h"

class Node {
public:
    BangDiem* data;
    Node* next;

    Node(BangDiem* value);
};

#endif //NODE_H
