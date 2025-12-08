//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/BangDiem.h"
#include <iostream>
#include <iomanip>
using namespace std;

BangDiem::BangDiem() {
    this->sinhVien = nullptr;
    this->monHoc = nullptr;
    this->diem = nullptr;
}

BangDiem::BangDiem(SinhVien *sinhVien, MonHoc *monHoc, Diem *diem) {
    this->sinhVien = sinhVien;
    this->monHoc = monHoc;
    this->diem = diem;
}

SinhVien* BangDiem::getSinhVien() { return sinhVien; }
MonHoc* BangDiem::getMonHoc() { return monHoc; }
Diem* BangDiem::getDiem() { return diem; }

void BangDiem::setSinhVien(SinhVien* sinhVien) { this->sinhVien = sinhVien; }
void BangDiem::setMonHoc(MonHoc* monHoc) { this->monHoc = monHoc; }
void BangDiem::setDiem(Diem* diem) { this->diem = diem; }

void BangDiem::xuat() {
    if (sinhVien != nullptr && monHoc != nullptr && diem != nullptr) {
        cout << "Ma Sinh vien: " << sinhVien->getMaSV() << endl;
        cout << "Ho va Ten: " << sinhVien->getHoTen() << endl;
        cout << "Mon hoc: " << monHoc->getTenMon() << endl;
        diem->xuat();
        cout << endl;
    }
}

