#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;

public:
    // Câu 1: Hàm tạo không đối
    PhanSo()
    {
        tu = 0;
        mau = 1;
    }

    // Hàm tạo có đối
    PhanSo(int t, int m)
    {
        tu = t;
        mau = m;
    }

    // Hàm hủy
    ~PhanSo()
    {
    }

    // Câu 2: Nhập phân số
    void nhap()
    {
        cout << "Nhap tu so: ";
        cin >> tu;

        do
        {
            cout << "Nhap mau so: ";
            cin >> mau;
        } while (mau == 0);
    }

    // Xuất phân số
    void xuat()
    {
        if (mau == 1)
            cout << tu;
        else
            cout << tu << "/" << mau;
    }

    // Tìm UCLN
    int UCLN(int a, int b)
    {
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        return a;
    }

    // Rút gọn phân số
    void rutGon()
    {
        int u = UCLN(tu, mau);

        tu = tu / u;
        mau = mau / u;

        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
    }

    // Cộng hai phân số
    PhanSo cong(PhanSo b)
    {
        PhanSo kq;
        kq.tu = tu * b.mau + b.tu * mau;
        kq.mau = mau * b.mau;
        kq.rutGon();
        return kq;
    }

    // Trừ hai phân số
    PhanSo tru(PhanSo b)
    {
        PhanSo kq;
        kq.tu = tu * b.mau - b.tu * mau;
        kq.mau = mau * b.mau;
        kq.rutGon();
        return kq;
    }

    // Nhân hai phân số
    PhanSo nhan(PhanSo b)
    {
        PhanSo kq;
        kq.tu = tu * b.tu;
        kq.mau = mau * b.mau;
        kq.rutGon();
        return kq;
    }

    // Chia hai phân số
    PhanSo chia(PhanSo b)
    {
        PhanSo kq;
        kq.tu = tu * b.mau;
        kq.mau = mau * b.tu;
        kq.rutGon();
        return kq;
    }
};

int main()
{
    PhanSo a, b;

    cout << "=== NHAP PHAN SO THU NHAT ===" << endl;
    a.nhap();

    cout << "=== NHAP PHAN SO THU HAI ===" << endl;
    b.nhap();

    a.rutGon();
    b.rutGon();

    cout << "\nPhan so thu nhat: ";
    a.xuat();

    cout << "\nPhan so thu hai: ";
    b.xuat();

    PhanSo kq;

    cout << "\n\n=== KET QUA ===" << endl;

    kq = a.cong(b);
    cout << "Cong: ";
    kq.xuat();

    kq = a.tru(b);
    cout << "\nTru: ";
    kq.xuat();

    kq = a.nhan(b);
    cout << "\nNhan: ";
    kq.xuat();

    kq = a.chia(b);
    cout << "\nChia: ";
    kq.xuat();

    return 0;
}
