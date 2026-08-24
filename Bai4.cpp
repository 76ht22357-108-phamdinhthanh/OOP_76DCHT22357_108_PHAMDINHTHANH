#include <iostream>
#include <string>

using namespace std;

class NhanVien
{
private:
    string ten;
    int tuoi;

public:
    // Constructor không đối
    NhanVien()
    {
        ten = "";
        tuoi = 0;
    }

    // Constructor có đối
    NhanVien(string t, int tuoi)
    {
        ten = t;
        this->tuoi = tuoi;
    }

    // Nhập thông tin
    void nhap()
    {
        cout << "Nhap ten: ";
        cin >> ten;

        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    // Xuất thông tin
    void xuat()
    {
        cout << ten << "\t\t" << tuoi << endl;
    }
};

int main()
{
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    // ==============================
    // CACH 2: DUNG MANG DONG
    // ==============================

    NhanVien *dsnv;

    // Cap phat mang dong
    dsnv = new NhanVien[n];

    // Nhap du lieu cho mang
    for (int i = 0; i < n; i++)
    {
        cout << "\n=== NHAP THONG TIN CHO NHAN VIEN " << i + 1 << " ===" << endl;
        dsnv[i].nhap();
    }

    // Xuat du lieu theo cot
    cout << "\n======================================" << endl;
    cout << "        DANH SACH NHAN VIEN" << endl;
    cout << "======================================" << endl;

    cout << "STT\tTen\t\tTuoi" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t";
        dsnv[i].xuat();
    }

    // Giai phong bo nho
    delete[] dsnv;

    return 0;
}
