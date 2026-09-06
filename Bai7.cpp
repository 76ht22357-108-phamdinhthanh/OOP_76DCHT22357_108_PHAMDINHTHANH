#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        for (int i = 0; i < 4; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    void xuat() {
        cout << "\nHo ten: " << hoTen;
        cout << "\nNam sinh: " << namSinh;
        cout << "\nDiem: ";

        for (int i = 0; i < 4; i++)
            cout << diem[i] << " ";

        cout << "\nDiem trung binh: " << tinhDTB() << endl;
    }

    float tinhDTB() {
        float tong = 0;

        for (int i = 0; i < 4; i++)
            tong += diem[i];

        return tong / 4;
    }

    bool totNghiep() {
        if (tinhDTB() < 7)
            return false;

        for (int i = 0; i < 4; i++) {
            if (diem[i] < 5)
                return false;
        }

        return true;
    }
};

int main() {
    int n;

    cout << "Nhap so sinh vien: ";
    cin >> n;

    SinhVien ds[100];

    for (int i = 0; i < n; i++) {
        cout << "\n===== SINH VIEN " << i + 1 << " =====\n";
        ds[i].nhap();
    }

    cout << "\n\n===== SINH VIEN DU DIEU KIEN TOT NGHIEP =====\n";

    for (int i = 0; i < n; i++) {
        if (ds[i].totNghiep()) {
            ds[i].xuat();
        }
    }

    return 0;
}
