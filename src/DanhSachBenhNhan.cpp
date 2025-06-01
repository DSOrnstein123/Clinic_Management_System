#include "../include/DanhSachBenhNhan.h"
#include "../include/Global.h"
#include "../include/Utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void DanhSachBenhNhan::themBenhNhan()
{
    string maSo;
    cout << "Nhap ma so benh nhan: ";
    getline(cin, maSo);

    if (kiemTraTrungMa(maSo))
    {
        cout << ">> Ma so bi trung, vui long nhap lai!\n";
        return;
    }

    BenhNhan bn;
    bn.setMaSo(maSo);
    bn.nhapThongTin();

    danhSach.push_back(bn);
    cout << ">> Da them benh nhan thanh cong!\n";
    hethong.ghiLog("Them benh nhan: " + maSo);
}

void DanhSachBenhNhan::hienThiDanhSach()
{
    if (danhSach.empty())
    {
        cout << ">> Danh sach benh nhan rong.\n";
        return;
    }

    cout << left
         << setw(10) << "Ma so"
         << setw(20) << "Ho ten"
         << setw(6) << "Tuoi"
         << setw(10) << "Gioi tinh"
         << setw(14) << "Uu tien"
         << setw(12) << "Trang thai"
         << setw(20) << "Thoi gian den"
         << endl;

    for (const auto &bn : danhSach)
    {
        bn.xuatThongTin();
    }
}

void DanhSachBenhNhan::capNhatBenhNhan()
{
    string maSo;
    cout << "Nhap ma so can cap nhat: ";
    getline(cin, maSo);

    int viTri = timViTriTheoMa(maSo);
    if (viTri == -1)
    {
        cout << ">> Khong tim thay benh nhan.\n";
        return;
    }

    danhSach[viTri].capNhatThongTin();
    cout << ">> Da cap nhat thong tin benh nhan!\n";
    hethong.ghiLog("Cap nhat benh nhan: " + maSo);
}

void DanhSachBenhNhan::xoaBenhNhan()
{
    string maSo;
    cout << "Nhap ma so can xoa: ";
    getline(cin, maSo);

    int viTri = timViTriTheoMa(maSo);
    if (viTri == -1)
    {
        cout << ">> Khong tim thay benh nhan.\n";
        hethong.ghiLog("Xoa that bai (khong tim thay): " + maSo);
        return;
    }

    string ten = danhSach[viTri].getHoTen();
    danhSach.erase(danhSach.begin() + viTri);
    cout << ">> Da xoa benh nhan thanh cong!\n";
    hethong.ghiLog("Xoa benh nhan: " + maSo + " - " + ten);
}

void DanhSachBenhNhan::xuatDanhSachRaFile(const string &tenFile)
{
    ofstream out(tenFile);
    if (!out)
    {
        cout << ">> Loi mo file: " << tenFile << endl;
        return;
    }
    cout << "Da xuat danh sach ra file benhnhan_out.txt\n";

    out << left
        << setw(10) << "Ma so"
        << setw(20) << "Ho ten"
        << setw(6) << "Tuoi"
        << setw(10) << "Gioi tinh"
        << setw(14) << "Uu tien"
        << setw(12) << "Trang thai"
        << setw(20) << "Thoi gian den"
        << endl;

    for (const auto &bn : danhSach)
    {
        out << left
            << setw(10) << bn.getMaSo()
            << setw(20) << bn.getHoTen()
            << setw(6) << bn.getTuoi()
            << setw(10) << bn.getGioiTinh()
            << setw(14) << bn.getMucUuTien()
            << setw(12) << (bn.getDaKham() ? "Da kham" : "Chua kham")
            << setw(20) << bn.getThoiGianDenAsString()
            << endl;
    }

    out.close();
    hethong.ghiLog("Xuat danh sach ra file: " + tenFile);
}

void DanhSachBenhNhan::ghiDanhSachRaFileCSV(const string &tenFile)
{
    ofstream fout(tenFile);
    if (!fout.is_open())
    {
        cout << ">> Khong the ghi file: " << tenFile << endl;
        return;
    }

    for (const auto &bn : danhSach)
    {
        fout << bn.getMaSo() << ","
             << bn.getHoTen() << ","
             << bn.getTuoi() << ","
             << bn.getGioiTinh() << ","
             << bn.getMucUuTien() << ","
             << (bn.getDaKham() ? "1" : "0") << endl;
    }

    fout.close();
    hethong.ghiLog("Ghi danh sach ra file CSV: " + tenFile);
}

bool DanhSachBenhNhan::docDanhSachTuFile(const string &tenFile)
{
    ifstream in(tenFile);
    if (!in)
    {
        cout << ">> Loi mo file: " << tenFile << endl;
        return false;
    }

    danhSach.clear();
    string line;
    while (getline(in, line))
    {
        if (line.empty())
            continue;

        vector<string> fields;
        string field;
        for (char c : line)
        {
            if (c == ',')
            {
                fields.push_back(field);
                field.clear();
            }
            else
                field += c;
        }
        fields.push_back(field);

        if (fields.size() >= 6)
        {
            try
            {
                int tuoi = stoi(fields[2]);
                BenhNhan bn(fields[0], fields[1], tuoi, fields[3], fields[4]);
                if (fields[5] == "1")
                    bn.setTrangThaiDaKham();
                danhSach.push_back(bn);
            }
            catch (const exception &e)
            {
                cout << ">> Loi doc dong: \"" << line << "\"\n";
                cout << ">> Chi tiet loi: " << e.what() << endl;
            }
        }
    }

    in.close();
    hethong.ghiLog("Doc file: " + tenFile);
    return true;
}

const vector<BenhNhan> &DanhSachBenhNhan::getDanhSach() const
{
    return danhSach;
}

vector<BenhNhan> &DanhSachBenhNhan::getDanhSach()
{
    return danhSach;
}

int DanhSachBenhNhan::timViTriTheoMa(const string &ma)
{
    for (size_t i = 0; i < danhSach.size(); ++i)
    {
        if (danhSach[i].getMaSo() == ma)
            return static_cast<int>(i);
    }
    return -1;
}

bool DanhSachBenhNhan::kiemTraTrungMa(const string &ma)
{
    for (const auto &bn : danhSach)
    {
        if (bn.getMaSo() == ma)
            return true;
    }
    return false;
}

void DanhSachBenhNhan::clear()
{
    danhSach.clear();
}
