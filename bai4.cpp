#include <iostream>

using namespace std;

class Nguoi
{
protected:
    string hoTen;
    int namSinh;

public:
    Nguoi()
    {
        hoTen = "";
        namSinh = 0;
    }

    Nguoi(string ht, int ns)
    {
        hoTen = ht;
        namSinh = ns;
    }

    void nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen); // "cin >> ws" tự động xóa bỏ các khoảng trắng/dòng trống còn sót lại

        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    void xuat()
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
    }
};

// Khai báo lớp SinhVien kế thừa từ lớp Nguoi
class SinhVien : public Nguoi
{
private:
    string maSV;
    float diemTB;

public:
    SinhVien() : Nguoi()
    {
        maSV = "";
        diemTB = 0;
    }

    SinhVien(string ht, int ns, string ma, float dtb)
        : Nguoi(ht, ns)
    {
        maSV = ma;
        diemTB = dtb;
    }

    // Tái sử dụng phương thức nhap() của lớp Nguoi
    void nhap()
    {
        Nguoi::nhap(); // Gọi hàm nhập của lớp cha để nhập hoTen và namSinh

        cout << "Nhap ma sinh vien: ";
        getline(cin >> ws, maSV);

        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }

    // Tái sử dụng phương thức xuat() của lớp Nguoi
    void xuat()
    {
        Nguoi::xuat(); // Gọi hàm xuất của lớp cha
        cout << "Ma sinh vien: " << maSV << endl;
        cout << "Diem trung binh: " << diemTB << endl;
    }

    float getDiemTB()
    {
        return diemTB;
    }
};

// ================= CÂU 3 =================

int main()
{
    cout << "===== CHAY THU HAM TAO CO DOI =====" << endl;
    SinhVien sv1("Pham Dinh Thanh", 2006, "SV001", 8.5);
    sv1.xuat();

    int n;
    cout << "\n===== NHAP DANH SACH SINH VIEN =====" << endl;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien sv[100];

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap sinh vien thu " << i + 1 << ":" << endl;
        sv[i].nhap();
    }

    // Sắp xếp giảm dần theo điểm trung bình (Selection Sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sv[i].getDiemTB() < sv[j].getDiemTB())
            {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }

    cout << "\n===== DANH SACH SINH VIEN GIAM DAN THEO DIEM TB =====" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\nSinh vien thu " << i + 1 << ":" << endl;
        sv[i].xuat();
    }

    return 0;
}
