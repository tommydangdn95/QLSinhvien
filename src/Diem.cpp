//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/MonHoc.h"
#include "../includes/Diem.h"
#include <iostream>
#include <iomanip>
#include <format>

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

void Diem::nhap() {
    cout << "Diem chuyen can (0-10): ";
    cin >> diemChuyenCan;
    cout << "Diem giua ky (0-10): ";
    cin >> diemGiuaKy;
    cout << "Diem cuoi ky (0-10): ";
    cin >> diemCuoiKy;
    tinhDiemTongKet();
}

string Diem::getThongTin() {
    string msg = format("Diem chuyen can: {} - Diem giua ky: {} - Diem cuoi ky: {} - Diem Tong Ket: {}",
        this->diemChuyenCan,
        this->diemGiuaKy,
        this->diemCuoiKy,
        this->diemTongKet);
    return msg;
}

void Diem::capNhatThongTin() {
    string nhapDiemChuyenCan, nhapDiemGiuaKy, nhapDiemCuoiKy;
    cout << "Diem chuyen can (0-10): ";
    cin.ignore();
    getline(cin, nhapDiemChuyenCan);
    cout << "Diem giua ky (0-10): ";
    getline(cin, nhapDiemGiuaKy);
    cout << "Diem cuoi ky (0-10): ";
    getline(cin, nhapDiemCuoiKy);

    if (!nhapDiemChuyenCan.empty()) {
        float convertDck = stof(nhapDiemChuyenCan);
        setDiemChuyenCan(convertDck);
    }

    if (!nhapDiemGiuaKy.empty()) {
        float convertDgk = stof(nhapDiemGiuaKy);
        setDiemGiuaKy(convertDgk);
    }

    if (!nhapDiemCuoiKy.empty()) {
        float convertCuoiKy = stof(nhapDiemCuoiKy);
        setDiemCuoiKy(convertCuoiKy);
    }

    tinhDiemTongKet();
}



