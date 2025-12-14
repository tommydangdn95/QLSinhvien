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
    if (!head || !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    // Bubble sort by student ID
    bool swapped = true;
    while (swapped) {
        swapped = false;
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() > temp->next->data->getSinhVien()->getMaSV()) {
                // Swap data
                BangDiem* tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;
            }
            temp = temp->next;
        }
    }
    
    cout << "========== Bang diem (sap xep theo ma sinh vien) ==========" << endl;
    int index = 0;
    Node* temp = head;
    while (temp != nullptr) {
        cout << index + 1 << ". " << temp->data->getThongTin() << endl;
        temp = temp->next;
        index++;
    }
}

Node* LinkedList::getHead() {
    return this->head;
}

void LinkedList::hienThiBangDiemTheoMaSinhVien(string maSv) {
    cout << "\n========== Bang diem cua sinh vien: " << maSv << " ==========" << endl;
    
    bool found = false;
    int count = 0;
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp->data->getSinhVien()->getMaSV() == maSv) {
            count++;
            cout << count << ". " << temp->data->getThongTin() << endl;
            found = true;
        }
        temp = temp->next;
    }
    
    if (!found) {
        cout << "Khong tim thay bang diem cho sinh vien: " << maSv << endl;
    } else {
        cout << "\nTong so mon: " << count << endl;
    }
}

void LinkedList::hienThiBangDiemTheoMaSinhVienVaMonHoc(string maSv, string maMon) {
    cout << "\n========== Bang diem cua " << maSv << " - Mon: " << maMon << " ==========" << endl;
    
    bool found = false;
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp->data->getSinhVien()->getMaSV() == maSv && temp->data->getMonHoc()->getMaMon() == maMon) {
            cout << temp->data->getThongTin() << endl;
            found = true;
        }
        temp = temp->next;
    }
    
    if (!found) {
        cout << "Khong tim thay bang diem" << endl;
    }
}
