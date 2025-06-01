#ifndef DANHSACHBENHNHAN_H
#define DANHSACHBENHNHAN_H

#include "BenhNhan.h"
#include <vector>
#include <string>

class DanhSachBenhNhan
{
private:
    std::vector<BenhNhan> danhSach;

public:
    void themBenhNhan();

    void hienThiDanhSach();

    void capNhatBenhNhan();

    void xoaBenhNhan();

    bool kiemTraTrungMa(const std::string &ma);

    void xuatDanhSachRaFile(const std::string &tenFile);

    void ghiDanhSachRaFileCSV(const std::string &tenFile);

    bool docDanhSachTuFile(const std::string &tenFile);

    const std::vector<BenhNhan> &getDanhSach() const;
    std::vector<BenhNhan> &getDanhSach();

    void clear();

    int timViTriTheoMa(const std::string &ma);
};

#endif
