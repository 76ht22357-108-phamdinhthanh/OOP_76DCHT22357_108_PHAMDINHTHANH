#include <iostream>
#include <string>

using namespace std;

// 1. Khai báo kiểu dữ liệu cấu trúc Nhân viên
struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

// Hàm nhập thông tin cho 1 nhân viên
void nhapNhanVien(NhanVien &nv) {
    cout << "  - Nhập mã nhân viên: ";
    getline(cin, nv.maNV);
    cout << "  - Nhập tên nhân viên: ";
    getline(cin, nv.tenNV);
    cout << "  - Nhập lương cơ bản: ";
    cin >> nv.luongCoBan;
    cout << "  - Nhập hệ số lương: ";
    cin >> nv.heSo;
    cin.ignore();
}

// Hàm xuất thông tin cho 1 nhân viên
void xuatNhanVien(const NhanVien &nv) {
    cout << "Mã NV: " << nv.maNV << endl;
    cout << "Tên NV: " << nv.tenNV << endl;
    cout << "Lương cơ bản: " << nv.luongCoBan << endl;
    cout << "Hệ số lương: " << nv.heSo << endl;
}

// 2. Hàm nhập danh sách n nhân viên
void nhapDanhSach(NhanVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhập thông tin nhân viên thứ " << i + 1 << " ---\n";
        nhapNhanVien(ds[i]);
    }
}

// 3. Hàm xuất danh sách n nhân viên
void xuatDanhSach(const NhanVien ds[], int n) {
    cout << "\n========== DANH SÁCH NHÂN VIÊN ==========\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhân viên thứ " << i + 1 << " ---\n";
        xuatNhanVien(ds[i]);
    }
    cout << "\n=========================================\n";
}

int main() {
    int n;
    NhanVien ds[100];
    return 0;
}
