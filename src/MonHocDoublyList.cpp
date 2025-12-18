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

void MonHocDoublyList::xoaMonHoc(MonHoc *monHoc) {
    while (head && head->data->getMaMon() == monHoc->getMaMon()) {
        MHNode* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
    }

    MHNode* curr = head;
    while (curr != nullptr) {
        if (curr->data->getMaMon() == monHoc->getMaMon()) {
            MHNode* del = curr;

            MHNode* prevNode = del->prev;
            if (prevNode) {
                prevNode->next = del->next;
            }

            MHNode* nextNode = del->next;
            if (nextNode) {
                nextNode->prev = del->prev;
            }

            curr = curr->next;
            this->count--;
            delete del;
        } else {
            curr = curr->next;
        }
    }
}

void MonHocDoublyList::sortMonhocTheoTen() {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        MHNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data->getTenMon() > temp->next->data->getTenMon()) {
                MonHoc* tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;
            }
            temp = temp->next;
        }
    }
}

