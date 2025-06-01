@echo off
echo building...
g++ main.cpp src/BenhNhan.cpp src/DanhSachBenhNhan.cpp src/DanhSachChoKham.cpp src/Global.cpp src/HeThong.cpp src/Menu.cpp src/ThongKeBenhNhan.cpp src/TimKiemBenhNhan.cpp src/Utils.cpp -static -o app.exe
pause

