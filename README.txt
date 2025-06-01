============================================================
 HỆ THỐNG QUẢN LÝ KHÁM BỆNH - NHÓM 75 (Ngôn ngữ: C++)
============================================================
1. GIỚI THIỆU
  Đây là chương trình quản lý bệnh nhân đơn giản, giúp bạn:
    - Quản lý bệnh nhân
    - Tìm kiếm bệnh nhân
    - Quản lý danh sách chờ khám
    - Xuất dữ liệu
    - Thống kê tổng hợp
    - Tự động ghi lại lịch sử chỉnh sửa

2. CÁCH CHẠY CHƯƠNG TRÌNH
  Bước 1: Giải nén file nếu chương trình được nén dưới dạng .zip/.rar  
  Bước 2: Chạy file `ClinicManagementSystem.exe` bằng cách **nhấp đúp chuột** hoặc:
    - Mở `Command Prompt` (cmd)
    - Di chuyển đến thư mục chứa file: cd đường_dẫn_đến_thư_mục
    - Gõ lệnh: ClinicManagementSystem.exe

3. HƯỚNG DẪN SỬ DỤNG
  Chương trình hoạt động theo mô hình menu phân cấp. Người dùng chỉ cần nhập số tương ứng để thao tác. Sau khi chạy, chương trình sẽ hiển thị menu:

  ====== MENU CHINH ======
  1. Quan ly benh nhan
  2. Danh sach cho kham
  3. Tra cuu - Tim kiem
  4. Bao cao - Thong ke
  5. He thong
  0. Thoat
  Nhap lua chon:

  Nhập lựa chọn từ bàn phím theo hướng dẫn hiển thị trên màn hình.

  -> Chọn 1. Quan ly benh nhan:
    === QUAN LY BENH NHAN ===
    1. Them benh nhan
    2. Hien thi danh sach
    3. Cap nhat thong tin
    4. Xoa benh nhan
    5. Xuat danh sach ra file hien thi (benhnhan_out.txt)
    0. Quay lai menu chinh
    Nhap lua chon:

  -> Chọn 2. Danh sach cho kham:
    === DANH SACH CHO KHAM ===
    1. Them benh nhan vao hang doi
    2. Hien thi danh sach cho
    3. Goi benh nhan uu tien
    4. Xoa toan bo danh sach
    0. Quay lai
    Nhap lua chon:

  -> Chọn 3. Tra cuu - Tim kiem:
    === TIM KIEM BENH NHAN ===
    1. Tim theo ma so
    2. Tim theo ten
    3. Hien thi tat ca
    0. Quay lai
    Nhap lua chon:

  -> Chọn 4. Bao cao - Thong ke:
    === LOC VA THONG KE ===
    1. Theo gioi tinh
    2. Theo do tuoi
    3. Theo trang thai
    4. Theo muc uu tien
    0. Quay lai
    Nhap lua chon:

  -> Chọn 5. Thao tac he thong:
    === CAU HINH HE THONG ===
    1. Xuat danh sach ra file TXT
    2. Xuat danh sach ra file CSV
    3. Doc danh sach tu file TXT
    4. Reset he thong (xoa toan bo)
    5. Ghi log thu cong
    0. Quay lai
    Nhap lua chon:

4. CẤU TRÚC THƯ MỤC
  /project-folder
  │
  ├── data                             (Dữ liệu bệnh nhân và log)
  ├── src                              (Chứa mã nguồn)
  ├── include                          (Chứa các file định nghĩa lớp)
  ├── app.exe                          (File chạy chính)
  ├── build.bat                        (File build chương trình)
  ├── README.txt                       (Tệp hướng dẫn)

5. GHI CHÚ
  - Chương trình KHÔNG cần cài đặt. Chỉ cần giải nén (nếu có) và chỉ chạy file `.exe`.
  - Dữ liệu sẽ tự động được lưu vào thư mục `data/` sau mỗi thay đổi.