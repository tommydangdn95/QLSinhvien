#include <iostream>
#include "includes/MonHoc.h"
#include "includes/Diem.h"
#include "includes/LinkedList.h"
#include "includes/Node.h"
#include "includes/SinhVien.h"
#include <vector>

void themMoiSinhVien(vector<SinhVien*>& danhSachSinhVien) {
    SinhVien* sv = new SinhVien();
    sv->nhap();
    danhSachSinhVien.push_back(sv);
}

void themMoiMonHoc(vector<MonHoc*>& danhSachMonHoc) {
    MonHoc* monHoc = new MonHoc();
    monHoc->nhap();
    danhSachMonHoc.push_back(monHoc);
}

SinhVien* timSinhVienBangId(vector<SinhVien*>& danhsachSinhvien, string maSinhVien) {
    if (maSinhVien.empty()) {
        return nullptr;
    }

    for (int i = 0; i < danhsachSinhvien.size(); i++) {
        if (danhsachSinhvien[0]->getMaSV() == maSinhVien) {
            return danhsachSinhvien[i];
        }
    }

    return nullptr;
}

MonHoc* timMonHocBangId(vector<MonHoc*>& danhsachMonHoc, string maMonHoc) {
    if (maMonHoc.empty()) {
        return nullptr;
    }

    for (int i = 0; i < danhsachMonHoc.size(); i++) {
        if (danhsachMonHoc[0]->getMaMon() == maMonHoc) {
            return danhsachMonHoc[i];
        }
    }

    return nullptr;
}

void themMoiDiemSinhVien(vector<MonHoc*>& danhSachMonHoc, vector<SinhVien*>& danhSachSinhVien, LinkedList& danhSachBangDiem) {
    if (danhSachMonHoc.empty()) {
        cout << "Chua co mon hoc nao! " << endl;
        return;
    }

    if (danhSachSinhVien.empty()) {
        cout << "Chua co sinh vien nao! " << endl;
        return;
    }

    cout << "----- Danh sach sinh vien ----- " << endl;
    for(int i = 0 ; i < danhSachSinhVien.size(); i++) {
        cout << i + 1 << ". " << danhSachSinhVien[i]->getMaSV() << " - " << danhSachSinhVien[i]->getHoTen() << endl;
    }

    string maChonSv;
    cout << "Nhap ma chon sinh vien:  ";
    cin.ignore();
    getline(cin, maChonSv);

    SinhVien* chonSv = timSinhVienBangId(danhSachSinhVien, maChonSv);
    if (chonSv == nullptr) {
        cout << "Chon sinh vien khong hop le hoac khong tim thay sinh vien! " << endl;
        return;
    }

    cout << "--- Danh sach mon hoc ---" << endl;
    for (int i = 0; i < danhSachMonHoc.size(); i++) {
        cout << i + 1 << ". " << danhSachMonHoc[i]->getMaMon() << " - " << danhSachMonHoc[i]->getTenMon() << endl;
    }

    string maChonMonHoc;
    cout << "Nhap ma chon mon hoc: ";
    getline(cin, maChonMonHoc);

    MonHoc* chonMonHoc = timMonHocBangId(danhSachMonHoc, maChonMonHoc);
    if (chonMonHoc == nullptr) {
        cout << "Chon mon hoc khong hop le hoac khong tim thay mon hoc! " << endl;
        return;
    }

    Diem* diem = new Diem();
    diem->nhap();

    BangDiem* bangDiem = new BangDiem(chonSv, chonMonHoc, diem);
    danhSachBangDiem.them(bangDiem);
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
        cout << "3. Them bang diem sinh vien" << endl;
        cout << "4. Hien thi danh sach bang diem tat ca sinh vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "============================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        
        switch (luaChon)
        {
            case 1:
                themMoiMonHoc(danhSachMonHoc);
                break;
            case 2:
                themMoiSinhVien(danhSachSinhVien);
                break;
            case 3:
                themMoiDiemSinhVien(danhSachMonHoc, danhSachSinhVien, danhSachBangDiem);
                break;
            case 4:
                danhSachBangDiem.xuatHetThongTin();
                break;
            break;
            default:
                break;
        }


    } while (luaChon != 0);

    return 0;
}
