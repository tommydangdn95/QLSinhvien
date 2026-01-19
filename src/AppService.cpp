//
// Created by Tommy-Asus on 12/13/2025.
//

#include "../includes/AppService.h"
#include <string>
#include <sstream>
#include <set>
using namespace std;

AppService::AppService() {
    this->kiemTraFile();
    this->docFileBangDiem();
}


// ========================================
// ===== File Operation =====

void AppService::luuBangDiemVaoFile(BangDiem *bangDiem) {
    ofstream file(this->FILE_NAME, ios::app);

    if (!file.is_open()) {
        cout << "File could not be opened" << endl;
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
    cout << "Da them va luu bang diem! " << endl;
}

void AppService::docFileBangDiem() {
    ifstream file(this->FILE_NAME);
    if (!file.is_open()) {
        cout << "Chua co file, hay nhap mon hoc de them moi!\n";
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
    cout << "Doc " << this->danhSachBangDiem.getLength() << " record bang diem!\n";
}

void AppService::kiemTraFile() {
    ifstream fileCheck(this->FILE_NAME);
    if (!fileCheck.is_open()) {
        cout << "File chua ton tai, dang tao file moi...\n";

        // Tạo file mới (rỗng)
        ofstream fileNew(this->FILE_NAME);
        fileNew.close();

        cout << "Da tao file: " << this->FILE_NAME << "\n";
        return;
    }

    cout << "File da ton tai!\n";
    fileCheck.close();
}

void AppService::ghiDeFile() {
    ofstream file(this->FILE_NAME);  // ← XÓA file cũ tự động
        
    if (!file.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    Node* temp = this->danhSachBangDiem.getHead();
    while (temp != nullptr) {
        BangDiem* bangDiem = temp->data;
        file << bangDiem->getThongTinInLine() << endl;
        temp = temp->next;
    }

    file.close();
}

// ========================================
// ===== NHAP, Sua, Xoa DU LIEU =====

// 1. Them mon hoc
void AppService::themMoiMonHoc() {
    MonHoc* monHoc = new MonHoc();
    this->qlMonHocService.themMoiMonHoc(monHoc);
    this->qlMonHocService.luuMonHocVaoFile(monHoc);
}

// 2. Them sinh vien
void AppService::themMoiSinhVien() {
    SinhVien* sv = new SinhVien();
    this->qlSinhvienService.themMoiSinhVien(sv);
    this->qlSinhvienService.luuSinhVienVaoFile(sv);
}


//3. Them diem sinh vien
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
    cin >> sinhvienLuaChon;

    sinhvienLuaChon = sinhvienLuaChon - 1;
    SinhVien* chonSv = this->qlSinhvienService.timSinhVienBangIndex(sinhvienLuaChon);
    if (chonSv == nullptr) {
        cout << "Chon sinh vien khong hop le hoac khong tim thay sinh vien! " << endl;
        return;
    }

    cout << "----- Danh sach mon hoc ----- " << endl;
    this->qlMonHocService.hienThiDanhSachMonHoc();

    int monHocLuaChon;
    cout << "Nhap ma chon mon hoc: ";
    cin >> monHocLuaChon;

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

//4. Sua thong tin mon hoc
void AppService::capNhatThongTinMonHoc() {
    vector<MonHoc*> danhSachMonHoc = this->qlMonHocService.getDanhSachMonHoc();
    if (danhSachMonHoc.empty()) {
        cout << "Chua co mon hoc nao! " << endl;
        return;
    }

    cout << "----- Danh sach mon hoc ----- " << endl;
    this->qlMonHocService.hienThiDanhSachMonHoc();

    int monHocLuaChon;
    cout << "Nhap ma chon mon hoc (1 - " << danhSachMonHoc.size() << "): ";
    cin >> monHocLuaChon;

    monHocLuaChon = monHocLuaChon - 1;
    MonHoc* chonMonHoc = this->qlMonHocService.timMonHocBangIndex(monHocLuaChon);
    if (chonMonHoc == nullptr) {
        cout << "Chon mon hoc khong hop le hoac khong tim thay mon hoc! " << endl;
        return;
    }
     
    chonMonHoc->capNhatThongTin();
    this->qlMonHocService.ghiDeFile();

    this->danhSachBangDiem.capNhatBangDiemBangMonHoc(chonMonHoc);
    this->ghiDeFile();

    cout << "Cap nhat thong tin thanh cong" << endl;
}

//5. Sua thong tin sinh vien
void AppService::capNhatThongTinSinhVien() {
    vector<SinhVien*> danhSachSinhVien = this->qlSinhvienService.getDanhSachSinhVien();

    if (danhSachSinhVien.empty()) {
        cout << "Chua co sinh vien nao! " << endl;
        return;
    }

    cout << "----- Danh sach sinh vien ----- " << endl;
    this->qlSinhvienService.hienThiDanhSachSinhVien();

    int sinhvienLuaChon;
    cout << "Nhap lua chon sinh vien:  ";
    cin >> sinhvienLuaChon;

    sinhvienLuaChon = sinhvienLuaChon - 1;
    SinhVien* chonSv = this->qlSinhvienService.timSinhVienBangIndex(sinhvienLuaChon);
    if (chonSv == nullptr) {
        cout << "Chon sinh vien khong hop le hoac khong tim thay sinh vien! " << endl;
        return;
    }

    chonSv->capNhatThongTin();
    this->qlSinhvienService.ghiDeFile();

    this->danhSachBangDiem.capNhatBangDiemBangSinhVien(chonSv);
    this->ghiDeFile();
}

//6. Sua diem sinh vien
void AppService::capNhatThongTinBangDiem() {
    this->danhSachBangDiem.hienThiDanhSachBangDiem();

    int bangDiemchon;
    cout << "Nhap lua chon bang diem:  ";
    cin >> bangDiemchon;

    bangDiemchon = bangDiemchon - 1;
    BangDiem* bangDiem = this->danhSachBangDiem.timBangDiemTheoIndex(bangDiemchon);
    bangDiem->capNhatThongTin();
    this->ghiDeFile();
}

//7. Xoa mon hoc
void AppService::xoaMonHoc() {
    vector<MonHoc*> danhSachMonHoc = this->qlMonHocService.getDanhSachMonHoc();
    if (danhSachMonHoc.empty()) {
        cout << "Chua co mon hoc nao! " << endl;
        return;
    }

    cout << "----- Danh sach mon hoc ----- " << endl;
    this->qlMonHocService.hienThiDanhSachMonHoc();

    int monHocLuaChon;
    cout << "Nhap ma chon mon hoc (1 - " << danhSachMonHoc.size() << "): ";
    cin >> monHocLuaChon;

    monHocLuaChon = monHocLuaChon - 1;
    MonHoc* chonMonHoc = this->qlMonHocService.timMonHocBangIndex(monHocLuaChon);
    if (chonMonHoc == nullptr) {
        cout << "Chon mon hoc khong hop le hoac khong tim thay mon hoc! " << endl;
        return;
    }

    this->qlMonHocService.xoaMonHoc(chonMonHoc);
    this->qlMonHocService.ghiDeFile();

    this->danhSachBangDiem.capNhatBangDiemKhiXoaMonHoc(chonMonHoc);
    this->ghiDeFile();
    cout << "Xoa mon hoc " << chonMonHoc->getMaMon() << " thanh cong" << endl;
}



//8. Xoa sinh vien
void AppService::xoaSinhVien() {
    vector<SinhVien*> danhSachSinhVien = this->qlSinhvienService.getDanhSachSinhVien();

    if (danhSachSinhVien.empty()) {
        cout << "Chua co sinh vien nao! " << endl;
        return;
    }

    cout << "----- Danh sach sinh vien ----- " << endl;
    this->qlSinhvienService.hienThiDanhSachSinhVien();

    int sinhvienLuaChon;
    cout << "Nhap lua chon sinh vien:  ";
    cin >> sinhvienLuaChon;

    sinhvienLuaChon = sinhvienLuaChon - 1;
    SinhVien* chonSv = this->qlSinhvienService.timSinhVienBangIndex(sinhvienLuaChon);
    if (chonSv == nullptr) {
        cout << "Chon sinh vien khong hop le hoac khong tim thay sinh vien! " << endl;
        return;
    }

    this->qlSinhvienService.removeSinhVien(chonSv);
    this->qlSinhvienService.ghiDeFile();

    this->danhSachBangDiem.capNhatBangDiemKhiXoaSinhVien(chonSv);
    this->ghiDeFile();
    cout << "Xoa sinh vien " << chonSv->getMaSV() << " thanh cong" << endl;
}

//9. Xoa diem sinh vien
void AppService::xoaBangDiem() {
    this->danhSachBangDiem.hienThiDanhSachBangDiem();

    int bangDiemchon;
    cout << "Nhap lua chon bang diem:  ";
    cin >> bangDiemchon;

    bangDiemchon = bangDiemchon - 1;
    BangDiem* bangDiem = this->danhSachBangDiem.timBangDiemTheoIndex(bangDiemchon);
    this->danhSachBangDiem.capNhatBangDiemKhiXoaBangDiem(bangDiem);
    this->ghiDeFile();
    cout << "Xoa bang diem sinh vien " << bangDiem->getSinhVien()->getMaSV() << " mon hoc " << bangDiem->getMonHoc()->getMaMon() << " thanh cong" << endl;
}



// ========================================
// ===== HIEN THI DU LIEU ===== =====

// 10. Hien thi danh sach sinh vien
void AppService::hienThiDanhSachMonHoc() {
    cout << "--- Danh sach mon hoc ---" << endl;
    this->qlMonHocService.hienThiDanhSachMonHoc();
}

// 11. Hien thi danh sach mon hoc
void AppService::hienThiDanhSachSinhVien() {
    cout << "----- Danh sach sinh vien ----- " << endl;
    this->qlSinhvienService.hienThiDanhSachSinhVien();
}

// 12. Hien thi danh sach bang diem
void AppService::hienThiDanhSachBangDiemSinhVien() {
    this->danhSachBangDiem.hienThiDanhSachBangDiem();
}

// ========================================
// ===== TIM KIEM ===== ===== =====


// 13. Tim bang diem sinh vien theo ma SV
void AppService::timDanhSachBangDiemSinhVienBangMaSv() {
    vector<SinhVien*> danhSachSinhVien = this->qlSinhvienService.getDanhSachSinhVien();


    if (danhSachSinhVien.empty()) {
        cout << "Chua co sinh vien nao! " << endl;
        return;
    }

    cout << "----- Danh sach sinh vien ----- " << endl;
    this->qlSinhvienService.hienThiDanhSachSinhVien();

    int sinhvienLuaChon;
    cout << "Nhap lua chon sinh vien:  ";
    cin >> sinhvienLuaChon;

    sinhvienLuaChon = sinhvienLuaChon - 1;
    SinhVien* chonSv = this->qlSinhvienService.timSinhVienBangIndex(sinhvienLuaChon);
    if (chonSv == nullptr) {
        cout << "Chon sinh vien khong hop le hoac khong tim thay sinh vien! " << endl;
        return;
    }

    LinkedList* listResult = this->danhSachBangDiem.timBangDiemTheoMaSinhVien(chonSv);
    if (listResult->getLength() == 0) {
        cout << "Khong tim thay bang diem nao cua sinh vien: " << chonSv->getMaSV() << endl;
        return;
    }

    listResult->hienThiDanhSachBangDiem();
}

// 14. Tim bang diem sinh vien theo ma SV
void AppService::timDanhSachBangDiemSinhVienBangMaMonHoc() {
    vector<MonHoc*> danhSachMonHoc = this->qlMonHocService.getDanhSachMonHoc();

    if (danhSachMonHoc.empty()) {
        cout << "Chua co mon hoc nao! " << endl;
        return;
    }

    cout << "----- Danh sach mon hoc ----- " << endl;
    this->qlMonHocService.hienThiDanhSachMonHoc();

    int monHocLuaChon;
    cout << "Nhap ma chon mon hoc: ";
    cin >> monHocLuaChon;

    monHocLuaChon = monHocLuaChon - 1;
    MonHoc* chonMonHoc = this->qlMonHocService.timMonHocBangIndex(monHocLuaChon);
    if (chonMonHoc == nullptr) {
        cout << "Chon mon hoc khong hop le hoac khong tim thay mon hoc! " << endl;
        return;
    }

    LinkedList* listResult = this->danhSachBangDiem.timBangDiemTheoMonHoc(chonMonHoc);
    if (listResult->getLength() == 0) {
        cout << "Khong tim thay bang diem sinh vien nao cua mon hoc: " << chonMonHoc->getMaMon() << endl;
        return;
    }

    listResult->hienThiDanhSachBangDiem();
}


// ========================================
// ===== Sap Xep  ===== =====

void AppService::sapXepMonHocTheoTen() {
    this->qlMonHocService.sortMonHocTheoTen();
    cout << "Sap xep danh sach mon hoc thanh cong theo ten" << endl;
    this->hienThiDanhSachMonHoc();
}

void AppService::sapXepSinhVienTheoTen() {
    this->qlSinhvienService.sortSinhVienTheoTen();
    cout << "Sap xep danh sach sinh vien thanh cong theo ten" << endl;
    this->hienThiDanhSachSinhVien();
}

void AppService::sapXepBangDiemTheoMaSv() {
    this->danhSachBangDiem.sapXepDanhSachBangDiemTheoMaSinhVien();
    cout << "Sap xep danh sach sinh vien thanh cong theo ma sinh vien" << endl;
    this->hienThiDanhSachBangDiemSinhVien();
}

void AppService::sapXepBangDiemTheoDiemTrungBinh() {
    this->danhSachBangDiem.sapXepBangDiemTheoDiemTrungBinh();
    cout << "Sap xep danh sach sinh vien thanh cong theo diem trung binh" << endl;
    this->hienThiDanhSachBangDiemSinhVien();
}


// ========================================
// ===== TIM MIN/MAX, Tinh Toan, Tong  ===== =====

// 19.Tim sinh vien co diem TB cao nhat
void AppService::timSinhVienDiemTongketThapNhat() {
    LinkedList* listResult = this->danhSachBangDiem.timDanhSachSinhVienDiemTongketThapNhat();
    listResult->hienThiDanhSachBangDiem();
}

// 20.Tim sinh vien co diem TB thap nhat
void AppService::timSinhVienDiemTongketCaoNhat() {
    LinkedList* listResult = this->danhSachBangDiem.timDanhSachSinhVienDiemTongketCaoNhat();
    listResult->hienThiDanhSachBangDiem();
}

// 21. Tim sinh vien dang ky nhieu mon nhat
void AppService::timMonHocSinhVienDangKiNhieuNhat() {
    map<string, int> frequency = this->danhSachBangDiem.getDanhSachTanSuatMonHocDuocDangKy();

    int maxCountFrequency = frequency.begin()->second;
    for (pair<string, int> key: frequency) {
        if (key.second > maxCountFrequency) {
            maxCountFrequency = key.second;
        }
    }

    int show = 0;
    for (pair<string, int> key: frequency) {
        if (key.second ==  maxCountFrequency) {
            MonHoc* monHoc = this->qlMonHocService.timMonHocBangId(key.first);
            if (monHoc != nullptr) {
                cout << monHoc->getThongTin() << endl;
                show++;
            }
        }
    }

    if (show == 0) {
        cout << "Khong tim thay mon hoc nao";
        return;
    }
}

// 22. Tim sinh vien dang ky it mon nhat
void AppService::timMonHocSinhVienDangKiItMonNhat() {
    map<string, int> frequency = this->danhSachBangDiem.getDanhSachTanSuatMonHocDuocDangKy();

    int minCountFrequency = frequency.begin()->second;
    for (pair<string, int> key: frequency) {
        if (key.second < minCountFrequency) {
            minCountFrequency = key.second;
        }
    }

    int show = 0;
    for (pair<string, int> key: frequency) {
        if (key.second ==  minCountFrequency) {
            MonHoc* monHoc = this->qlMonHocService.timMonHocBangId(key.first);
            if (monHoc != nullptr) {
                cout << monHoc->getThongTin() << endl;
                show++;
            }
        }
    }

    if (show==0) {
        cout << "Khong tim thay mon hoc nao";
        return;
    }
}


// 23. Hien thi danh sach diem TB sinh vien
void AppService::hienThiDanhSachDiemTrungBinhSinhVien() {
    if (this->qlSinhvienService.getDanhSachSinhVien().empty()) {
        cout << "Danh sach sinh vien trong";
        return;
    }

    vector<SinhVien*> danhSachSinhVien = this->qlSinhvienService.getDanhSachSinhVien();

    for (SinhVien* sinhVien: danhSachSinhVien) {
        float diemTrungBinh = this->danhSachBangDiem.tinhDiemTrungBinhCacMonCuaSinhVien(sinhVien);
        cout << "Ma sinh vien: "
                << sinhVien->getMaSV()
                << " - Ho va ten: " << sinhVien->getHoTen()
                << " - Diem trung binh cac mon: " << diemTrungBinh << endl;
    }
}

// 24. Hien thi danh sach diem trung binh theo cac mon
void AppService::hienThiDanhSachDiemTrungBinhTheoMonHoc() {
    if (this->qlMonHocService.getDanhSachMonHoc().empty()) {
        cout << "Danh sach mon hoc trong";
        return;
    }

    vector<MonHoc*> danhSachMonHoc = this->qlMonHocService.getDanhSachMonHoc();

    for (MonHoc* monHoc: danhSachMonHoc) {
        float diemTrungBinh = this->danhSachBangDiem.tinhDiemTrungBinhTheoMonHoc(monHoc);
        cout << "Ma mon hoc: "
                << monHoc->getMaMon()
                << " - Ten mon hoc: " << monHoc->getTenMon()
                << " - Diem trung binh: " << diemTrungBinh << endl;
    }
}

// 25. Hien thi danh sach tong so tin chi sinh vien dang ky
void AppService::hienThiDanhSachTongSoTinChiCuaSinhVien() {
    vector<SinhVien*> danhSachSinhVien = this->qlSinhvienService.getDanhSachSinhVien();

    if (danhSachSinhVien.empty()) {
        cout << "Danh sach sinh vien trong";
        return;
    }

    for (SinhVien* sinhVien: danhSachSinhVien) {
        int tongSoTinChi = this->danhSachBangDiem.tinhTongSoTinChiCuaSinhVien(sinhVien);
        cout << "Ma sinh vien: "
                << sinhVien->getMaSV()
                << " - Ho va ten: " << sinhVien->getHoTen()
                << " - Tong so tin chi cac mon: " << tongSoTinChi << endl;
    }
}

// 26. Dem so sinh vien dat loai gioi
void AppService::demSoSinhVienDatLoaiGioi() {
    if (this->qlSinhvienService.getDanhSachSinhVien().empty()) {
        cout << "Danh sach sinh vien trong";
        return;
    }

    vector<SinhVien*> danhSachSinhVien = this->qlSinhvienService.getDanhSachSinhVien();

    int count = 0;
    for (SinhVien* sinhVien: danhSachSinhVien) {
        float diemTrungBinh = this->danhSachBangDiem.tinhDiemTrungBinhCacMonCuaSinhVien(sinhVien);
        XepLoai xepLoai = getXepLoaiTheoDiemTrungBinh(diemTrungBinh);
        if (xepLoai == XepLoai::Gioi) {
            count+= 1;
        }
    }

    if (count == 0) {
        cout << "Khong co sinh vien nao xep hang gioi" << endl;
        return;
    }

    cout << "So sinh vien dat loai gioi: " << count << endl;
}

// 27. dem so mon hoc sinh vien dang ky
void AppService::demSoMonHocSinhVienDangKy() {
    vector<SinhVien*> danhSachSinhVien = this->qlSinhvienService.getDanhSachSinhVien();


    if (danhSachSinhVien.empty()) {
        cout << "Chua co sinh vien nao! " << endl;
        return;
    }

    cout << "----- Danh sach sinh vien ----- " << endl;
    this->qlSinhvienService.hienThiDanhSachSinhVien();

    int sinhvienLuaChon;
    cout << "Nhap lua chon sinh vien:  ";
    cin >> sinhvienLuaChon;

    sinhvienLuaChon = sinhvienLuaChon - 1;
    SinhVien* chonSv = this->qlSinhvienService.timSinhVienBangIndex(sinhvienLuaChon);
    if (chonSv == nullptr) {
        cout << "Chon sinh vien khong hop le hoac khong tim thay sinh vien! " << endl;
        return;
    }

    int count = this->danhSachBangDiem.demSoMonHocSinhVienDaDangKy(chonSv);

    if (count == 0) {
        cout << "Sinh vien "<< chonSv->getHoTen() << " chua dang ki mon nao" << endl;
        return;
    }

    cout << "Sinh vien: " << chonSv->getHoTen() << " da dang ki " << count << " mon" << endl;
}

// 28. Thong ke so sinh vien theo mon hoc
void AppService::thongKeSoSinhVienDangHocMonHoc() {
    cout << "\n========== Thong ke so sinh vien dang hoc theo mon hoc ==========" << endl;
    vector<MonHoc*> danhSach = this->qlMonHocService.getDanhSachMonHoc();

    for (int i = 0; i < danhSach.size(); i++) {
        int count = 0;
        set<string> studentIds;

        Node* temp = this->danhSachBangDiem.getHead();
        while (temp != nullptr) {
            if (temp->data->getMonHoc()->getMaMon() == danhSach[i]->getMaMon()) {
                studentIds.insert(temp->data->getSinhVien()->getMaSV());
                count++;
            }
            temp = temp->next;
        }

        cout << i + 1 << ". " << danhSach[i]->getTenMon() << " - So sinh vien: " << count << endl;
    }
}

// 29.Thong ke sinh vien Gioi theo mon hoc
void AppService::thongKeSoSinhVienDatLoaiGioiTheoMonHoc() {
    cout << "\n========== Thong ke sinh vien dat loai Gioi theo mon hoc ==========" << endl;
    vector<MonHoc*> danhSach = this->qlMonHocService.getDanhSachMonHoc();

    for (int i = 0; i < danhSach.size(); i++) {
        int count = 0;
        vector<string> gioiStudents;

        Node* temp = this->danhSachBangDiem.getHead();
        while (temp != nullptr) {
            if (temp->data->getMonHoc()->getMaMon() == danhSach[i]->getMaMon()) {
                float score = temp->data->getDiem()->getDiemTongKet();
                if (score >= 8.5) {
                    count++;
                    gioiStudents.push_back(temp->data->getSinhVien()->getHoTen());
                }
            }
            temp = temp->next;
        }

        cout << i + 1 << ". " << danhSach[i]->getTenMon() << " - So sinh vien Gioi: " << count;
        if (count > 0) {
            cout << " (";
            for (int j = 0; j < gioiStudents.size(); j++) {
                cout << gioiStudents[j];
                if (j < gioiStudents.size() - 1) cout << ", ";
            }
            cout << ")";
        }
        cout << endl;
    }
}

//30. Thong ke sinh vien co GPA > 9
void AppService::thongKeSoSinhVienDatLoaiGPAXuaSac() {
    cout << "\n========== Thong ke sinh vien co diem TB tren 9.0 ==========" << endl;
    int count = 0;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();
    vector<pair<string, float>> excellentStudents;

    for (SinhVien* sv : danhSach) {
        float totalScore = 0;
        int countSubjects = 0;

        Node* temp = this->danhSachBangDiem.getHead();
        while (temp != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() == sv->getMaSV()) {
                totalScore += temp->data->getDiem()->getDiemTongKet();
                countSubjects++;
            }
            temp = temp->next;
        }

        if (countSubjects > 0) {
            float gpa = totalScore / countSubjects;
            if (gpa > 9) {
                count++;
                excellentStudents.push_back({sv->getHoTen(), gpa});
            }
        }
    }

    cout << "So sinh vien co diem TB > 9.0: " << count << endl;
    if (count > 0) {
        cout << "\nDanh sach:" << endl;
        for (int i = 0; i < excellentStudents.size(); i++) {
            cout << i + 1 << ". " << excellentStudents[i].first << " - Diem TB: " << excellentStudents[i].second << endl;
        }
    }
}

// 31.Thong ke so sinh vien theo loai diem
void AppService::thongKeSoSinhVienTheoLoaiDiem() {
    cout << "\n========== Thong ke so sinh vien theo loai diem ==========" << endl;

    int gioi = 0, kha = 0, trungBinh = 0, yeu = 0, kem = 0;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();

    for (SinhVien* sv : danhSach) {
        float totalScore = 0;
        int count = 0;

        Node* temp = this->danhSachBangDiem.getHead();
        while (temp != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() == sv->getMaSV()) {
                totalScore += temp->data->getDiem()->getDiemTongKet();
                count++;
            }
            temp = temp->next;
        }

        if (count > 0) {
            float gpa = totalScore / count;
            if (gpa >= 8.5) gioi++;
            else if (gpa >= 7.0) kha++;
            else if (gpa >= 5.5) trungBinh++;
            else if (gpa >= 4.0) yeu++;
            else kem++;
        }
    }

    cout << "Gioi (>= 8.5): " << gioi << " sinh vien" << endl;
    cout << "Kha (7.0 - 8.5): " << kha << " sinh vien" << endl;
    cout << "Trung binh (5.5 - 7.0): " << trungBinh << " sinh vien" << endl;
    cout << "Yeu (4.0 - 5.5): " << yeu << " sinh vien" << endl;
    cout << "Kem (< 4.0): " << kem << " sinh vien" << endl;
}

//32. Thong ke so sinh vien theo loai diem
void AppService::thongKeDiemTrungBinhSinhVienTheoLop() {
    cout << "\n========== Thong ke diem trung binh sinh vien theo lop ==========" << endl;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();

    if (danhSach.empty()) {
        cout << "Khong co sinh vien nao!" << endl;
        return;
    }

    // Group by class and calculate average
    map<string, pair<float, int>> lopMap; // lop -> (totalScore, count)

    for (SinhVien* sv : danhSach) {
        float totalScore = 0;
        int count = 0;

        Node* temp = this->danhSachBangDiem.getHead();
        while (temp != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() == sv->getMaSV()) {
                totalScore += temp->data->getDiem()->getDiemTongKet();
                count++;
            }
            temp = temp->next;
        }

        if (count > 0) {
            string lop = sv->getLop();
            if (lopMap.find(lop) == lopMap.end()) {
                lopMap[lop] = {totalScore / count, 1};
            } else {
                lopMap[lop].first += (totalScore / count);
                lopMap[lop].second++;
            }
        }
    }

    // Display results
    for (auto& pair : lopMap) {
        float avgGpa = pair.second.first / pair.second.second;
        cout << "Lop " << pair.first << ": " << avgGpa << " diem trung binh" << endl;
    }
}


// ========================================
// Additional

XepLoai AppService::getXepLoaiTheoDiemTrungBinh(float diemTrungBinh) {
    if (diemTrungBinh >= 8.5) return XepLoai::Gioi;
    if (diemTrungBinh >= 7.0) return XepLoai::Kha;
    if (diemTrungBinh >= 5.5) return XepLoai::TrungBinh;
    if (diemTrungBinh >= 4.0) return XepLoai::Yeu;
    return XepLoai::Kem;
}

// ========================================
