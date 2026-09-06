#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        for (int i = 0; i < 5; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    void xuat() {
        cout << "\nHo ten: " << hoTen;
        cout << "\nNam sinh: " << namSinh;
        cout << "\nDiem: ";

        for (int i = 0; i < 5; i++)
            cout << diem[i] << " ";

        cout << "\nDiem trung binh: " << tinhDTB() << endl;
    }

    float tinhDTB() {
        float tong = 0;

        for (int i = 0; i < 5; i++)
            tong += diem[i];

        return tong / 5;
    }

    void thiLai() {
        bool coThiLai = false;

        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) {
                cout << "\nMon " << i + 1
                     << " - Diem: " << diem[i];
                coThiLai = true;
            }
        }

        if (coThiLai) {
            cout << "\nSinh vien: " << hoTen << " phai thi lai.";
        }
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

    cout << "\n\n===== DANH SACH SINH VIEN PHAI THI LAI =====\n";

    for (int i = 0; i < n; i++) {
        ds[i].thiLai();
        cout << endl;
    }

    return 0;
}
