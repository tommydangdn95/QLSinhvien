//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../includes/Node.h"
#include <iostream>
#include <fstream>
#include <vector>

class LinkedList {
private:
    Node* head;
    int length;
public:
    LinkedList();
    int getLength();
    void them(BangDiem* bangDiem);
    void hienThiDanhSachBangDiem();
    void sapXepDanhSachBangDiemTheoMaSinhVien();
};

#endif //LINKEDLIST_H
