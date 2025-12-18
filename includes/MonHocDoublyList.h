//
// Created by Tommy-Asus on 12/14/2025.
//

#ifndef MONHOCDOUBLYLIST_H
#define MONHOCDOUBLYLIST_H

#include "MonHoc.h"
#include <vector>

// Node cho Doubly Linked List
struct MHNode {
    MonHoc* data;
    MHNode* next;
    MHNode* prev;
    MHNode(MonHoc* mh) : data(mh), next(nullptr), prev(nullptr) {}
};

class MonHocDoublyList {
private:
    MHNode* head;
    MHNode* tail;
    int count;

public:
    MonHocDoublyList();
    void push_back(MonHoc* mh);
    MonHoc* operator[](int index);
    MonHoc* findById(const std::string& maMon);
    bool empty() const;
    int size() const;
    vector<MonHoc*> toVector() const;
    void clear();
    void xoaMonHoc(MonHoc *monHoc);
    void sortMonhocTheoTen();
};


#endif //MONHOCDOUBLYLIST_H
