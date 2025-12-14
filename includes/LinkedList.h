//
// Created by Tommy-Asus on 12/7/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../includes/Node.h"
#include <iostream>
#include <fstream>
#include <map>

class LinkedList {
private:
    Node* head;
    int length;
public:
    LinkedList();
    int getLength();
    Node* getHead();
    void them(BangDiem* bangDiem);
    void hienThiDanhSachBangDiem();
    void sapXepDanhSachBangDiemTheoMaSinhVien();
    LinkedList* timBangDiemTheoMaSinhVien(SinhVien* sv);
    LinkedList* timBangDiemTheoMonHoc(MonHoc* monHoc);
    LinkedList* timDanhSachSinhVienDiemTongketThapNhat();
    LinkedList* timDanhSachSinhVienDiemTongketCaoNhat();
    map<string, int> getDanhSachTanSuatMonHocDuocDangKy();
    float tinhDiemTrungBinhCacMonCuaSinhVien(SinhVien* sinhVien);
    float tinhDiemTrungBinhTheoMonHoc(MonHoc* sinhVien);
    int tinhTongSoTinChiCuaSinhVien(SinhVien* sinhVien);
    int demSoMonHocSinhVienDaDangKy(SinhVien* sinhVien);
};

#endif //LINKEDLIST_H
