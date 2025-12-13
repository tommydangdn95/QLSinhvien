//
// Created by Tommy-Asus on 12/7/2025.
//
#include <string>
#include <iomanip>

#ifndef MONHOC_H
#define MONHOC_H
#include <string>
using namespace std;

class MonHoc {
private:
    string maMon;
    string tenMon;
    int soTinChi;

public:
    MonHoc();
    MonHoc(string maMon, string tenMon, int soTinChi);

    string getMaMon();
    string getTenMon();
    int getSoTinChi();

    void setMaMon(string ma);
    void setTenMon(string ten);
    void setSoTinChi(int tc);

    void nhap();
    string getThongTin();

};

#endif //MONHOC_H
