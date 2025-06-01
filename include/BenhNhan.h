#ifndef BENHNHAN_H
#define BENHNHAN_H

#include <string>
#include <ctime>

class BenhNhan
{
private:
    std::string maSo;
    std::string hoTen;
    int tuoi;
    std::string gioiTinh;
    std::string mucUuTien;
    bool daKham;
    time_t thoiGianDen;

public:
    BenhNhan();
    BenhNhan(std::string maSo, std::string hoTen, int tuoi, std::string gioiTinh, std::string mucUuTien);

    void nhapThongTin();
    void xuatThongTin() const;
    void capNhatThongTin();

    std::string getMaSo() const;
    std::string getHoTen() const;
    int getTuoi() const;
    std::string getGioiTinh() const;
    std::string getMucUuTien() const;
    bool getDaKham() const;
    time_t getThoiGianDen() const;
    std::string getThoiGianDenAsString() const;
    int getDoUuTien() const;

    void setTrangThaiDaKham();
    void setMaSo(const std::string &ms);

    bool operator<(const BenhNhan &other) const;
};

#endif
