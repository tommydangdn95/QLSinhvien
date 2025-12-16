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
    // Mon Hoc
    // ========================================
    void themMoiMonHoc();
    void hienThiDanhSachMonHoc();
    void capNhatThongTinMonHoc();
    void xoaMonHocBangIndex();
    MonHoc* timKiemMonHoc(string maMonHoc);
    void sapXepMonHocTheoTenMonHoc();

    // ========================================
    // Sinh vien
    // ========================================
    void themMoiSinhVien();
    void hienThiDanhSachSinhVien();
    void capNhatThongTinSinhVien();
    void xoaSinhVien();
    SinhVien* timKiemSinhVienBangId(string maSinhVien);
    void sapXepSinhVienTheoTenSinhVien();

    // ========================================
    // Bang Diem Sinh Vien
    // ========================================

    void kiemTraFile();
    void hienThiDanhSachBangDiemSinhVien();
    void themMoiDiemSinhVien();
    void luuBangDiemVaoFile(BangDiem* bangDiem);
    void docFileBangDiem();
    void hienThiBangDiemCuaSinhVienBangId(string maSinhVien);
    void hienThiBangDiemCuaSinhVienBangIndex(int sinhVienIndex);

    void suaDiemSinhVien();
    void suaDiemSinhVienBangMasv(string maSv);
    void xoaDiemSinhVien();
    void xoaDiemSinhVienBangMasv(string maSv);

    void timDanhSachBangDiemSinhVienBangMaSv();
    void timDanhSachBangDiemSinhVienBangMaMonHoc();

    void sapXepDanhSachBangDiemTheoMaSinhVien();
    void sapXepDanhSachBangDiemSinhVienTheoTenSv();
    void sapXepDanhSachBangDiemSinhVienTheoTenMonHoc();
    void sapXepDanhSachBangDiemSinhvienTheoDiemTrungBinh();


    // Toi thieu 4 yeu cau tim phan tu lon nhat, nho nhat
    void timSinhVienDiemTongketThapNhat();
    void timSinhVienDiemTongketCaoNhat();
    void timMonHocSinhVienDangKiNhieuNhat();
    void timMonHocSinhVienDangKiItMonNhat();

    // Toi thieu 5 yeu cau tinh tong, trung binh, dem
    void hienThiDanhSachDiemTrungBinhSinhVien();
    void hienThiDanhSachDiemTrungBinhTheoMonHoc();
    void hienThiDanhSachTongSoTinChiCuaSinhVien();
    void demSoSinhVienDatLoaiGioi();
    void demSoMonHocSinhVienDangKy();

    // Các yêu cầu thống kê theo điều kiện: 1 điểm (Tối thiểu 5 yêu cầu)
    void thongKeSoSinhVienDangHocMonHoc();
    void thongKeSoSinhVienDatLoaiGioiTheoMonHoc();
    void thongKeSoSinhVienDatLoaiGPAXuaSac();
};

#endif //AppService_h
