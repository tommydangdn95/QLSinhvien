//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/SinhVien.h"
#include <iostream>
#include <iomanip>
using namespace std;

SinhVien::SinhVien() {
    this->maSinhVien = "";
    this->hoTen = "";
    this->ngaySinh = "";
    this->lop = "";
    this->khoa = "";
}

SinhVien::SinhVien(string maSinhVien, string tenSinhVien, string ngaySinh, string lop, string khoa) {
    this->maSinhVien = maSinhVien;
    this->hoTen = tenSinhVien;
    this->ngaySinh = ngaySinh;
    this->lop = lop;
    this->khoa = khoa;
}

string SinhVien::getMaSV() { return maSinhVien; }
string SinhVien::getHoTen() { return hoTen; }
string SinhVien::getNgaySinh() { return ngaySinh; }
string SinhVien::getLop() { return lop; }
string SinhVien::getKhoa() { return khoa; }

void SinhVien::setMaSV(string maSinhVien) { this->maSinhVien = maSinhVien; }
void SinhVien::setHoTen(string hoTen) { this->hoTen = hoTen; }
void SinhVien::setNgaySinh(string ngaySinh) { this->ngaySinh = ngaySinh; }
void SinhVien::setLop(string lop) { this->lop = lop; }
void SinhVien::setKhoa(string khoa) { this->khoa = khoa; }


void SinhVien::nhap() {
    cout << "\nNhap ma sinh vien: ";
    cin.ignore();
    getline(cin, maSinhVien);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
    cout << "Nhap lop: ";
    getline(cin, lop);
    cout << "Nhap khoa: ";
    getline(cin, khoa);
}

void SinhVien::xuat() {
    cout << left << setw(12) << maSinhVien
         << setw(25) << hoTen
         << setw(15) << ngaySinh
         << setw(10) << lop
         << setw(20) << khoa << endl;
}
