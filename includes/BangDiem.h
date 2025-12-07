//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef BANGDIEM_H
#define BANGDIEM_H

#include "SinhVien.h"
#include "MonHoc.h"
#include "Diem.h"

class BangDiem {
private:
    SinhVien* sinhVien;
    MonHoc* monHoc;
    Diem* diem;

public:
    BangDiem();
    BangDiem(SinhVien* sinhVien, MonHoc* monHoc, Diem* diem);

    SinhVien* getSinhVien();
    MonHoc* getMonHoc();
    Diem* getDiem();

    void setSinhVien(SinhVien* sinhVien);
    void setMonHoc(MonHoc* monHoc);
    void setDiem(Diem* diem);

    void xuat();
};

#endif //BANGDIEM_H

