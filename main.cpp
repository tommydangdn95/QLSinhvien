#include <iostream>
#include "includes/MonHoc.h"
#include "includes/Diem.h"
#include "includes/LinkedList.h"
#include "includes/Node.h"
#include "includes/SinhVien.h"
#include <vector>

#include "includes/AppService.h"
#include "includes/QLSinhVienService.h"


void enterLine() {
    string line;
    cout << "Nhan phim bat ky de tiep tuc : ";
    cin.ignore();
    getline(cin, line);
}

int main() {
    AppService appSerivce;

    int luaChon;
    do {
        cout << "\n========== QUAN LY DIEM SINH VIEN ==========" << endl;
        cout << "===== NHAP, Sua, Xoa DU LIEU =====" << endl;
        cout << "1. Them mon hoc" << endl;
        cout << "2. Them sinh vien" << endl;
        cout << "3. Them diem sinh vien" << endl;
        cout << "4. Sua thong tin mon hoc" << endl;
        cout << "5. Sua thong tin sinh vien" << endl;
        cout << "6. Sua diem sinh vien" << endl;
        cout << "7. Xoa mon hoc" << endl;
        cout << "8. Xoa sinh vien" << endl;
        cout << "9. Xoa diem sinh vien" << endl;

        cout << "\n===== HIEN THI DU LIEU =====" << endl;
        cout << "10. Hien thi danh sach sinh vien" << endl;
        cout << "11. Hien thi danh sach mon hoc" << endl;
        cout << "12. Hien thi danh sach bang diem" << endl;

        cout << "\n===== TIM KIEM =====" << endl;
        cout << "13. Tim kiem bang diem sinh vien theo viec chon sinh vien" << endl;
        cout << "14. Tim kiem bang diem sinh vien theo viec chon mon hoc" << endl;

        cout << "\n===== SAP XEP =====" << endl;
        cout << "15. Sap xep mon hoc theo ten" << endl;
        cout << "16. Sap xep sinh vien theo ten" << endl;
        cout << "17. Sap xep bang diem theo ma sinh vien" << endl;
        cout << "18. Sap xep bang diem theo diem trung binh (cao den thap)" << endl;

        cout << "\n===== TIM MIN/MAX =====" << endl;
        cout << "19. Tim sinh vien co diem TB cao nhat" << endl;
        cout << "20. Tim sinh vien co diem TB thap nhat" << endl;
        cout << "21. Tim mon hoc sinh vien dang ky nhieu nhat" << endl;
        cout << "22. Tim mon hoc sinh vien dang ky it nhat" << endl;

        cout << "\n===== TINH TOAN =====" << endl;
        cout << "23. Hien thi danh sach diem TB sinh vien" << endl;
        cout << "24. Hien thi danh sach diem trung binh theo cac mon" << endl;
        cout << "25. Hien thi danh sach tong so tin chi sinh vien dang ky" << endl;
        cout << "26. Dem so sinh vien dat loai gioi" << endl;
        cout << "27. Dem so mon hoc sinh vien da dang ky" << endl;

        cout << "\n===== THONG KE =====" << endl;
        cout << "28. Thong ke so sinh vien dang theo mon hoc" << endl;
        cout << "29. Thong ke sinh vien Gioi theo mon hoc" << endl;
        cout << "30. Thong ke sinh vien co GPA > 9.0" << endl;
        cout << "31. Thong ke so sinh vien theo loai diem" << endl;
        cout << "32. Thong ke diem trung binh sinh vien theo lop" << endl;
        
        cout << "\n0. Thoat" << endl;
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
                appSerivce.capNhatThongTinMonHoc();
                break;
            case 5:
                appSerivce.capNhatThongTinSinhVien();
                break;
            case 6:
                appSerivce.capNhatThongTinBangDiem();
                break;
            case 7:
                appSerivce.xoaMonHoc();
                enterLine();
                break;
            case 8:
                appSerivce.xoaSinhVien();
                enterLine();
            break;
            case 9:
                appSerivce.xoaBangDiem();
                enterLine();
            break;
            case 10:
                appSerivce.hienThiDanhSachSinhVien();
                enterLine();
                break;
            case 11:
                appSerivce.hienThiDanhSachMonHoc();
                enterLine();
                break;
            case 12:
                appSerivce.hienThiDanhSachBangDiemSinhVien();
                enterLine();
                break;
            case 13:
                appSerivce.timDanhSachBangDiemSinhVienBangMaSv();
                enterLine();
                break;
            case 14:
                appSerivce.timDanhSachBangDiemSinhVienBangMaMonHoc();
                enterLine();
                break;
            case 15:
                appSerivce.sapXepMonHocTheoTen();
                enterLine();
                break;
            case 16:
                appSerivce.sapXepSinhVienTheoTen();
                enterLine();
                break;
            case 17:
                appSerivce.sapXepBangDiemTheoMaSv();
                enterLine();
                break;
            case 18:
                appSerivce.sapXepBangDiemTheoDiemTrungBinh();
                enterLine();
                break;
            case 19:
                appSerivce.timSinhVienDiemTongketCaoNhat();
                enterLine();
                break;
            case 20:
                appSerivce.timSinhVienDiemTongketThapNhat();
                enterLine();
                break;
            case 21:
                appSerivce.timMonHocSinhVienDangKiNhieuNhat();
                enterLine();
                break;
            case 22:
                appSerivce.timMonHocSinhVienDangKiItMonNhat();
                enterLine();
                break;
            case 23:
                appSerivce.hienThiDanhSachDiemTrungBinhSinhVien();
                enterLine();
                break;
            case 24:
                appSerivce.hienThiDanhSachDiemTrungBinhTheoMonHoc();
                enterLine();
                break;
            case 25:
                appSerivce.hienThiDanhSachTongSoTinChiCuaSinhVien();
                enterLine();
                break;
            case 26:
                appSerivce.demSoSinhVienDatLoaiGioi();
                enterLine();
                break;
            case 27:
                appSerivce.demSoMonHocSinhVienDangKy();
                enterLine();
                break;
            case 28:
                appSerivce.thongKeSoSinhVienDangHocMonHoc();
                enterLine();
                break;
            case 29:
                appSerivce.thongKeSoSinhVienDatLoaiGioiTheoMonHoc();
                enterLine();
                break;
            case 30:
                appSerivce.thongKeSoSinhVienDatLoaiGPAXuaSac();
                enterLine();
                break;
            case 31:
                appSerivce.thongKeSoSinhVienTheoLoaiDiem();
                enterLine();
                break;
            case 32:
                appSerivce.thongKeDiemTrungBinhSinhVienTheoLop();
                enterLine();
                break;
            default:
                break;
        }

    } while (luaChon != 0);

    return 0;
}