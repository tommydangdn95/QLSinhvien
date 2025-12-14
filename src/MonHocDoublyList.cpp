//
// Created by Tommy-Asus on 12/14/2025.
//

#include "../includes/MonHocDoublyList.h"
#include <iostream>

MonHocDoublyList::MonHocDoublyList() : head(nullptr), tail(nullptr), count(0) {}

void MonHocDoublyList::push_back(MonHoc* mh) {
    MHNode* newNode = new MHNode(mh);

    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    count++;
}

MonHoc* MonHocDoublyList::operator[](int index) {
    if (index < 0 || index >= count) {
        return nullptr;
    }

    MHNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

MonHoc* MonHocDoublyList::findById(const std::string& maMon) {
    if (maMon.empty()) {
        return nullptr;
    }

    MHNode* current = head;
    while (current != nullptr) {
        if (current->data->getMaMon() == maMon) {
            return current->data;
        }
        current = current->next;
    }

    return nullptr;
}

bool MonHocDoublyList::empty() const {
    return count == 0;
}

int MonHocDoublyList::size() const {
    return count;
}

std::vector<MonHoc*> MonHocDoublyList::toVector() const {
    std::vector<MonHoc*> result;

    MHNode* current = head;
    while (current != nullptr) {
        result.push_back(current->data);
        current = current->next;
    }

    return result;
}

void MonHocDoublyList::clear() {
    while (head != nullptr) {
        MHNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}