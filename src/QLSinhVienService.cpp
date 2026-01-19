#include "../includes/QLSinhVienService.h"
#include <string>
#include <sstream>
using namespace std;

QLSinhVienService::QLSinhVienService() {
    this->kiemTraFile();
    this->docFileSinhVien();
}

void QLSinhVienService::themMoiSinhVien(SinhVien* sv) {
    sv->nhap();
    this->danhSachSinhVien.push_back(sv);
}

void QLSinhVienService::luuSinhVienVaoFile(SinhVien* sv) {
    ofstream file(this->FILE_NAME, ios::app);

    if (!file.is_open()) {
        cout << "File could not be opened" << endl;
        return;
    }

    file << sv->getMaSV() << "|"
        << sv->getHoTen() << "|"
        << sv->getNgaySinh() << "|"
        << sv->getLop() << "|"
        << sv->getKhoa() << endl;

    file.close();
    cout << "Da them va luu sinh vien! " << endl;
}

void QLSinhVienService::docFileSinhVien() {
    ifstream file(this->FILE_NAME);
    if (!file.is_open()) {
        cout << "Chua co file, hay nhap sinh vien de them moi!\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string maSv, hoTen, ngaySinh, lop, khoa;

        getline(ss, maSv, '|');
        getline(ss, hoTen, '|');
        getline(ss, ngaySinh, '|');
        getline(ss, lop, '|');
        getline(ss, khoa, '|');

        SinhVien* sv = new SinhVien(maSv, hoTen, ngaySinh, lop, khoa);
        this->danhSachSinhVien.push_back(sv);
    }

    file.close();
    cout << "Doc " << this->danhSachSinhVien.size() << " sinh vien!\n";
}


void QLSinhVienService::kiemTraFile() {
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

void QLSinhVienService::ghiDeFile() {
    ofstream file(this->FILE_NAME);

    if (!file.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    for(SinhVien * sinhVien : this->getDanhSachSinhVien()){
        file << sinhVien->getThongTinInLine() << endl;
    }

    file.close();
}


vector<SinhVien *> QLSinhVienService::getDanhSachSinhVien() {
    return this->danhSachSinhVien.toVector();
}

void QLSinhVienService::hienThiDanhSachSinhVien() {
    int index = 0;
    for(SinhVien* sinhVien: this->getDanhSachSinhVien()) {
        cout << index + 1 << ". " << sinhVien->getThongTin() << endl;
        index++;
    }
}

void QLSinhVienService::hienThiDanhSachSinhVien(vector<SinhVien*> listResult) {
    for(int i = 0 ; i < listResult.size(); i++) {
        cout << i + 1 << ". " << listResult[i]->getThongTin() << endl;
    }
}

SinhVien* QLSinhVienService::timSinhVienBangIndex(int index) {
    SinhVien* sv = new SinhVien();
    if (this->danhSachSinhVien.empty()) {
        return nullptr;
    }

    if (index >= this->danhSachSinhVien.size()) {
        return nullptr;
    }

    return this->danhSachSinhVien[index];
}


SinhVien* QLSinhVienService::timSinhVienBangId(string maSinhVien) {
    if (maSinhVien.empty()) {
        return nullptr;
    }

    return this->danhSachSinhVien.findById(maSinhVien);
}

void QLSinhVienService::removeSinhVien(SinhVien* sinhVien) {
    SinhVienStack stackSinhVien = this->danhSachSinhVien.removeAt(sinhVien);
    this->danhSachSinhVien = stackSinhVien;
}

void QLSinhVienService::sortSinhVienTheoTen() {
    this->danhSachSinhVien.sortMonHocByName();
}
