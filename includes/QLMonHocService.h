//
// Created by Tommy-Asus on 12/13/2025.
//

#ifndef QLMONHOCSERVICE_H
#define QLMONHOCSERVICE_H
#include "MonHoc.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "MonHocDoublyList.h"

class QLMonHocService {
private:
    string FILE_NAME = "../monhoc.txt";
    MonHocDoublyList  danhSachMonHoc;
    void kiemTraFile();
public:
    QLMonHocService();
    void themMoiMonHoc(MonHoc* monHoc);
    void hienThiDanhSachMonHoc();
    vector<MonHoc*> getDanhSachMonHoc();
    MonHoc* timMonHocBangId(string maMonHoc);
    MonHoc* timMonHocBangIndex(int index);
    void luuMonHocVaoFile(MonHoc* monHoc);
    void docFileMonHOc();
};

#endif //QLMONHOCSERVICE_H
