//
// Created by Tommy-Asus on 12/7/2025.
//

#include <iostream>
#include "../includes/LinkedList.h"

#include <complex>
#include <map>
#include <vector>
using namespace std;

LinkedList::LinkedList() {
    this->head = nullptr;
    this->length = 0;
}

int LinkedList::getLength() {
    return this->length;
}

Node* LinkedList::getHead() {
    return this->head;
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

void LinkedList::capNhatBangDiemBangMonHoc(MonHoc* monHoc) {
    if (this->length == 0) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    Node* temp = this->head;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getMonHoc()->getMaMon() == monHoc->getMaMon()){
            current->setMonHoc(monHoc);
        }
        temp = temp->next;
    }
}

void LinkedList::capNhatBangDiemBangSinhVien(SinhVien* sinhVien) {
    if (this->length == 0) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    Node* temp = this->head;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getSinhVien()->getMaSV() == sinhVien->getMaSV()){
            current->setSinhVien(sinhVien);
        }
        temp = temp->next;
    }
}

void LinkedList::capNhatBangDiemKhiXoaSinhVien(SinhVien *sinhVien) {
    if (this->head == nullptr || this->length == 0) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    if (head->data->getSinhVien()->getMaSV() == sinhVien->getMaSV()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data->getSinhVien()->getMaSV() == sinhVien->getMaSV()) {
            Node* nodeDel = current->next;
            current->next = nodeDel->next;
            delete nodeDel;
        } else {
            current = current->next;
        }
    };
}

void LinkedList::capNhatBangDiemKhiXoaMonHoc(MonHoc *monHoc) {
    if (this->head == nullptr || this->length == 0) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    if (head->data->getMonHoc()->getMaMon() == monHoc->getMaMon()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data->getSinhVien()->getMaSV() == monHoc->getMaMon()) {
            Node* nodeDel = current->next;
            current->next = nodeDel->next;
            delete nodeDel;
        } else {
            current = current->next;
        }
    };
}

void LinkedList::capNhatBangDiemKhiXoaBangDiem(BangDiem *bangDiem) {
    if (this->head == nullptr || this->length == 0) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    bool isMatch = head->data->getSinhVien()->getMaSV() == bangDiem->getSinhVien()->getMaSV()
                && head->data->getMonHoc()->getMaMon() == bangDiem->getMonHoc()->getMaMon();

    if (isMatch) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {

        bool isMatchItem = current->data->getSinhVien()->getMaSV() == bangDiem->getSinhVien()->getMaSV()
                && current->data->getMonHoc()->getMaMon() == bangDiem->getMonHoc()->getMaMon();

        if (isMatchItem) {
            Node* nodeDel = current->next;
            current->next = nodeDel->next;

            this-length--;
            delete nodeDel;
        } else {
            current = current->next;
        }
    };
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


// tim thong tin sinhvien theo maSV
LinkedList* LinkedList::timBangDiemTheoMaSinhVien(SinhVien* sv) {
    LinkedList* listResult = new LinkedList();
    if (!head && !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return listResult;
    }

    cout << "Dang tim kiem doi tuong sinh vien: " << sv->getMaSV()<< endl;
    Node* temp = this->head;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getSinhVien()->getMaSV() == sv->getMaSV()) {
            listResult->them(current);
        }

        temp = temp->next;
    }

    return listResult;
}

LinkedList *LinkedList::timBangDiemTheoMonHoc(MonHoc *monHoc) {
    LinkedList* listResult = new LinkedList();
    if (!head && !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return listResult;
    }

    cout << "Dang tim kiem doi tuong mon hoc: " << monHoc->getMaMon()<< endl;
    Node* temp = this->head;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getMonHoc()->getMaMon() == monHoc->getMaMon()) {
            listResult->them(current);
        }
        temp = temp->next;
    }

    return listResult;
}

LinkedList* LinkedList::timDanhSachSinhVienDiemTongketThapNhat() {
    LinkedList* listResult = new LinkedList();
    if (!head && !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return listResult;
    }

    Node* temp = this->head;
    float minDiemTongKet = temp->data->getDiem()->getDiemTongKet();
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getDiem()->getDiemTongKet() < minDiemTongKet ) {
            minDiemTongKet = current->getDiem()->getDiemTongKet();
        }
        temp = temp->next;
    }

    temp = this->head;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getDiem()->getDiemTongKet() == minDiemTongKet ) {
            listResult->them(current);
        }
        temp = temp->next;
    }

    return listResult;
}

