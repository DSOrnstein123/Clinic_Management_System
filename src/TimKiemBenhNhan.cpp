#include "../include/TimKiemBenhNhan.h"
#include <iostream>
#include <iomanip>

using namespace std;

int TimKiemBenhNhan::hashFunc(const std::string &key)
{
    int hash = 0;
    for (char c : key)
    {
        hash = (hash * 31 + c) % HASH_SIZE;
    }
    return hash;
}

void TimKiemBenhNhan::taoBangBam(const std::vector<BenhNhan> &danhSach)
{
    for (int i = 0; i < HASH_SIZE; ++i)
        bangBam[i].clear();

    for (const BenhNhan &bn : danhSach)
    {
        int index = hashFunc(bn.getMaSo());
        bangBam[index].push_back({bn.getMaSo(), bn});
    }
}

void TimKiemBenhNhan::timKiemTheoMaHash()
{
    string maSo;
    cout << "Nhap ma so benh nhan can tim: ";
    getline(cin, maSo);

    int index = hashFunc(maSo);
    bool timThay = false;

    for (const auto &cap : bangBam[index])
    {
        if (cap.first == maSo)
        {
            cout << ">> Da tim thay benh nhan:\n";
            cap.second.xuatThongTin();
            timThay = true;
            break;
        }
    }

    if (!timThay)
        cout << ">> Khong tim thay benh nhan co ma so: " << maSo << endl;
}

void TimKiemBenhNhan::timKiemTheoTen(const vector<BenhNhan> &danhSach, const string &ten)
{
    bool timThay = false;
    for (const auto &bn : danhSach)
    {
        if (bn.getHoTen().find(ten) != string::npos)
        {
            if (!timThay)
            {
                cout << ">> Ket qua tim kiem:\n";
                cout << left
                     << setw(10) << "Ma so"
                     << setw(20) << "Ho ten"
                     << setw(6) << "Tuoi"
                     << setw(10) << "Gioi tinh"
                     << setw(14) << "Uu tien"
                     << setw(12) << "Trang thai"
                     << setw(20) << "Thoi gian den"
                     << endl;
            }
            bn.xuatThongTin();
            timThay = true;
        }
    }

    if (!timThay)
        cout << ">> Khong tim thay benh nhan ten: " << ten << endl;
}
