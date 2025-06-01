#include "../include/ThongKeBenhNhan.h"
#include "../include/Global.h"
#include "../include/Utils.h"
#include <iostream>

using namespace std;

void ThongKeBenhNhan::thongKeTheoGioiTinh(const DanhSachBenhNhan &ds)
{
    int nam = 0, nu = 0, khac = 0;
    for (const auto &bn : ds.getDanhSach())
    {
        string gt = bn.getGioiTinh();
        if (gt == "Nam")
            nam++;
        else if (gt == "Nu")
            nu++;
        else
            khac++;
    }
    cout << "\n=== THONG KE GIOI TINH ===\n";
    cout << "Nam: " << nam << "\nNu: " << nu << "\nKhac: " << khac << "\n";
}

void ThongKeBenhNhan::thongKeTheoDoTuoi(const DanhSachBenhNhan &ds)
{
    int duoi18 = 0, tu18den60 = 0, tren60 = 0;
    for (const auto &bn : ds.getDanhSach())
    {
        int tuoi = bn.getTuoi();
        if (tuoi < 18)
            duoi18++;
        else if (tuoi <= 60)
            tu18den60++;
        else
            tren60++;
    }
    cout << "\n=== THONG KE DO TUOI ===\n";
    cout << "Duoi 18: " << duoi18 << "\n18-60: " << tu18den60 << "\nTren 60: " << tren60 << "\n";
}

void ThongKeBenhNhan::thongKeTheoTrangThai(const DanhSachBenhNhan &ds)
{
    int daKham = 0, chuaKham = 0;
    for (const auto &bn : ds.getDanhSach())
    {
        if (bn.getDaKham())
            daKham++;
        else
            chuaKham++;
    }
    cout << "\n=== THONG KE TRANG THAI ===\n";
    cout << "Da kham: " << daKham << "\nChua kham: " << chuaKham << "\n";
}

void ThongKeBenhNhan::thongKeTheoUuTien(const DanhSachBenhNhan &ds)
{
    int capCuu = 0, taiKham = 0, thongThuong = 0;
    for (const auto &bn : ds.getDanhSach())
    {
        string uuTien = bn.getMucUuTien();
        if (uuTien == "Cap cuu")
            capCuu++;
        else if (uuTien == "Tai kham")
            taiKham++;
        else
            thongThuong++;
    }
    cout << "\n=== THONG KE MUC UU TIEN ===\n";
    cout << "Cap cuu: " << capCuu << "\nTai kham: " << taiKham << "\nThong thuong: " << thongThuong << "\n";
}
