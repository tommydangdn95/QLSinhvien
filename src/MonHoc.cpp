#include "../includes/MonHoc.h"
#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

MonHoc::MonHoc() {
    this->maMon = "";
    this->tenMon = "";
    this->soTinChi = 0;
}

MonHoc::MonHoc(string maMon, string tenMon, int soTinChi) {
    this->maMon = maMon;
    this->tenMon = tenMon;
    this->soTinChi = soTinChi;
}

string MonHoc::getMaMon() { return maMon; }
string MonHoc::getTenMon() { return tenMon; }
int MonHoc::getSoTinChi() { return soTinChi; }

void MonHoc::setMaMon(string maMon) { this->maMon = maMon; }
void MonHoc::setTenMon(string tenMon) { this->tenMon = tenMon; }
void MonHoc::setSoTinChi(int soTinChi) { this->soTinChi = soTinChi; }

void MonHoc::nhap() {
    cout << "\nNhap ma mon: ";
    cin.ignore();
    getline(cin, maMon);
    cout << "Nhap ten mon: ";
    getline(cin, tenMon);
    cout << "Nhap so tin chi: ";
    cin >> soTinChi;
}

void MonHoc::xuat() {
    cout << left << setw(10) << maMon 
         << setw(30) << tenMon 
         << setw(10) << soTinChi << endl;
}