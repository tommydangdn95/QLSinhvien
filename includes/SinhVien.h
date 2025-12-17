//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>
using namespace std;

class SinhVien {
private:
    string maSinhVien;
    string hoTen;
    string ngaySinh;
    string lop;
    string khoa;

public:
    SinhVien();
    SinhVien(string maSinhVien, string hoTen, string ngaySinh, string lop, string khoa);

    string getMaSV();
    string getHoTen();
    string getNgaySinh();
    string getLop();
    string getKhoa();

    void setMaSV(string maSinhVien);
    void setHoTen(string hoTen);
    void setNgaySinh(string ngaySinh);
    void setLop(string lop);
    void setKhoa(string khoa);

    void nhap();
    string getThongTin();
    string getThongTinInLine();
    void capNhatThongTin();
};

#endif //SINHVIEN_H
