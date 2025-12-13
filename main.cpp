#include <iostream>
#include "includes/MonHoc.h"
#include "includes/Diem.h"
#include "includes/LinkedList.h"
#include "includes/Node.h"
#include "includes/SinhVien.h"
#include <vector>

#include "includes/AppService.h"
#include "includes/QLSinhVienService.h"

int main() {
    AppService appSerivce;

    int luaChon;

    do {
        cout << "\n========== QUAN LY DIEM SINH VIEN ==========" << endl;
        cout << "1. Them mon hoc" << endl;
        cout << "2. Them sinh vien" << endl;
        cout << "3. Them diem sinh vien" << endl;
        cout << "4. Hien Thi danh sach sinh vien" << endl;
        cout << "5. Hien Thi danh sach mon hoc" << endl;
        cout << "6. Hien thi danh sach bang diem tat ca sinh vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "============================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        
        switch (luaChon)
        {
            case 1:
                appSerivce.themMoiMonHoc();
                break;
            case 2:
                appSerivce.themMoiSinhVien();
                break;
            case 3:
                appSerivce.themMoiDiemSinhVien();
                break;
            case 4:
                appSerivce.hienThiDanhSachSinhVien();
                break;
            case 5:
                appSerivce.hienThiDanhSachMonHoc();
            case 6:
                appSerivce.hienThiDanhSachBangDiemSinhVien();
            break;
            default:
                break;
        }


    } while (luaChon != 0);

    return 0;
}
