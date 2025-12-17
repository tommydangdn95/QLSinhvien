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
        cout << "===== NHAP, Sua, Xoa DU LIEU =====" << endl;
        cout << "1. Them mon hoc" << endl;
        cout << "2. Them sinh vien" << endl;
        cout << "3. Them diem sinh vien" << endl;
        cout << "4. Sua thong tin mon hoc" << endl;
        cout << "5. Sua thong tin sinh vien" << endl;
        cout << "6. Sua diem sinh vien" << endl;
        cout << "7. Xoa sinh vien" << endl;
        cout << "8. Xoa mon hoc" << endl;
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
        cout << "30. Thong ke so sinh vien theo mon hoc" << endl;
        cout << "31. Thong ke sinh vien Gioi theo mon hoc" << endl;
        cout << "32. Thong ke sinh vien co GPA > 8.0" << endl;
        cout << "33. Thong ke so sinh vien theo loai diem" << endl;
        cout << "34. Thong ke diem trung binh sinh vien theo lop" << endl;
        
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
            case 10:
                appSerivce.hienThiDanhSachSinhVien();
                break;
            case 11:
                appSerivce.hienThiDanhSachMonHoc();
                break;
            case 12:
                appSerivce.hienThiDanhSachBangDiemSinhVien();
                break;
            case 13:
                appSerivce.timDanhSachBangDiemSinhVienBangMaSv();
                break;
            case 14:
                appSerivce.timDanhSachBangDiemSinhVienBangMaMonHoc();
                break;


            case 19:
                appSerivce.timSinhVienDiemTongketCaoNhat();
                break;
            case 20:
                appSerivce.timSinhVienDiemTongketThapNhat();
                break;
            case 21:
                appSerivce.timMonHocSinhVienDangKiNhieuNhat();
                break;
            case 22:
                appSerivce.timMonHocSinhVienDangKiItMonNhat();
                break;

            case 23:
                appSerivce.hienThiDanhSachDiemTrungBinhSinhVien();
                break;
            case 24:
                appSerivce.hienThiDanhSachDiemTrungBinhTheoMonHoc();
                break;
            case 25:
                appSerivce.hienThiDanhSachTongSoTinChiCuaSinhVien();
                break;
            case 26:
                appSerivce.demSoSinhVienDatLoaiGioi();
                break;
            case 27:
                appSerivce.demSoMonHocSinhVienDangKy();
                break;
            default:
                break;
        }


    } while (luaChon != 0);

    return 0;
}
