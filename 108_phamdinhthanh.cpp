#include <iostream>
#include <string>

using namespace std;

// Khai bao lop NhanVien
class NhanVien {
public:
    string maNV;
    string hoTen;
    string ngaySinh;
    string diaChi;

    // Phuong thuc nhap thong tin
    void nhap() {
        cout << "Nhap ma nhan vien: ";
        getline(cin, maNV);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngaySinh);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    // Phuong thuc xuat thong tin
    void xuat() {
        cout << "\n--- THONG TIN NHAN VIEN ---" << endl;
        cout << "Ma nhan vien: " << maNV << endl;
        cout << "Ho va ten   : " << hoTen << endl;
        cout << "Ngay sinh   : " << ngaySinh << endl;
        cout << "Dia chi     : " << diaChi << endl;
    }
};

int main() {
    // Khai bao 1 doi tuong Minh thuoc lop NhanVien
    NhanVien Minh;

    // Nhap thong tin cho Minh
    cout << "=== NHAP THONG TIN CHO NHAN VIEN MINH ===" << endl;
    Minh.nhap();

    // Xuat thong tin cua Minh
    Minh.xuat();

    return 0;
}
