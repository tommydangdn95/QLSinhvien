//
// Created by Tommy-Asus on 12/13/2025.
//

#ifndef AppService_h
#define AppService_h

#include "LinkedList.h"
#include "QLMonHocService.h"
#include "QLSinhVienService.h"

enum class XepLoai {
    Gioi,
    Kha,
    TrungBinh,
    Yeu,
    Kem
};

class AppService {
private:
    QLSinhVienService qlSinhvienService;
    QLMonHocService qlMonHocService;
    LinkedList danhSachBangDiem;
    string FILE_NAME = "../bangdiem.txt";
    XepLoai getXepLoaiTheoDiemTrungBinh(float diemTrungBinh);
public:
    AppService();

    // ========================================
    // NHAP, Sua, Xoa DU LIEU
    // ========================================
    void themMoiMonHoc();
    void themMoiSinhVien();
    void themMoiDiemSinhVien();
    void capNhatThongTinMonHoc();
    void capNhatThongTinSinhVien();
    void capNhatThongTinBangDiem();
    void xoaSinhVien();
    void xoaMonHoc();
    void xoaBangDiem();

    // ========================================
    // ===== HIEN THI DU LIEU ===== =====
    void hienThiDanhSachMonHoc();
    void hienThiDanhSachSinhVien();
    void hienThiDanhSachBangDiemSinhVien();

    // ========================================
    // ===== TIM KIEM ===== ===== =====
    void timDanhSachBangDiemSinhVienBangMaSv();
    void timDanhSachBangDiemSinhVienBangMaMonHoc();

    //==========================================
    // ======== TIM KIEM ====================
    void sapXepMonHocTheoTen();
    void sapXepSinhVienTheoTen();
    void sapXepBangDiemTheoMaSv();
    void sapXepBangDiemTheoDiemTrungBinh();

    // ========================================
    // ===== TIM MIN/MAX, Tinh Toan, Tong  ===== =====
    void timSinhVienDiemTongketThapNhat();
    void timSinhVienDiemTongketCaoNhat();
    void timMonHocSinhVienDangKiNhieuNhat();
    void timMonHocSinhVienDangKiItMonNhat();

    // ========================================
    // ===== TINH TOAN =====
    void hienThiDanhSachDiemTrungBinhSinhVien();
    void hienThiDanhSachDiemTrungBinhTheoMonHoc();
    void hienThiDanhSachTongSoTinChiCuaSinhVien();
    void demSoSinhVienDatLoaiGioi();
    void demSoMonHocSinhVienDangKy();

    // ========================================
    // ===== ===== TINH TOAN =====  ===== =====

    MonHoc* timKiemMonHoc(string maMonHoc);
    void sapXepMonHocTheoTenMonHoc();

    // ========================================
    // Sinh vien
    // ========================================

    SinhVien* timKiemSinhVienBangId(string maSinhVien);
    void sapXepSinhVienTheoTenSinhVien();

    // ========================================
    // Bang Diem Sinh Vien
    // ========================================

    void hienThiBangDiemCuaSinhVienBangId(string maSinhVien);
    void hienThiBangDiemCuaSinhVienBangIndex(int sinhVienIndex);

    void suaDiemSinhVien();
    void suaDiemSinhVienBangMasv(string maSv);
    void xoaDiemSinhVien();
    void xoaDiemSinhVienBangMasv(string maSv);


    // Các yêu cầu thống kê theo điều kiện: 1 điểm (Tối thiểu 5 yêu cầu)
    void thongKeSoSinhVienDangHocMonHoc();
    void thongKeSoSinhVienDatLoaiGioiTheoMonHoc();
    void thongKeSoSinhVienDatLoaiGPAXuaSac();

    // Additional
    void kiemTraFile();
    void luuBangDiemVaoFile(BangDiem* bangDiem);
    void docFileBangDiem();
    void ghiDeFile();
};

#endif //AppService_h
