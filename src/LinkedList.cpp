//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/LinkedList.h"

LinkedList::LinkedList() {
    this->head = nullptr;
    this->length = 0;
}

void LinkedList::them(BangDiem *bangDiem) {
    Node* newNode = new Node(bangDiem);
    if (this->length == 0) {
        this->head = newNode;
        this->length++;
        return;
    }
    
    Node* temp = this->head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    this->length++;
}
