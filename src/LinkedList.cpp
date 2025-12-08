//
// Created by Tommy-Asus on 12/7/2025.
//

#include <stdio.h>
#include <iostream>
#include "../includes/LinkedList.h"
using namespace std;

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

void LinkedList::xuatHetThongTin() {
    if (this->length == 0) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    Node* temp = this->head;
    cout << "========== Bang diem sinh vien ==========" << endl;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        current->xuat();
        temp = temp->next;
    }
}

