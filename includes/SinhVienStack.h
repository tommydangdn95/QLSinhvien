//
// Created by Tommy-Asus on 12/14/2025.
//

#ifndef SINHVIENSTACK_H
#define SINHVIENSTACK_H

#include "SinhVien.h"
#include <vector>

// Node cho Stack
struct StackNode {
    SinhVien* data;
    StackNode* next;

    StackNode(SinhVien* sv) : data(sv), next(nullptr) {}
};

class SinhVienStack {
private:
    StackNode* top;
    int count;

public:
    SinhVienStack();
    void push(SinhVien* sv);
    void push_back(SinhVien* sv);
    SinhVien* pop();

    SinhVien* peek() const;
    SinhVien* operator[](int index);
    SinhVien* at(int index);
    SinhVien* findById(const std::string& maSV);

    bool empty() const;
    int size() const;
    vector<SinhVien*> toVector() const;

    void clear();
    void display() const;
};

#endif //SINHVIENSTACK_H
