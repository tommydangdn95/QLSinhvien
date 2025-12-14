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
        cout << "===== NHAP DU LIEU =====" << endl;
        cout << "1. Them mon hoc" << endl;
        cout << "2. Them sinh vien" << endl;
        cout << "3. Them diem sinh vien" << endl;
        cout << "\n===== HIEN THI DU LIEU =====" << endl;
        cout << "4. Hien thi danh sach sinh vien" << endl;
        cout << "5. Hien thi danh sach mon hoc" << endl;
        cout << "6. Hien thi danh sach bang diem" << endl;
        cout << "\n===== TIM KIEM =====" << endl;
        cout << "7. Tim bang diem sinh vien theo ma SV" << endl;
        cout << "8. Tim bang diem theo ma SV va ma mon" << endl;
        cout << "\n===== SAP XEP =====" << endl;
        cout << "9. Sap xep mon hoc theo ten" << endl;
        cout << "10. Sap xep sinh vien theo ten" << endl;
        cout << "11. Sap xep bang diem theo ma sinh vien" << endl;
        cout << "12. Sap xep bang diem theo ten sinh vien" << endl;
        cout << "13. Sap xep bang diem theo ten mon hoc" << endl;
        cout << "14. Sap xep bang diem theo diem trung binh (cao den thap)" << endl;
        cout << "\n===== TIM MIN/MAX =====" << endl;
        cout << "15. Tim sinh vien co diem TB cao nhat" << endl;
        cout << "16. Tim sinh vien co diem TB thap nhat" << endl;
        cout << "17. Tim sinh vien dang ky nhieu mon nhat" << endl;
        cout << "18. Tim sinh vien dang ky it mon nhat" << endl;
        cout << "\n===== TINH TOAN =====" << endl;
        cout << "19. Hien thi danh sach diem TB sinh vien" << endl;
        cout << "20. Hien thi danh sach so tin chi sinh vien" << endl;
        cout << "21. Dem so sinh vien dat loai Gioi" << endl;
        cout << "22. Dem so sinh vien dat loai Kha" << endl;
        cout << "23. Tinh diem cao nhat cua tung sinh vien" << endl;
        cout << "\n===== THONG KE =====" << endl;
        cout << "24. Thong ke so sinh vien theo mon hoc" << endl;
        cout << "25. Thong ke sinh vien Gioi theo mon hoc" << endl;
        cout << "26. Thong ke sinh vien co GPA > 8.0" << endl;
        cout << "27. Thong ke so sinh vien theo loai diem" << endl;
        cout << "28. Thong ke diem trung binh sinh vien theo lop" << endl;
        cout << "\n0. Thoat" << endl;
        cout << "============================================" << endl;
        cout << "Nhap lua chon: ";
        if (!(cin >> luaChon)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nhap khong hop le! Vui long nhap mot so." << endl;
            continue;
        }
        
        switch (luaChon) {
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
                break;
            case 6:
                appSerivce.hienThiDanhSachBangDiemSinhVien();
                break;
            case 7: {
                string maSv;
                cout << "Nhap ma sinh vien: ";
                cin.ignore();
                getline(cin, maSv);
                appSerivce.timDanhSachBangDiemSinhVienBangMasv(maSv);
                break;
            }
            case 8: {
                string maSv, maMon;
                cout << "Nhap ma sinh vien: ";
                cin.ignore();
                getline(cin, maSv);
                cout << "Nhap ma mon hoc: ";
                getline(cin, maMon);
                appSerivce.timDanhSachBangDiemSinhVienBangMaMonHoc(maSv, maMon);
                break;
            }
            case 9:
                appSerivce.sapXepMonHocTheoTenMonHoc();
                break;
            case 10:
                appSerivce.sapXepSinhVienTheoTenSinhVien();
                break;
            case 11:
                appSerivce.sapXepDanhSachBangDiemTheoMaSinhVien();
                break;
            case 12:
                appSerivce.sapXepDanhSachBangDiemSinhVienTheoTenSv();
                break;
            case 13:
                appSerivce.sapXepDanhSachBangDiemSinhVienTheoTenMonHoc();
                break;
            case 14:
                appSerivce.sapXepDanhSachBangDiemSinhvienTheoDiemTrungBinh();
                break;
            case 15: {
                SinhVien* sv = appSerivce.timSinhvienDiemTrungBinhCaoNhat();
                if (sv != nullptr) {
                    cout << "\nSinh vien co diem TB cao nhat: " << sv->getThongTin() << endl;
                }
                break;
            }
            case 16: {
                SinhVien* sv = appSerivce.timSinhVienDiemTrungBinhThapNhat();
                if (sv != nullptr) {
                    cout << "\nSinh vien co diem TB thap nhat: " << sv->getThongTin() << endl;
                }
                break;
            }
            case 17:
                appSerivce.timBangDiemSinhVienDangKiNhieuMonNhat();
                break;
            case 18:
                appSerivce.timBangDiemSinhVienDangKiItMonNhat();
                break;
            case 19:
                appSerivce.hienThiDanhSachDiemTrungBinhSinhVien();
                break;
            case 20:
                appSerivce.hienThiDanhSachSoTinChiSinhVien();
                break;
            case 21:
                appSerivce.demSoSinhVienDatLoaiGioi();
                break;
            case 22:
                appSerivce.demSoSinhVienDatLoaiKha();
                break;
            case 23:
                appSerivce.tinhDiemTrungBinhCaoNhatCuaSinhVien();
                break;
            case 24:
                appSerivce.thongKeSoSinhVienDangHocMonHoc();
                break;
            case 25:
                appSerivce.thongKeSoSinhVienDatLoaiGioiTheoMonHoc();
                break;
            case 26:
                appSerivce.thongKeSoSinhVienDatLoaiGPAXuaSac();
                break;
            case 27:
                appSerivce.hienThiSoSinhVienTheoLoaiDiem();
                break;
            case 28:
                appSerivce.thongKeSoSinhVienDatTheoLop();
                break;
            case 0:
                cout << "Cam on da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }


    } while (luaChon != 0);

    return 0;
}
