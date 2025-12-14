//
// Created by Tommy-Asus on 12/13/2025.
//

#include "../includes/AppService.h"
#include <sstream>
AppService::AppService() {
    this->kiemTraFile();
    this->docFileBangDiem();
}

// ========================================
// Mon Hoc
// ========================================

void AppService::themMoiMonHoc() {
    MonHoc* monHoc = new MonHoc();
    this->qlMonHocService.themMoiMonHoc(monHoc);
    this->qlMonHocService.luuMonHocVaoFile(monHoc);
}

void AppService::hienThiDanhSachMonHoc() {
    cout << "--- Danh sach mon hoc ---" << endl;
    this->qlMonHocService.hienThiDanhSachMonHoc();
}



// ========================================
// Sinh vien
// ========================================

void AppService::themMoiSinhVien() {
    SinhVien* sv = new SinhVien();
    this->qlSinhvienService.themMoiSinhVien(sv);
    this->qlSinhvienService.luuSinhVienVaoFile(sv);
}

void AppService::hienThiDanhSachSinhVien() {
    cout << "----- Danh sach sinh vien ----- " << endl;
    this->qlSinhvienService.hienThiDanhSachSinhVien();
}


// ========================================
// Bang Diem Sinh Vien
// ========================================

void AppService::themMoiDiemSinhVien() {
    vector<MonHoc*> danhSachMonHoc = this->qlMonHocService.getDanhSachMonHoc();
    vector<SinhVien*> danhSachSinhVien = this->qlSinhvienService.getDanhSachSinhVien();

    if (danhSachMonHoc.empty()) {
        cout << "Chua co mon hoc nao! " << endl;
        return;
    }

    if (danhSachSinhVien.empty()) {
        cout << "Chua co sinh vien nao! " << endl;
        return;
    }

    cout << "----- Danh sach sinh vien ----- " << endl;
    this->qlSinhvienService.hienThiDanhSachSinhVien();

    int sinhvienLuaChon;
    cout << "Nhap lua chon sinh vien:  ";
    if (!(cin >> sinhvienLuaChon)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Nhap khong hop le! Vui long nhap mot so." << endl;
        return;
    }

    sinhvienLuaChon = sinhvienLuaChon - 1;
    SinhVien* chonSv = this->qlSinhvienService.timSinhVienBangIndex(sinhvienLuaChon);
    if (chonSv == nullptr) {
        cout << "Chon sinh vien khong hop le hoac khong tim thay sinh vien! " << endl;
        return;
    }

    cout << "----- Danh sach mon hoc ----- " << endl;
    this->qlMonHocService.hienThiDanhSachMonHoc();

    int monHocLuaChon;
    cout << "Nhap mon hoc: ";
    if (!(cin >> monHocLuaChon)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Nhap khong hop le! Vui long nhap mot so." << endl;
        return;
    }

    monHocLuaChon = monHocLuaChon - 1;
    MonHoc* chonMonHoc = this->qlMonHocService.timMonHocBangIndex(monHocLuaChon);
    if (chonMonHoc == nullptr) {
        cout << "Chon mon hoc khong hop le hoac khong tim thay mon hoc! " << endl;
        return;
    }

    Diem* diem = new Diem();
    diem->nhap();

    BangDiem* bangDiem = new BangDiem(chonSv, chonMonHoc, diem);
    this->danhSachBangDiem.them(bangDiem);
    this->luuBangDiemVaoFile(bangDiem);
}

void AppService::luuBangDiemVaoFile(BangDiem *bangDiem) {
    ofstream file(this->FILE_NAME, ios::app);

    if (!file.is_open()) {
        cout << "Khong the mo tep tin" << endl;
        return;
    }

    file << bangDiem->getSinhVien()->getMaSV() << "|"
        << bangDiem->getSinhVien()->getHoTen() << "|"
        << bangDiem->getMonHoc()->getMaMon() << "|"
        << bangDiem->getMonHoc()->getTenMon() << "|"
        << bangDiem->getDiem()->getDiemChuyenCan() << "|"
        << bangDiem->getDiem()->getDiemGiuaKy() << "|"
        << bangDiem->getDiem()->getDiemCuoiKy() << "|" << endl;

    file.close();
    cout << "✓ Da them va luu bang diem! " << endl;
}

void AppService::docFileBangDiem() {
    ifstream file(this->FILE_NAME);
    if (!file.is_open()) {
        cout << "⚠ Chua co file, hay nhap mon hoc de them moi!\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string maSv, tenSinhVien, maMonHoc, tenMonHoc;
        float diemChuyenCan, diemGiuaKy, diemCuoiKy;
        char delimiter;

        getline(ss, maSv, '|');
        getline(ss, tenSinhVien, '|');
        getline(ss, maMonHoc, '|');
        getline(ss, tenMonHoc, '|');
        ss >> diemChuyenCan >> delimiter;
        ss >> diemGiuaKy >> delimiter;
        ss >> diemCuoiKy;

        SinhVien* sinhVien = this->qlSinhvienService.timSinhVienBangId(maSv);
        if (sinhVien == nullptr) {
            cout << "Khong tim thay sinh vien ma so: " << maSv << endl;
            continue;
        }

        MonHoc* monHoc = this->qlMonHocService.timMonHocBangId(maMonHoc);
        if (monHoc == nullptr) {
            cout << "Khong tim thay mon hoc ma so: " << maMonHoc << endl;
            continue;
        }

        Diem* diem = new Diem(diemChuyenCan, diemGiuaKy, diemCuoiKy);
        BangDiem * bangDiem = new BangDiem(sinhVien, monHoc, diem);
        this->danhSachBangDiem.them(bangDiem);
    }

    file.close();
    cout << "✓ Doc " << this->danhSachBangDiem.getLength() << " record bang diem!\n";
}

void AppService::kiemTraFile() {
    ifstream fileCheck(this->FILE_NAME);
    if (!fileCheck.is_open()) {
        cout << "⚠ File chua ton tai, dang tao file moi...\n";

        // Tạo file mới (rỗng)
        ofstream fileNew(this->FILE_NAME);
        fileNew.close();

        cout << "✓ Da tao file: " << this->FILE_NAME << "\n";
        return;
    }

    cout << "✓ File da ton tai!\n";
    fileCheck.close();
}

void AppService::hienThiDanhSachBangDiemSinhVien() {
    this->danhSachBangDiem.hienThiDanhSachBangDiem();
}



void AppService::sapXepDanhSachBangDiemTheoMaSinhVien() {

}