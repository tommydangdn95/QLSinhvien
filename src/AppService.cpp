//
// Created by Tommy-Asus on 12/13/2025.
//

#include "../includes/AppService.h"
#include <sstream>
#include <map>
#include <set>
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



// ========================================
// TIM KIEM (2+ requirements)
// ========================================
void AppService::timDanhSachBangDiemSinhVienBangMasv(string maSv) {
    this->danhSachBangDiem.hienThiBangDiemTheoMaSinhVien(maSv);
}

void AppService::timDanhSachBangDiemSinhVienBangMaMonHoc(string maSv, string maMonHoc) {
    this->danhSachBangDiem.hienThiBangDiemTheoMaSinhVienVaMonHoc(maSv, maMonHoc);
}

// ========================================
// SAP XEP (4+ requirements)
// ========================================
void AppService::sapXepMonHocTheoTenMonHoc() {
    cout << "\nDanh sach mon hoc (sap xep theo ten):" << endl;
    vector<MonHoc*> danhSach = this->qlMonHocService.getDanhSachMonHoc();
    
    // Bubble sort
    for (int i = 0; i < danhSach.size(); i++) {
        for (int j = i + 1; j < danhSach.size(); j++) {
            if (danhSach[i]->getTenMon() > danhSach[j]->getTenMon()) {
                MonHoc* temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < danhSach.size(); i++) {
        cout << i + 1 << ". " << danhSach[i]->getThongTin() << endl;
    }
}

void AppService::sapXepSinhVienTheoTenSinhVien() {
    cout << "\nDanh sach sinh vien (sap xep theo ten):" << endl;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();
    
    // Bubble sort
    for (int i = 0; i < danhSach.size(); i++) {
        for (int j = i + 1; j < danhSach.size(); j++) {
            if (danhSach[i]->getHoTen() > danhSach[j]->getHoTen()) {
                SinhVien* temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < danhSach.size(); i++) {
        cout << i + 1 << ". " << danhSach[i]->getThongTin() << endl;
    }
}

void AppService::sapXepDanhSachBangDiemTheoMaSinhVien() {
    this->danhSachBangDiem.sapXepDanhSachBangDiemTheoMaSinhVien();
}

void AppService::sapXepDanhSachBangDiemSinhVienTheoTenSv() {
    cout << "\n========== Bang diem (sap xep theo ten sinh vien) ==========" << endl;
    
    // Convert linked list to vector for easier sorting
    vector<pair<string, Node*>> grades; // (student name, node)
    Node* temp = this->danhSachBangDiem.getHead();
    
    while (temp != nullptr) {
        grades.push_back({temp->data->getSinhVien()->getHoTen(), temp});
        temp = temp->next;
    }
    
    // Bubble sort by student name
    for (int i = 0; i < grades.size(); i++) {
        for (int j = i + 1; j < grades.size(); j++) {
            if (grades[i].first > grades[j].first) {
                swap(grades[i], grades[j]);
            }
        }
    }
    
    // Display sorted
    for (int i = 0; i < grades.size(); i++) {
        cout << i + 1 << ". " << grades[i].second->data->getThongTin() << endl;
    }
}

void AppService::sapXepDanhSachBangDiemSinhVienTheoTenMonHoc() {
    cout << "\n========== Bang diem (sap xep theo ten mon hoc) ==========" << endl;
    
    // Convert linked list to vector for easier sorting
    vector<pair<string, Node*>> grades; // (course name, node)
    Node* temp = this->danhSachBangDiem.getHead();
    
    while (temp != nullptr) {
        grades.push_back({temp->data->getMonHoc()->getTenMon(), temp});
        temp = temp->next;
    }
    
    // Bubble sort by course name
    for (int i = 0; i < grades.size(); i++) {
        for (int j = i + 1; j < grades.size(); j++) {
            if (grades[i].first > grades[j].first) {
                swap(grades[i], grades[j]);
            }
        }
    }
    
    // Display sorted
    for (int i = 0; i < grades.size(); i++) {
        cout << i + 1 << ". " << grades[i].second->data->getThongTin() << endl;
    }
}

void AppService::sapXepDanhSachBangDiemSinhvienTheoDiemTrungBinh() {
    cout << "\n========== Bang diem (sap xep theo diem trung binh) ==========" << endl;
    
    // Convert linked list to vector for easier sorting
    vector<pair<float, Node*>> grades; // (GPA, node)
    Node* temp = this->danhSachBangDiem.getHead();
    
    while (temp != nullptr) {
        float gpa = temp->data->getDiem()->getDiemTongKet();
        grades.push_back({gpa, temp});
        temp = temp->next;
    }
    
    // Bubble sort by GPA (descending)
    for (int i = 0; i < grades.size(); i++) {
        for (int j = i + 1; j < grades.size(); j++) {
            if (grades[i].first < grades[j].first) {
                swap(grades[i], grades[j]);
            }
        }
    }
    
    // Display sorted
    for (int i = 0; i < grades.size(); i++) {
        cout << i + 1 << ". " << grades[i].second->data->getThongTin() << " (Diem: " << grades[i].first << ")" << endl;
    }
}

// ========================================
// TIM MIN/MAX (4+ requirements)
// ========================================
SinhVien* AppService::timSinhVienDiemTrungBinhThapNhat() {
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();
    if (danhSach.empty()) {
        cout << "\nKhong co sinh vien nao!" << endl;
        return nullptr;
    }
    
    SinhVien* minSv = nullptr;
    float minGpa = 10.0f;
    
    // Iterate through each student
    for (SinhVien* sv : danhSach) {
        float totalScore = 0;
        int count = 0;
        
        // Calculate average GPA for this student
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
            if (gpa < minGpa) {
                minGpa = gpa;
                minSv = sv;
            }
        }
    }
    
    if (minSv != nullptr) {
        cout << "\n========== Sinh vien co diem TB thap nhat ==========" << endl;
        cout << minSv->getThongTin() << endl;
        cout << "Diem TB: " << minGpa << endl;
    } else {
        cout << "\nKhong tim thay sinh vien!" << endl;
    }
    
    return minSv;
}

SinhVien* AppService::timSinhvienDiemTrungBinhCaoNhat() {
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();
    if (danhSach.empty()) {
        cout << "\nKhong co sinh vien nao!" << endl;
        return nullptr;
    }
    
    SinhVien* maxSv = nullptr;
    float maxGpa = 0.0f;
    
    // Iterate through each student
    for (SinhVien* sv : danhSach) {
        float totalScore = 0;
        int count = 0;
        
        // Calculate average GPA for this student
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
            if (gpa > maxGpa) {
                maxGpa = gpa;
                maxSv = sv;
            }
        }
    }
    
    if (maxSv != nullptr) {
        cout << "\n========== Sinh vien co diem TB cao nhat ==========" << endl;
        cout << maxSv->getThongTin() << endl;
        cout << "Diem TB: " << maxGpa << endl;
    } else {
        cout << "\nKhong tim thay sinh vien!" << endl;
    }
    
    return maxSv;
}

LinkedList AppService::timBangDiemSinhVienDangKiNhieuMonNhat() {
    LinkedList result;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();
    
    if (danhSach.empty()) {
        cout << "\nKhong co sinh vien nao!" << endl;
        return result;
    }
    
    string maxSvId;
    int maxCount = 0;
    
    // Count courses for each student
    for (SinhVien* sv : danhSach) {
        int count = 0;
        Node* temp = this->danhSachBangDiem.getHead();
        
        while (temp != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() == sv->getMaSV()) {
                count++;
            }
            temp = temp->next;
        }
        
        if (count > maxCount) {
            maxCount = count;
            maxSvId = sv->getMaSV();
        }
    }
    
    if (maxCount > 0) {
        cout << "\n========== Sinh vien dang ky nhieu mon hoc nhat ==========" << endl;
        this->danhSachBangDiem.hienThiBangDiemTheoMaSinhVien(maxSvId);
    } else {
        cout << "\nKhong tim thay!" << endl;
    }
    
    return result;
}

LinkedList AppService::timBangDiemSinhVienDangKiItMonNhat() {
    LinkedList result;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();
    
    if (danhSach.empty()) {
        cout << "\nKhong co sinh vien nao!" << endl;
        return result;
    }
    
    string minSvId;
    int minCount = INT_MAX;
    
    // Count courses for each student
    for (SinhVien* sv : danhSach) {
        int count = 0;
        Node* temp = this->danhSachBangDiem.getHead();
        
        while (temp != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() == sv->getMaSV()) {
                count++;
            }
            temp = temp->next;
        }
        
        if (count > 0 && count < minCount) {
            minCount = count;
            minSvId = sv->getMaSV();
        }
    }
    
    if (minCount < INT_MAX) {
        cout << "\n========== Sinh vien dang ky it mon hoc nhat ==========" << endl;
        this->danhSachBangDiem.hienThiBangDiemTheoMaSinhVien(minSvId);
    } else {
        cout << "\nKhong tim thay!" << endl;
    }
    
    return result;
}

