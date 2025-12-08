//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef DIEM_H
#define DIEM_H

#include "MonHoc.h"
#include <string>
using namespace std;

class Diem {
private:
    float diemChuyenCan;
    float diemGiuaKy;
    float diemCuoiKy;
    float diemTongKet;

public:
    // Constructor
    Diem();
    Diem(MonHoc* monHoc, float diemChuyenCan, float diemGiuaKy, float diemCuoiKy);

    MonHoc* getMonHoc();
    float getDiemChuyenCan();
    float getDiemGiuaKy();
    float getDiemCuoiKy();
    float getDiemTongKet();

    void setDiemChuyenCan(float diemChuyenCan);
    void setDiemGiuaKy(float diemGiuaKy);
    void setDiemCuoiKy(float diemCuoiKy);

    void tinhDiemTongKet();
    string xepLoai();
    void nhap();
    void xuat();
};

#endif //DIEM_H
