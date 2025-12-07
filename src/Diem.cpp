//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/MonHoc.h"
#include "../includes/Diem.h"
#include <iostream>

using namespace std;

Diem::Diem() {
    this->diemChuyenCan = 0;
    this->diemGiuaKy = 0;
    this->diemCuoiKy = 0;
    this->diemTongKet = 0;
}

Diem::Diem(MonHoc* monHoc, float diemChuyenCan, float diemGiuaKy, float diemCuoiKy){
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
    cout << "Diem chuyen can (0-10): ";
    cin >> diemChuyenCan;
    cout << "Diem giua ky (0-10): ";
    cin >> diemGiuaKy;
    cout << "Diem cuoi ky (0-10): ";
    cin >> diemCuoiKy;
    tinhDiemTongKet();
}

void Diem::xuat() {
    cout << setw(8) << fixed << setprecision(1) << diemChuyenCan
         << setw(8) << diemGiuaKy
         << setw(8) << diemCuoiKy
         << setw(8) << diemTongKet
         << setw(15) << xepLoai();
}


