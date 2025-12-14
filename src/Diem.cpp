//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/MonHoc.h"
#include "../includes/Diem.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Diem::Diem() {
    this->diemChuyenCan = 0;
    this->diemGiuaKy = 0;
    this->diemCuoiKy = 0;
    this->diemTongKet = 0;
}

Diem::Diem(float diemChuyenCan, float diemGiuaKy, float diemCuoiKy){
    this->diemChuyenCan = diemChuyenCan;
    this->diemGiuaKy = diemGiuaKy;
    this->diemCuoiKy = diemCuoiKy;
    this->tinhDiemTongKet();
}

float Diem::getDiemChuyenCan() { return diemChuyenCan; }
float Diem::getDiemGiuaKy() { return diemGiuaKy; }
float Diem::getDiemCuoiKy() { return diemCuoiKy; }
float Diem::getDiemTongKet() { return diemTongKet; }


void Diem::setDiemChuyenCan(float diemChuyenCan) {
    this->diemChuyenCan = diemChuyenCan;
    this->tinhDiemTongKet();
}

void Diem::setDiemGiuaKy(float diemGiuaKy) {
    this->diemGiuaKy = diemGiuaKy;
    tinhDiemTongKet();
}

void Diem::setDiemCuoiKy(float diemCuoiKy) {
    this->diemCuoiKy = diemCuoiKy;
    tinhDiemTongKet();
}

void Diem::tinhDiemTongKet() {
    this->diemTongKet = diemChuyenCan * 0.1 + diemGiuaKy * 0.3 + diemCuoiKy * 0.6;
}

string Diem::xepLoai() {
    if (diemTongKet >= 8.5) return "Gioi";
    if (diemTongKet >= 7.0) return "Kha";
    if (diemTongKet >= 5.5) return "Trung binh";
    if (diemTongKet >= 4.0) return "Yeu";
    return "Kem";
}

void Diem::nhap() {
    cout << "Diem chuyen can (0 < diem < 10): ";
    while (true) {
        if (!(cin >> diemChuyenCan)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nhap khong hop le! Vui long nhap mot so: ";
            continue;
        }
        if (diemChuyenCan <= 0 || diemChuyenCan >= 10) {
            cout << "Diem khong hop le! Diem phai trong khoang 0 den 10: ";
            continue;
        }
        break;
    }
    
    cout << "Diem giua ky (0 < diem < 10): ";
    while (true) {
        if (!(cin >> diemGiuaKy)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nhap khong hop le! Vui long nhap mot so: ";
            continue;
        }
        if (diemGiuaKy <= 0 || diemGiuaKy >= 10) {
            cout << "Diem khong hop le! Diem phai trong khoang 0 den 10: ";
            continue;
        }
        break;
    }
    
    cout << "Diem cuoi ky (0 < diem < 10): ";
    while (true) {
        if (!(cin >> diemCuoiKy)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nhap khong hop le! Vui long nhap mot so: ";
            continue;
        }
        if (diemCuoiKy <= 0 || diemCuoiKy >= 10) {
            cout << "Diem khong hop le! Diem phai trong khoang 0 den 10: ";
            continue;
        }
        break;
    }
    
    tinhDiemTongKet();
}

string Diem::getThongTin() {
    stringstream ss;
    ss << "Diem chuyen can: " << this->diemChuyenCan << " - Diem giua ky: " << this->diemGiuaKy << " - Diem cuoi ky: " << this->diemCuoiKy << " - Diem Tong Ket: " << this->diemTongKet;
    return ss.str();
}


