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
        cout << "1. Them mon hoc" << endl;
        cout << "2. Them sinh vien" << endl;
        cout << "3. Them diem sinh vien" << endl;
        cout << "4. Hien Thi danh sach sinh vien" << endl;
        cout << "5. Hien Thi danh sach mon hoc" << endl;
        cout << "6. Hien thi danh sach bang diem tat ca sinh vien" << endl;
        cout << "7. Tim kiem bang diem sinh vien theo viec chon sinh vien " << endl;
        cout << "8. Tim kiem bang diem sinh vien theo viec chon mon hoc " << endl;
        cout << "9. Hien thi sinh vien va mon hoc co diem trung binh thap nhat " << endl;
        cout << "10. Hien thi sinh vien va mon hoc co diem trung binh cao nhat " << endl;
        cout << "11. Hien thi mon hoc co so sinh vien dang ki it nhat " << endl;
        cout << "12. Hien thi mon hoc co so sinh vien dang ki cao nhat " << endl;
        cout << "13. Hien thi danh sach diem trung binh cac mon sinh vien " << endl;
        cout << "14. Hien thi danh sach diem trung binh theo cac mon " << endl;
        cout << "15. Hien thi danh sach tong so tin chi cac mon sinh vien " << endl;
        cout << "16. Dem so mon sinh vien dat loai gioi " << endl;
        cout << "17. Dem so mon hoc sinh vien da dang ky" << endl;
        cout << "0. Thoat" << endl;
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
                appSerivce.hienThiDanhSachSinhVien();
                break;
            case 5:
                appSerivce.hienThiDanhSachMonHoc();
                break;
            case 6:
                appSerivce.hienThiDanhSachBangDiemSinhVien();
                break;
            case 7:
                appSerivce.timDanhSachBangDiemSinhVienBangMaSv();
                break;
            case 8:
                appSerivce.timDanhSachBangDiemSinhVienBangMaMonHoc();
                break;
            case 9:
                appSerivce.timSinhVienDiemTongketThapNhat();
                break;
            case 10:
                appSerivce.timSinhVienDiemTongketCaoNhat();
                break;
            case 11:
                appSerivce.timMonHocSinhVienDangKiItMonNhat();
                break;
            case 12:
                appSerivce.timMonHocSinhVienDangKiNhieuNhat();
                break;
            case 13:
                appSerivce.hienThiDanhSachDiemTrungBinhSinhVien();
                break;
            case 14:
                appSerivce.hienThiDanhSachDiemTrungBinhTheoMonHoc();
                break;
            case 15:
                appSerivce.hienThiDanhSachTongSoTinChiCuaSinhVien();
                break;
            case 16:
                appSerivce.demSoSinhVienDatLoaiGioi();
                break;
            case 17:
                appSerivce.demSoMonHocSinhVienDangKy();
                break;
            default:
                break;
        }


    } while (luaChon != 0);

    return 0;
}
