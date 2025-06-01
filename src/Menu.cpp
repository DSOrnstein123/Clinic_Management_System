#include <iostream>
#include <string>

#include "../include/Menu.h"
#include "../include/BenhNhan.h"
#include "../include/DanhSachBenhNhan.h"
#include "../include/DanhSachChoKham.h"
#include "../include/TimKiemBenhNhan.h"
#include "../include/ThongKeBenhNhan.h"
#include "../include/HeThong.h"
#include "../include/Global.h"
#include "../include/Utils.h"

using namespace std;

void showMainMenu()
{
    int luaChon;
    do
    {
        xoaManHinh();
        cout << "====== MENU CHINH ======\n";
        cout << "1. Quan ly benh nhan\n";
        cout << "2. Danh sach cho kham\n";
        cout << "3. Tra cuu - Tim kiem\n";
        cout << "4. Bao cao - Thong ke\n";
        cout << "5. He thong\n";
        cout << "0. Thoat\n";
        luaChon = nhapSoNguyen("Nhap lua chon: ");

        switch (luaChon)
        {
        case 1:
            menuQuanLyBenhNhan();
            break;
        case 2:
            menuDanhSachChoKham();
            break;
        case 3:
            menuTraCuuBenhNhan();
            break;
        case 4:
            menuThongKeBenhNhan();
            break;
        case 5:
            menuHeThong();
            break;
        case 0:
            hethong.ghiFileCSV(manager, "data/benhnhan.txt");
            hethong.ghiFileCSV(manager, "data/benhnhan.csv");
            hethong.ghiLog("Luu du lieu va thoat chuong trinh");
            cout << "Tam biet!\n";
            break;

        default:
            cout << "Lua chon khong hop le. Vui long thu lai!\n";
            tamDung();
        }
    } while (luaChon != 0);
}

void menuQuanLyBenhNhan()
{
    int chon;
    do
    {
        xoaManHinh();
        cout << "=== QUAN LY BENH NHAN ===\n";
        cout << "1. Them benh nhan\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Cap nhat thong tin\n";
        cout << "4. Xoa benh nhan\n";
        cout << "5. Xuat danh sach ra file (benhnhan_out.txt)\n";
        cout << "0. Quay lai\n";
        chon = nhapSoNguyen("Nhap lua chon: ");

        switch (chon)
        {
        case 1:
            manager.themBenhNhan();
            hethong.ghiLog("Them benh nhan moi");
            tamDung();
            break;
        case 2:
            manager.hienThiDanhSach();
            hethong.ghiLog("Hien thi danh sach benh nhan");
            tamDung();
            break;
        case 3:
            manager.capNhatBenhNhan();
            hethong.ghiLog("Cap nhat thong tin benh nhan");
            tamDung();
            break;
        case 4:
            manager.xoaBenhNhan();
            hethong.ghiLog("Xoa benh nhan");
            tamDung();
            break;
        case 5:
            manager.xuatDanhSachRaFile("data/benhnhan_out.txt");
            hethong.ghiLog("Xuat danh sach ra file TXT");
            tamDung();
            break;
        }
    } while (chon != 0);
}

void menuDanhSachChoKham()
{
    int chon;
    do
    {
        xoaManHinh();
        cout << "=== DANH SACH CHO KHAM ===\n";
        cout << "1. Them benh nhan vao hang doi\n";
        cout << "2. Hien thi danh sach cho\n";
        cout << "3. Goi benh nhan uu tien\n";
        cout << "4. Xoa toan bo danh sach\n";
        cout << "0. Quay lai\n";
        chon = nhapSoNguyen("Nhap lua chon: ");

        switch (chon)
        {
        case 1:
        {
            string ma;
            cout << "Nhap ma so benh nhan can chen: ";
            getline(cin, ma);
            int viTri = manager.timViTriTheoMa(ma);
            if (viTri != -1)
            {
                danhSachCho.themVaoHangDoi(manager.getDanhSach()[viTri]);
                hethong.ghiLog("Them vao hang doi: " + ma);
            }
            else
            {
                cout << ">> Khong tim thay benh nhan!\n";
                hethong.ghiLog("Them vao hang doi that bai (khong tim thay): " + ma);
            }
            tamDung();
            break;
        }
        case 2:
            danhSachCho.hienThiHangDoi();
            hethong.ghiLog("Hien thi danh sach cho kham");
            tamDung();
            break;
        case 3:
        {
            BenhNhan goi = danhSachCho.goiBenhNhan();
            if (!goi.getMaSo().empty())
            {
                goi.xuatThongTin();
                hethong.ghiLog("Goi benh nhan uu tien: " + goi.getMaSo());
                int viTri = manager.timViTriTheoMa(goi.getMaSo());
                if (viTri != -1)
                    manager.getDanhSach()[viTri].setTrangThaiDaKham();
            }
            else
            {
                cout << ">> Khong co benh nhan nao trong danh sach!\n";
                hethong.ghiLog("Goi benh nhan that bai (danh sach rong)");
            }
            tamDung();
            break;
        }
        case 4:
            danhSachCho.xoaToanBo();
            hethong.ghiLog("Xoa toan bo danh sach cho kham");
            tamDung();
            break;
        }
    } while (chon != 0);
}

