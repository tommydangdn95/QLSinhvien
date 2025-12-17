//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/BangDiem.h"
#include <iostream>
#include <iomanip>
#include <format>
#include <string>
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
    string msg = format("{:<1}{}\n{:<2}{}\n{:<2}{}",
                       "",sinhVien->getThongTin(),
                       "",monHoc->getThongTin(),
                       "",diem->getThongTin());
    return msg;
}

string BangDiem::getThongTinInLine(){
    stringstream ss;
    ss << this->sinhVien->getMaSV() << "|"
        << this->sinhVien->getHoTen() << "|"
        << this->monHoc->getMaMon() << "|"
        << this->monHoc->getTenMon() << "|"
        << this->diem->getDiemChuyenCan() << "|"
        << this->diem->getDiemGiuaKy() << "|"
        << this->diem->getDiemCuoiKy() << "|";
    return ss.str();
}

void BangDiem::capNhatThongTin() {
    cout << "Sua diem cho sinh vien: " << this->sinhVien->getHoTen() << " ten mon: " << this->monHoc->getTenMon() << endl;
    this->diem->capNhatThongTin();
}
