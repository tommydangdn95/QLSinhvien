#include <iostream>
#include "includes/MonHoc.h"
#include "includes/Diem.h"
#include "includes/LinkedList.h"
#include "includes/Node.h"
#include "includes/SinhVien.h"
#include <iostream>
#include <vector>

void themMoiSinhVien(vector<SinhVien*> danhSachSinhVien) {
    SinhVien* sv = new SinhVien();
    sv->nhap();
    danhSachSinhVien.push_back(sv);
}

void themMoiMonHoc(vector<MonHoc*> danhSachMonHoc) {
    MonHoc* monHoc = new MonHoc();
    monHoc->nhap();
    danhSachMonHoc.push_back(monHoc);
}

int main() {
    vector<MonHoc*> danhSachMonHoc;
    vector<SinhVien*> danhSachSinhVien;
    LinkedList danhSachBangDiem;

    int luaChon;

    do {
        cout << "\n========== QUAN LY DIEM SINH VIEN ==========" << endl;
        cout << "1. Them mon hoc" << endl;
        cout << "2. Them sinh vien" << endl;
        cout << "7. Hien thi bang diem cua 1 sinh vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "============================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        
        switch (luaChon)
        {
            case 1:
                themMoiMonHoc(danhSachMonHoc);
                break;
            
            default:
                break;
        }


    } while (luaChon != 0);

    themMoiSinhVien(danhSachSinhVien);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
