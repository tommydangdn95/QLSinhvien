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

int LinkedList::getLength() {
    return this->length;
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


void LinkedList::hienThiDanhSachBangDiem() {
    if (this->length == 0) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    int index = 0;
    Node* temp = this->head;
    cout << "========== Bang diem sinh vien ==========" << endl;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        cout << index + 1 << "." << current->getThongTin() << endl;
        temp = temp->next;
        index++;
    }
}

// Sap xep bang diem theo maSV tang dan
void LinkedList::sapXepDanhSachBangDiemTheoMaSinhVien() {
    if (!head && !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    bool swapped = true;
    while (swapped) {
        swapped = false;
    }
}
