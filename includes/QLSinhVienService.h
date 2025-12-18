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
#include "SinhVienStack.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class QLSinhVienService {
private:
    string FILE_NAME = "../sinhvien.txt";
    SinhVienStack  danhSachSinhVien;
    void kiemTraFile();
public:
    QLSinhVienService();
    void themMoiSinhVien(SinhVien* sv);
    void hienThiDanhSachSinhVien();
    void hienThiDanhSachSinhVien(vector<SinhVien*> listResult);
    vector<SinhVien*> getDanhSachSinhVien();
    SinhVien* timSinhVienBangId(string maSinhVien);
    SinhVien* timSinhVienBangIndex(int index);
    void luuSinhVienVaoFile(SinhVien* sv);
    void docFileSinhVien();
    void ghiDeFile();
    void removeSinhVien(SinhVien* sinhVien);
    void sortSinhVienTheoTen();
};

#endif //QLSINHVIENSERVICE_H
