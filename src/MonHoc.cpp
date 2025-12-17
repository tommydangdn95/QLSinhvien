#include "../includes/MonHoc.h"
#include <iostream>
#include <iomanip>
#include <format>
#include <string>
#include <sstream>
using namespace std;

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

string MonHoc::getThongTin() {
    string msg = format("Ma MonHoc: {} - Ten Mon Hoc: {} - So tin chi: {}",
            this->maMon,
            this->tenMon,
            this->soTinChi);
    return msg;
}

void MonHoc::capNhatThongTin() {
    string nhapTenMon;
    string nhapSoTinChi;
    cout << "Thay doi thong tin mon hoc: " << maMon << endl;
    cout << "Nhap ten mon: ";
    cin.ignore();
    getline(cin, nhapTenMon);
    cout << "Nhap so tin chi: ";
    getline(cin, nhapSoTinChi);

    if (!nhapTenMon.empty()) {
        setTenMon(nhapTenMon);
    }

    if (!nhapSoTinChi.empty()) {
        int convertSoTinChi = stoi(nhapSoTinChi);
        setSoTinChi(convertSoTinChi);
    }
}

string MonHoc::getThongTinInLine() {
    stringstream ss;
    ss << this->maMon << "|"
        << this->tenMon << "|"
        << this->soTinChi << "|";
    return ss.str();
}