// ========================================
// TINH TONG, TRUNG BINH, DEM (5+ requirements)
// ========================================
void AppService::hienThiDanhSachDiemTrungBinhSinhVien() {
    cout << "\n========== Danh sach diem trung binh cua tung sinh vien ==========" << endl;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();
    
    for (int i = 0; i < danhSach.size(); i++) {
        float totalScore = 0;
        int count = 0;
        
        Node* temp = this->danhSachBangDiem.getHead();
        while (temp != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() == danhSach[i]->getMaSV()) {
                totalScore += temp->data->getDiem()->getDiemTongKet();
                count++;
            }
            temp = temp->next;
        }
        
        if (count > 0) {
            float gpa = totalScore / count;
            cout << i + 1 << ". " << danhSach[i]->getHoTen() << " - Diem TB: " << gpa << endl;
        }
    }
}

void AppService::hienThiDanhSachSoTinChiSinhVien() {
    cout << "\n========== Danh sach so tin chi cua tung sinh vien ==========" << endl;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();
    vector<MonHoc*> danhSachMonHoc = this->qlMonHocService.getDanhSachMonHoc();

    for (int i = 0; i < danhSach.size(); i++) {
        int totalCredits = 0;

        Node* temp = this->danhSachBangDiem.getHead();
        while (temp != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() == danhSach[i]->getMaSV()) {
                MonHoc* monHoc = temp->data->getMonHoc();
                if (monHoc != nullptr) {
                    totalCredits += monHoc->getSoTinChi();
                }
            }
            temp = temp->next;
        }

        cout << i + 1 << ". " << danhSach[i]->getHoTen() << " - Tong tin chi: " << totalCredits << endl;
    }
}

