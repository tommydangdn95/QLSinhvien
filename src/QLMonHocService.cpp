//
// Created by Tommy-Asus on 12/13/2025.
//

#include "../includes/QLMonHocService.h"
#include <string>
#include <sstream>
using namespace std;


QLMonHocService::QLMonHocService() {
    this->kiemTraFile();
    this->docFileMonHOc();
}

void QLMonHocService::themMoiMonHoc(MonHoc* monHoc) {
    monHoc->nhap();
    this->danhSachMonHoc.push_back(monHoc);
}

void QLMonHocService::luuMonHocVaoFile(MonHoc *monHoc) {
    ofstream file(this->FILE_NAME, ios::app);

    if (!file.is_open()) {
        cout << "File could not be opened" << endl;
        return;
    }

    file << monHoc->getMaMon() << "|"
        << monHoc->getTenMon() << "|"
        << monHoc->getSoTinChi() << "|" << endl;

    file.close();
    cout << "✓ Da them va luu mon hoc! " << endl;
}

void QLMonHocService::docFileMonHOc() {
    ifstream file(this->FILE_NAME);
    if (!file.is_open()) {
        cout << "⚠ Chua co file, hay nhap mon hoc de them moi!\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string maMonHoc, tenMonHoc;
        int soTinChi;

        getline(ss, maMonHoc, '|');
        getline(ss, tenMonHoc, '|');
        ss >> soTinChi;

        MonHoc* monHoc = new MonHoc(maMonHoc, tenMonHoc, soTinChi);
        this->danhSachMonHoc.push_back(monHoc);
    }

    file.close();
    cout << "✓ Doc " << this->danhSachMonHoc.size() << " mon hoc!\n";
}


void QLMonHocService::kiemTraFile() {
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

void QLMonHocService::ghiDeFile() {
    ofstream file(this->FILE_NAME);

    if (!file.is_open()) {
        cout << "⚠ Khong mo duoc file!\n";
        return;
    }

    for(MonHoc* monHoc : this->getDanhSachMonHoc()){
        file << monHoc->getThongTinInLine() << endl;
    }

    file.close();
}


vector<MonHoc*> QLMonHocService::getDanhSachMonHoc() {
    return this->danhSachMonHoc.toVector();
}

void QLMonHocService::hienThiDanhSachMonHoc() {
    for (int i = 0; i < danhSachMonHoc.size(); i++) {
        cout << i + 1 << ". " << danhSachMonHoc[i]->getThongTin() << endl;
    }
}

MonHoc* QLMonHocService::timMonHocBangId(string maMonHoc) {
    if (maMonHoc.empty()) {
        return nullptr;
    }

    return this->danhSachMonHoc.findById(maMonHoc);
}

MonHoc* QLMonHocService::timMonHocBangIndex(int index) {
    if (this->danhSachMonHoc.empty()) {
        return nullptr;
    }

    if (index >= this->danhSachMonHoc.size()) {
        return nullptr;
    }

    return this->danhSachMonHoc[index];
}

void QLMonHocService::xoaMonHoc(MonHoc *monHoc) {
    this->danhSachMonHoc.xoaMonHoc(monHoc);
}

void QLMonHocService::sortMonHocTheoTen() {
    this->danhSachMonHoc.sortMonhocTheoTen();
}


