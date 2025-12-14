#include "../includes/QLSinhVienService.h"
#include <sstream>
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
    cout << "✓ Da them va luu sinh vien! " << endl;
}

void QLSinhVienService::docFileSinhVien() {
    ifstream file(this->FILE_NAME);
    if (!file.is_open()) {
        cout << "⚠ Chua co file, hay nhap sinh vien de them moi!\n";
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
    cout << "✓ Doc " << this->danhSachSinhVien.size() << " sinh vien!\n";
}


void QLSinhVienService::kiemTraFile() {
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



vector<SinhVien *> QLSinhVienService::getDanhSachSinhVien() {
    return this->danhSachSinhVien;
}

void QLSinhVienService::hienThiDanhSachSinhVien() {
    for(int i = 0 ; i < danhSachSinhVien.size(); i++) {
        cout << i + 1 << ". " << danhSachSinhVien[i]->getThongTin() << endl;
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

    for (SinhVien*& sinhVien : this->danhSachSinhVien) {
        if (sinhVien->getMaSV() == maSinhVien) {
            return sinhVien;
        }
    }

    return nullptr;
}