int AppService::demSoSinhVienDatLoaiGioi() {
    int count = 0;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();

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
            if (gpa >= 8.5) {
                count++;
                cout << sv->getHoTen() << " - Diem TB: " << gpa << endl;
            }
        }
    }

    cout << "\nTong so sinh vien dat loai Gioi: " << count << endl;
    return count;
}

int AppService::demSoSinhVienDatLoaiKha() {
    int count = 0;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();

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
            if (gpa >= 7.0 && gpa < 8.5) {
                count++;
                cout << sv->getHoTen() << " - Diem TB: " << gpa << endl;
            }
        }
    }

    cout << "\nTong so sinh vien dat loai Kha: " << count << endl;
    return count;
}

float AppService::hienThiDiemTrungBinhCuaTatCaSinhVienTheoMonHoc() {
    cout << "\nDiem trung binh cua tat ca sinh vien theo mon hoc:" << endl;
    return 0.0f;
}


float AppService::tinhDiemTrungBinhCaoNhatCuaSinhVien() {
    cout << "\n========== Diem cao nhat cua tung sinh vien ==========" << endl;
    vector<SinhVien*> danhSach = this->qlSinhvienService.getDanhSachSinhVien();

    for (int i = 0; i < danhSach.size(); i++) {
        float maxScore = 0;
        string maxMonHoc = "";

        Node* temp = this->danhSachBangDiem.getHead();
        while (temp != nullptr) {
            if (temp->data->getSinhVien()->getMaSV() == danhSach[i]->getMaSV()) {
                float score = temp->data->getDiem()->getDiemTongKet();
                if (score > maxScore) {
                    maxScore = score;
                    maxMonHoc = temp->data->getMonHoc()->getTenMon();
                }
            }
            temp = temp->next;
        }

        if (maxScore > 0) {
            cout << i + 1 << ". " << danhSach[i]->getHoTen() << " - Diem cao nhat: " << maxScore
                 << " (" << maxMonHoc << ")" << endl;
        } else {
            cout << i + 1 << ". " << danhSach[i]->getHoTen() << " - Chua co diem" << endl;
        }
    }

    return 0.0f;
}

void AppService::hienThiSoSinhVienTheoLoaiDiem() {
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

// ========================================
// THONG KE THEO DIEU KIEN
// ========================================
// THONG KE THEO DIEU KIEN (5+ requirements)
// ========================================
void AppService::thongKeSoSinhVienDangHocMonHoc() {
    cout << "\n========== Thong ke so sinh vien dang hoc theo mon hoc ==========" << endl;
    vector<MonHoc*> danhSach = this->qlMonHocService.getDanhSachMonHoc();

    for (int i = 0; i < danhSach.size(); i++) {
        int count = 0;
        set<string> studentIds; // To avoid counting duplicate enrollments

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

void AppService::thongKeSoSinhVienDatLoaiGPAXuaSac() {
    cout << "\n========== Thong ke sinh vien co diem TB tren 8.0 ==========" << endl;
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
            if (gpa > 8.0) {
                count++;
                excellentStudents.push_back({sv->getHoTen(), gpa});
            }
        }
    }

    cout << "So sinh vien co diem TB > 8.0: " << count << endl;
    if (count > 0) {
        cout << "\nDanh sach:" << endl;
        for (int i = 0; i < excellentStudents.size(); i++) {
            cout << i + 1 << ". " << excellentStudents[i].first << " - Diem TB: " << excellentStudents[i].second << endl;
        }
    }
}

void AppService::thongKeSoSinhVienDatTheoLop() {
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
