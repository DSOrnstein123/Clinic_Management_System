#include "../include/HeThong.h"
#include "../include/Utils.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

void HeThong::ghiFileTXT(const DanhSachBenhNhan &ds, const string &tenFile)
{
    ofstream out(tenFile);
    if (!out)
    {
        cout << ">> Khong mo duoc file de ghi: " << tenFile << endl;
        return;
    }

    out << "MA SO     | HO TEN              | TUOI | GIOI TINH | UU TIEN      | TRANG THAI\n";
    out << "-------------------------------------------------------------------------------\n";
    for (const auto &bn : ds.getDanhSach())
    {
        out << bn.getMaSo() << " | "
            << bn.getHoTen() << " | "
            << bn.getTuoi() << " | "
            << bn.getGioiTinh() << " | "
            << bn.getMucUuTien() << " | "
            << (bn.getDaKham() ? "Da kham" : "Chua kham") << "\n";
    }

    out.close();
    cout << ">> Da xuat danh sach ra file TXT: " << tenFile << "\n";
}

void HeThong::ghiFileCSV(const DanhSachBenhNhan &ds, const string &tenFile)
{
    ofstream out(tenFile);
    if (!out)
    {
        cout << ">> Khong mo duoc file de ghi: " << tenFile << endl;
        return;
    }

    out << "MaSo,HoTen,Tuoi,GioiTinh,MucUuTien,TrangThai\n";
    for (const auto &bn : ds.getDanhSach())
    {
        out << bn.getMaSo() << ","
            << bn.getHoTen() << ","
            << bn.getTuoi() << ","
            << bn.getGioiTinh() << ","
            << bn.getMucUuTien() << ","
            << (bn.getDaKham() ? "Da kham" : "Chua kham") << "\n";
    }

    out.close();
    cout << ">> Da xuat danh sach ra file CSV: " << tenFile << "\n";
}

void HeThong::docFileTXT(DanhSachBenhNhan &ds, const string &tenFile)
{
    ds.docDanhSachTuFile(tenFile);
    cout << ">> Da doc du lieu tu file: " << tenFile << "\n";
}

void HeThong::resetHeThong(DanhSachBenhNhan &ds)
{
    ds.clear();
    cout << ">> Da reset toan bo du lieu he thong!\n";
}

void HeThong::ghiLog(const string &noiDung)
{
    ofstream out("data/log.txt", ios::app);
    if (!out)
        return;

    time_t now = time(0);
    char *dt = ctime(&now);
    dt[strcspn(dt, "\n")] = '\0';

    out << "[" << dt << "] " << noiDung << "\n";
    out.close();
}
