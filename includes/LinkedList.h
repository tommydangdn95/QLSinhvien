//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../includes/Node.h"


class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList();

    void them(BangDiem* bangDiem);
};

#endif //LINKEDLIST_H