void menuTraCuuBenhNhan()
{
    int chon;
    do
    {
        xoaManHinh();
        cout << "=== TRA CUU BENH NHAN ===\n";
        cout << "1. Tim theo ma so (bang bam)\n";
        cout << "2. Tim theo ho ten\n";
        cout << "3. Hien thi tat ca\n";
        cout << "0. Quay lai\n";
        chon = nhapSoNguyen("Nhap lua chon: ");

        switch (chon)
        {
        case 1:
        {
            TimKiemBenhNhan tk;
            tk.taoBangBam(manager.getDanhSach());
            tk.timKiemTheoMaHash();
            hethong.ghiLog("Tra cuu benh nhan theo ma bang bang bam");
            tamDung();
            break;
        }
        case 2:
        {
            string ten;
            cout << "Nhap ten can tim: ";
            getline(cin, ten);
            TimKiemBenhNhan tk;
            tk.timKiemTheoTen(manager.getDanhSach(), ten);
            hethong.ghiLog("Tra cuu benh nhan theo ten: " + ten);
            tamDung();
            break;
        }
        case 3:
            manager.hienThiDanhSach();
            hethong.ghiLog("Hien thi tat ca benh nhan trong tra cuu");
            tamDung();
            break;
        }
    } while (chon != 0);
}

void menuThongKeBenhNhan()
{
    ThongKeBenhNhan thongke;
    int chon;
    do
    {
        xoaManHinh();
        cout << "=== THONG KE BENH NHAN ===\n";
        cout << "1. Theo gioi tinh\n";
        cout << "2. Theo do tuoi\n";
        cout << "3. Theo trang thai da kham\n";
        cout << "4. Theo muc uu tien\n";
        cout << "0. Quay lai\n";
        chon = nhapSoNguyen("Nhap lua chon: ");

        switch (chon)
        {
        case 1:
            thongke.thongKeTheoGioiTinh(manager);
            hethong.ghiLog("Thong ke theo gioi tinh");
            tamDung();
            break;
        case 2:
            thongke.thongKeTheoDoTuoi(manager);
            hethong.ghiLog("Thong ke theo do tuoi");
            tamDung();
            break;
        case 3:
            thongke.thongKeTheoTrangThai(manager);
            hethong.ghiLog("Thong ke theo trang thai da kham");
            tamDung();
            break;
        case 4:
            thongke.thongKeTheoUuTien(manager);
            hethong.ghiLog("Thong ke theo muc uu tien");
            tamDung();
            break;
        }
    } while (chon != 0);
}

void menuHeThong()
{
    HeThong ht;
    int chon;
    do
    {
        xoaManHinh();
        cout << "=== MENU HE THONG ===\n";
        cout << "1. Xuat danh sach ra file TXT\n";
        cout << "2. Xuat danh sach ra file CSV\n";
        cout << "3. Doc danh sach tu file TXT\n";
        cout << "4. Reset he thong (xoa toan bo)\n";
        cout << "5. Ghi log thu cong\n";
        cout << "0. Quay lai\n";
        chon = nhapSoNguyen("Nhap lua chon: ");

        switch (chon)
        {
        case 1:
            ht.ghiFileTXT(manager, "data/benhnhan_out.txt");
            hethong.ghiLog("Xuat danh sach ra file TXT");
            break;
        case 2:
            ht.ghiFileCSV(manager, "data/benhnhan_out.csv");
            hethong.ghiLog("Xuat danh sach ra file CSV");
            break;
        case 3:
            ht.docFileTXT(manager, "data/benhnhan.txt");
            hethong.ghiLog("Doc danh sach tu file TXT");
            break;
        case 4:
            ht.resetHeThong(manager);
            hethong.ghiLog("Reset he thong (xoa danh sach benh nhan)");
            break;
        case 5:
        {
            string nd;
            cout << "Nhap noi dung log: ";
            getline(cin, nd);
            ht.ghiLog("Thu cong: " + nd);
            break;
        }
        }

        tamDung();
    } while (chon != 0);
}
