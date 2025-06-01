#include "../include/BenhNhan.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

BenhNhan::BenhNhan()
{
    daKham = false;
    thoiGianDen = time(nullptr);
}

BenhNhan::BenhNhan(string maSo, string hoTen, int tuoi, string gioiTinh, string mucUuTien)
    : maSo(maSo), hoTen(hoTen), tuoi(tuoi), gioiTinh(gioiTinh), mucUuTien(mucUuTien)
{
    daKham = false;
    thoiGianDen = time(nullptr);
}

void BenhNhan::nhapThongTin()
{
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap gioi tinh (Nam / Nu): ";
    getline(cin, gioiTinh);

    cout << "Nhap muc uu tien (Cap cuu / Thong thuong / Tai kham): ";
    getline(cin, mucUuTien);

    daKham = false;
    thoiGianDen = time(nullptr);
}

void BenhNhan::xuatThongTin() const
{
    cout << left
         << setw(10) << maSo
         << setw(20) << hoTen
         << setw(6) << tuoi
         << setw(10) << gioiTinh
         << setw(14) << mucUuTien
         << setw(12) << (daKham ? "Da kham" : "Chua kham")
         << setw(20) << getThoiGianDenAsString()
         << endl;
}

void BenhNhan::capNhatThongTin()
{
    cout << "\n--- Cap nhat thong tin benh nhan ---\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ho ten cu: " << hoTen << "\nNhap moi (bo qua = giu nguyen): ";
    string temp;
    getline(cin, temp);
    if (!temp.empty())
        hoTen = temp;

    cout << "Tuoi cu: " << tuoi << "\nNhap tuoi moi (0 = giu nguyen): ";
    int tuoiMoi;
    cin >> tuoiMoi;
    if (tuoiMoi > 0)
        tuoi = tuoiMoi;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Gioi tinh cu: " << gioiTinh << "\nNhap moi (bo qua = giu nguyen): ";
    getline(cin, temp);
    if (!temp.empty())
        gioiTinh = temp;

    cout << "Muc uu tien cu: " << mucUuTien << "\nNhap moi (bo qua = giu nguyen): ";
    getline(cin, temp);
    if (!temp.empty())
        mucUuTien = temp;

    cout << ">> Cap nhat thanh cong!\n";
}

string BenhNhan::getMaSo() const
{
    return maSo;
}

string BenhNhan::getHoTen() const
{
    return hoTen;
}

int BenhNhan::getTuoi() const
{
    return tuoi;
}

string BenhNhan::getGioiTinh() const
{
    return gioiTinh;
}

string BenhNhan::getMucUuTien() const
{
    return mucUuTien;
}

bool BenhNhan::getDaKham() const
{
    return daKham;
}

time_t BenhNhan::getThoiGianDen() const
{
    return thoiGianDen;
}

string BenhNhan::getThoiGianDenAsString() const
{
    char buffer[30];
    tm *timeinfo = localtime(&thoiGianDen);
    strftime(buffer, sizeof(buffer), "%H:%M:%S %d/%m/%Y", timeinfo);
    return string(buffer);
}

int BenhNhan::getDoUuTien() const
{
    if (mucUuTien == "Cap cuu")
        return 1;
    if (mucUuTien == "Tai kham")
        return 2;
    return 3;
}

void BenhNhan::setTrangThaiDaKham()
{
    daKham = true;
}

void BenhNhan::setMaSo(const string &ms)
{
    maSo = ms;
}

bool BenhNhan::operator<(const BenhNhan &other) const
{
    if (getDoUuTien() != other.getDoUuTien())
        return getDoUuTien() < other.getDoUuTien();
    return thoiGianDen > other.thoiGianDen;
}
