//
// Created by Tommy-Asus on 12/14/2025.
//

#include "../includes/SinhVienStack.h"
#include <iostream>
#include <algorithm>

SinhVienStack::SinhVienStack() {
    this->top = nullptr;
    this->count = 0 ;
}

void SinhVienStack::push(SinhVien* sv) {
    StackNode* newNode = new StackNode(sv);
    newNode->next = top;
    top = newNode;
    count++;
}

void SinhVienStack::push_back(SinhVien* sv) {
    push(sv);
}

SinhVien* SinhVienStack::pop() {
    if (empty()) {
        std::cout << "⚠ Stack rỗng!" << std::endl;
        return nullptr;
    }

    StackNode* temp = top;
    SinhVien* data = temp->data;

    top = top->next;
    delete temp;
    count--;

    return data;
}

SinhVien* SinhVienStack::peek() const {
    if (empty()) {
        return nullptr;
    }
    return top->data;
}

SinhVien* SinhVienStack::operator[](int index) {
    if (index < 0 || index >= count) {
        return nullptr;
    }

    StackNode* current = top;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

SinhVien* SinhVienStack::at(int index) {
    if (index < 0 || index >= count) {
        std::cout << "⚠ Index out of range!" << std::endl;
        return nullptr;
    }

    return (*this)[index];
}

SinhVien* SinhVienStack::findById(const std::string& maSV) {
    if (maSV.empty()) {
        return nullptr;
    }

    StackNode* current = top;
    while (current != nullptr) {
        if (current->data->getMaSV() == maSV) {
            return current->data;
        }
        current = current->next;
    }

    return nullptr;
}

bool SinhVienStack::empty() const {
    return count == 0;
}

int SinhVienStack::size() const {
    return count;
}

vector<SinhVien*> SinhVienStack::toVector() const {
    vector<SinhVien*> result;

    StackNode* current = top;
    while (current != nullptr) {
        result.push_back(current->data);
        current = current->next;
    }

    return result;
}

void SinhVienStack::clear() {
    while (!empty()) {
        pop();
    }
}

void SinhVienStack::display() const {
    if (empty()) {
        std::cout << "Stack rỗng!" << std::endl;
        return;
    }

    std::cout << "Stack (từ đỉnh xuống):" << std::endl;
    StackNode* current = top;
    int index = 0;
    while (current != nullptr) {
        std::cout << index << ". " << current->data->getThongTin() << std::endl;
        current = current->next;
        index++;
    }
}