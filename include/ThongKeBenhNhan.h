#ifndef THONGKEBENHNHAN_H
#define THONGKEBENHNHAN_H

#include "DanhSachBenhNhan.h"

class ThongKeBenhNhan {
public:
    void thongKeTheoGioiTinh(const DanhSachBenhNhan& ds);
    void thongKeTheoDoTuoi(const DanhSachBenhNhan& ds);
    void thongKeTheoTrangThai(const DanhSachBenhNhan& ds);
    void thongKeTheoUuTien(const DanhSachBenhNhan& ds);
};

#endif

