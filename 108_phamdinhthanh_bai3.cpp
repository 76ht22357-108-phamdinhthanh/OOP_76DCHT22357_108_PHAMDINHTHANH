#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NhanVien {
    string ten;
    int tuoi;

    void nhap() {
        cout << "Nhap ten: ";
        cin >> ten;

        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void xuat() const {
        cout << "Ten: " << ten << " | Tuoi: " << tuoi << endl;
    }
};

int main() {
    int n = 10;

    // ==========================================
    // CACH 1: MANG TINH
    // ==========================================
    cout << "\n=== CACH 1: MANG TINH ===" << endl;

    NhanVien dsnv_tinh[10];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien " << i + 1 << ":" << endl;
        dsnv_tinh[i].nhap();
    }

    cout << "\n--- Danh sach nhan vien (Mang tinh) ---" << endl;

    for (int i = 0; i < n; i++) {
        dsnv_tinh[i].xuat();
    }


    // ==========================================
    // CACH 2: MANG DONG
    // ==========================================
    cout << "\n=== CACH 2: MANG DONG ===" << endl;

    NhanVien *dsnv_dong = new NhanVien[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien " << i + 1 << ":" << endl;
        dsnv_dong[i].nhap();
    }

    cout << "\n--- Danh sach nhan vien (Mang dong) ---" << endl;

    for (int i = 0; i < n; i++) {
        dsnv_dong[i].xuat();
    }

    // Giai phong bo nho
    delete[] dsnv_dong;


    // ==========================================
    // CACH 3: VECTOR
    // ==========================================
    cout << "\n=== CACH 3: VECTOR ===" << endl;

    vector<NhanVien> ds_vector;

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien " << i + 1 << ":" << endl;

        NhanVien nv;
        nv.nhap();

        ds_vector.push_back(nv);
    }

    cout << "\n--- Danh sach nhan vien (Vector) ---" << endl;

    for (int i = 0; i < ds_vector.size(); i++) {
        ds_vector[i].xuat();
    }

    return 0;
}
