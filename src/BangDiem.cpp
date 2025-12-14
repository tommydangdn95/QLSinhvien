//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/BangDiem.h"
#include <iostream>
#include <iomanip>
#include <sstream>

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

string BangDiem::getThongTin() {
    stringstream ss;
    ss << sinhVien->getThongTin() << "\n" << monHoc->getThongTin() << "\n" << diem->getThongTin();
    return ss.str();
}

