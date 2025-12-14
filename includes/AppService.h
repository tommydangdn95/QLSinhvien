//
// Created by Tommy-Asus on 12/13/2025.
//

#ifndef AppService_h
#define AppService_h

#include "LinkedList.h"
#include "QLMonHocService.h"
#include "QLSinhVienService.h"


class AppService {
private:
    QLSinhVienService qlSinhvienService;
    QLMonHocService qlMonHocService;
    LinkedList danhSachBangDiem;
    string FILE_NAME = "../bangdiem.txt";
public:
    AppService();

    // ========================================
    // Mon Hoc
    // ========================================
    void themMoiMonHoc();
    void hienThiDanhSachMonHoc();
    void xoaMonHocBangIndex();
    MonHoc* timKiemMonHoc(string maMonHoc);
    void sapXepMonHocTheoTenMonHoc();

    // ========================================
    // Sinh vien
    // ========================================
    void themMoiSinhVien();
    void hienThiDanhSachSinhVien();
    void xoaSinhVien();
    SinhVien* timKiemSinhVienBangId(string maSinhVien);
    void sapXepSinhVienTheoTenSinhVien();

    // ========================================
    // Bang Diem Sinh Vien
    // ========================================

    void kiemTraFile();
    void hienThiDanhSachBangDiemSinhVien();
    void luuBangDiemVaoFile(BangDiem* bangDiem);
    void docFileBangDiem();
    void hienThiBangDiemCuaSinhVienBangId(string maSinhVien);
    void hienThiBangDiemCuaSinhVienBangIndex(int sinhVienIndex);

    void themMoiDiemSinhVien();
    void themMoiDiemSinhVienBangMasv(string maSv);
    void suaDiemSinhVien();
    void suaDiemSinhVienBangMasv(string maSv);
    void xoaDiemSinhVien();
    void xoaDiemSinhVienBangMasv(string maSv);

    void timDanhSachBangDiemSinhVienBangMasv(string maSv);
    void timDanhSachBangDiemSinhVienBangMaMonHoc(string maSv, string maMonHoc);

    void sapXepDanhSachBangDiemTheoMaSinhVien();
    void sapXepDanhSachBangDiemSinhVienTheoTenSv();
    void sapXepDanhSachBangDiemSinhVienTheoTenMonHoc();
    void sapXepDanhSachBangDiemSinhvienTheoDiemTrungBinh();


    // Toi thieu 4 yeu cau tim phan tu lon nhat, nho nhat
    SinhVien* timSinhVienDiemTrungBinhThapNhat();
    SinhVien* timSinhvienDiemTrungBinhCaoNhat();
    LinkedList timBangDiemSinhVienDangKiNhieuMonNhat();
    LinkedList timBangDiemSinhVienDangKiItMonNhat();

    // Toi thieu 5 yeu cau tinh tong, trung binh, dem
    void hienThiDanhSachDiemTrungBinhSinhVien();
    void hienThiDanhSachSoTinChiSinhVien();
    int demSoSinhVienDatLoaiGioi();
    int demSoSinhVienDatLoaiKha();
    float hienThiDiemTrungBinhCuaTatCaSinhVienTheoMonHoc();
    float tinhDiemTrungBinhCaoNhatCuaSinhVien();

    // Các yêu cầu thống kê theo điều kiện: 1 điểm (Tối thiểu 5 yêu cầu)
    void thongKeSoSinhVienDangHocMonHoc();
    void thongKeSoSinhVienDatLoaiGioiTheoMonHoc();
    void thongKeSoSinhVienDatLoaiGPAXuaSac();
    void hienThiSoSinhVienTheoLoaiDiem();
    void thongKeSoSinhVienDatTheoLop();
};

#endif //AppService_h
