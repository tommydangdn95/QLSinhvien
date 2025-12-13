//
// Created by Tommy-Asus on 12/13/2025.
//

#ifndef QLSINHVIENSERVICE_H
#define QLSINHVIENSERVICE_H
#include <iostream>
#include "MonHoc.h"
#include "Diem.h"
#include "LinkedList.h"
#include "Node.h"
#include "SinhVien.h"
#include <vector>
#include <fstream>

class QLSinhVienService {
private:
    string FILE_NAME = "../sinhvien.txt";
    vector<SinhVien*> danhSachSinhVien;
    void kiemTraFile();
public:
    QLSinhVienService();
    void themMoiSinhVien(SinhVien* sv);
    void hienThiDanhSachSinhVien();
    vector<SinhVien*> getDanhSachSinhVien();
    SinhVien* timSinhVienBangId(string maSinhVien);
    SinhVien* timSinhVienBangIndex(int index);
    void luuSinhVienVaoFile(SinhVien* sv);
    void docFileSinhVien();
};

#endif //QLSINHVIENSERVICE_H
