//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/LinkedListBangDiem.h"

LinkedListBangDiem::LinkedListBangDiem() {
    this->head = nullptr;
    this->length = 0;
}

void LinkedListBangDiem::them(BangDiem *bangDiem) {
    NodeBangDiem* newNode = new NodeBangDiem(bangDiem);
    if (this->length == 0) {
        this->head = newNode;
        this->length++;
        return;
    }
    NodeBangDiem* temp = this->head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    this->length++;
}

