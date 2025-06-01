#include "../include/DanhSachChoKham.h"
#include <iostream>
#include <iomanip>

using namespace std;

void DanhSachChoKham::themVaoHangDoi(const BenhNhan &bn)
{
    hangDoi.push_back(bn);
    sapXepTheoUuTien();
}

BenhNhan DanhSachChoKham::goiBenhNhan()
{
    if (hangDoi.empty())
    {
        cout << ">> Khong co benh nhan trong danh sach cho.\n";
        return BenhNhan();
    }

    sapXepTheoUuTien();

    BenhNhan bn = hangDoi.front();
    hangDoi.erase(hangDoi.begin());
    return bn;
}

bool DanhSachChoKham::rong() const
{
    return hangDoi.empty();
}

void DanhSachChoKham::hienThiHangDoi() const
{
    if (hangDoi.empty())
    {
        cout << ">> Danh sach cho dang rong.\n";
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

    for (const auto &bn : hangDoi)
    {
        bn.xuatThongTin();
    }
}

void DanhSachChoKham::xoaToanBo()
{
    hangDoi.clear();
}

int DanhSachChoKham::soLuong() const
{
    return static_cast<int>(hangDoi.size());
}

void DanhSachChoKham::sapXepTheoUuTien()
{
    if (hangDoi.size() <= 1)
        return;
    mergeSort(0, hangDoi.size() - 1);
}

void DanhSachChoKham::mergeSort(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void DanhSachChoKham::merge(int left, int mid, int right)
{
    vector<BenhNhan> trai(hangDoi.begin() + left, hangDoi.begin() + mid + 1);
    vector<BenhNhan> phai(hangDoi.begin() + mid + 1, hangDoi.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < trai.size() && j < phai.size())
    {
        if (trai[i] < phai[j])
            hangDoi[k++] = trai[i++];
        else
            hangDoi[k++] = phai[j++];
    }

    while (i < trai.size())
        hangDoi[k++] = trai[i++];
    while (j < phai.size())
        hangDoi[k++] = phai[j++];
}
