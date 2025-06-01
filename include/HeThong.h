#ifndef HETHONG_H
#define HETHONG_H

#include "DanhSachBenhNhan.h"

class HeThong
{
public:
    void ghiFileTXT(const DanhSachBenhNhan &ds, const std::string &tenFile);

    void ghiFileCSV(const DanhSachBenhNhan &ds, const std::string &tenFile);

    void docFileTXT(DanhSachBenhNhan &ds, const std::string &tenFile);

    void resetHeThong(DanhSachBenhNhan &ds);

    void ghiLog(const std::string &noiDung);
};

#endif
