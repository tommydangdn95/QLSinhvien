//
// Created by Tommy-Asus on 12/7/2025.
//

#include "../includes/SinhVien.h"

#include <format>
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

string SinhVien::getThongTin() {
    string msg = format("MaSv: {} - Ho va Ten: {} - Ngay sinh: {} - Lop: {} - Khoa: {}",
            this->maSinhVien,
            this->hoTen,
            this->ngaySinh, this->lop, this->khoa);
    return msg;
}

void SinhVien::capNhatThongTin(string hoVaTen, string ngaySinh) {
    cout << "Cap nhat thong tin sinh vien:  " << maSinhVien << endl;
    this->setHoTen(hoVaTen);
    this->setNgaySinh(ngaySinh);
}