BangDiem* LinkedList::timBangDiemTheoIndex(int index) {
    if (this->length == 0) {
        cout << "Danh sach bang diem trong" << endl;
        return nullptr;
    }

    Node* temp = this->head;
    int bangDiemIndex = 0;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (bangDiemIndex == index) {
            return current;
        }
        bangDiemIndex++;
        temp = temp->next;
    }

    return nullptr;
}


LinkedList* LinkedList::timDanhSachSinhVienDiemTongketCaoNhat() {
    LinkedList* listResult = new LinkedList();
    if (!head && !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return listResult;
    }

    Node* temp = this->head;
    float maxDiemTongKet = temp->data->getDiem()->getDiemTongKet();
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getDiem()->getDiemTongKet() > maxDiemTongKet ) {
            maxDiemTongKet = current->getDiem()->getDiemTongKet();
        }
        temp = temp->next;
    }

    temp = this->head;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getDiem()->getDiemTongKet() == maxDiemTongKet ) {
            listResult->them(current);
        }
        temp = temp->next;
    }

    return listResult;
}

map<string, int> LinkedList::getDanhSachTanSuatMonHocDuocDangKy() {
    map<string, int> result;
    if (!head && !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return result;
    }

    map<string, int> frequency;
    Node* temp = this->head;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        string key = current->getMonHoc()->getMaMon();
        if (frequency.count(key) > 0) {
            frequency[key] = frequency[key] + 1;
        }
        else {
            frequency.insert({key, 1});
        }

        temp = temp->next;
    }

    return frequency;
}

float LinkedList::tinhDiemTrungBinhCacMonCuaSinhVien(SinhVien *sinhVien) {
    if (!head && !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return 0;
    }

    Node* temp = this->head;
    float sum = 0;
    int total = 0;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        string key = current->getSinhVien()->getMaSV();
        if (key == sinhVien->getMaSV()) {
            sum = current->getDiem()->getDiemTongKet() + sum;
            total += 1;
        }
        temp = temp->next;
    }

    if (sum == 0) {
        return 0;
    }

   return (sum / total);
}

float LinkedList::tinhDiemTrungBinhTheoMonHoc(MonHoc* monHoc) {
    if (!head && !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return 0;
    }

    Node* temp = this->head;
    float sum = 0;
    int total = 0;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        string key = current->getMonHoc()->getMaMon();
        if (key == monHoc->getMaMon()) {
            sum = current->getDiem()->getDiemTongKet() + sum;
            total += 1;
        }
        temp = temp->next;
    }

    if (sum == 0) {
        return 0;
    }

    return (sum / total);
}

int LinkedList::tinhTongSoTinChiCuaSinhVien(SinhVien *sinhVien) {
    if (!head || !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return 0;
    }

    Node* temp = this->head;
    int sum = 0;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        string key = current->getSinhVien()->getMaSV();
        if (key == sinhVien->getMaSV()) {
            sum = current->getMonHoc()->getSoTinChi() + sum;
        }
        temp = temp->next;
    }

    return sum;
}

int LinkedList::demSoMonHocSinhVienDaDangKy(SinhVien* sinhVien) {
    if (!head || !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return 0;
    }

    map<string, int> frequency;
    Node* temp = this->head;
    int sum = 0;
    while (temp != nullptr) {
        BangDiem* current = temp->data;
        if (current->getSinhVien()->getMaSV() == sinhVien->getMaSV()) {
            string key = current->getMonHoc()->getMaMon();
            if (frequency.count(key) > 0) {
                frequency[key] = frequency[key] + 1;
            }
            else {
                frequency.insert({key, 1});
            }
        }
        temp = temp->next;
    }

    return frequency.size();
}


void LinkedList::sapXepDanhSachBangDiemTheoMaSinhVien() {
    if (!head || !head->next) {
        cout << "Danh sach bang diem trong" << endl;
        return;
    }

    bool swapped = true;
    while (swapped) {
        swapped = false;
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() > temp->next->data->getSinhVien()->getMaSV()) {
                BangDiem* tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;
            }
            temp = temp->next;
        }
    }
}
