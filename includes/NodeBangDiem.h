//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef NODE_H
#define NODE_H

#include "BangDiem.h"

class NodeBangDiem {
public:
    BangDiem* data;
    NodeBangDiem* next;

    NodeBangDiem(BangDiem* value);
};

#endif //NODE_H
