#ifndef DANHSACHCHOKHAM_H
#define DANHSACHCHOKHAM_H

#include "BenhNhan.h"
#include <vector>

class DanhSachChoKham
{
private:
    std::vector<BenhNhan> hangDoi;

    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);

public:
    void themVaoHangDoi(const BenhNhan &bn);

    BenhNhan goiBenhNhan();

    bool rong() const;

    void hienThiHangDoi() const;

    void xoaToanBo();

    int soLuong() const;

    void sapXepTheoUuTien();
};

#endif
