#ifndef TIMKIEMBENHNHAN_H
#define TIMKIEMBENHNHAN_H

#include "BenhNhan.h"
#include <vector>
#include <string>
#include <utility>

#define HASH_SIZE 1000

class TimKiemBenhNhan
{
private:
    std::vector<std::pair<std::string, BenhNhan>> bangBam[HASH_SIZE];
    int hashFunc(const std::string &key);

public:
    void taoBangBam(const std::vector<BenhNhan> &danhSach);
    void timKiemTheoMaHash();
    void timKiemTheoTen(const std::vector<BenhNhan> &danhSach, const std::string &ten);
};

#endif
