//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../includes/NodeBangDiem.h"


class LinkedListBangDiem {
private:
    NodeBangDiem* head;
    int length;

public:
    LinkedListBangDiem();

    void them(BangDiem* bangDiem);
    void xuat();
};

#endif //LINKEDLIST_H
