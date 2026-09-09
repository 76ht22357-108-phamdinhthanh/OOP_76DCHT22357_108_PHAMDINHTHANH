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

    // Câu 2: Nạp chồng toán tử nhập >>
    friend istream& operator>>(istream& is, PhanSo& p)
    {
        cout << "Nhap tu so: ";
        is >> p.tu;

        do
        {
            cout << "Nhap mau so: ";
            is >> p.mau;
        } while (p.mau == 0);

        return is;
    }

    // Nạp chồng toán tử xuất <<
    friend ostream& operator<<(ostream& os, PhanSo p)
    {
        if (p.mau == 1)
            os << p.tu;
        else
            os << p.tu << "/" << p.mau;

        return os;
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

    // Rút gọn
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

    // Câu 3: Toán tử +
    PhanSo operator+(PhanSo b)
    {
        PhanSo kq;

        kq.tu = tu * b.mau + b.tu * mau;
        kq.mau = mau * b.mau;

        kq.rutGon();

        return kq;
    }

    // Toán tử -
    PhanSo operator-(PhanSo b)
    {
        PhanSo kq;

        kq.tu = tu * b.mau - b.tu * mau;
        kq.mau = mau * b.mau;

        kq.rutGon();

        return kq;
    }

    // Toán tử *
    PhanSo operator*(PhanSo b)
    {
        PhanSo kq;

        kq.tu = tu * b.tu;
        kq.mau = mau * b.mau;

        kq.rutGon();

        return kq;
    }

    // Toán tử /
    PhanSo operator/(PhanSo b)
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
    cin >> a;

    cout << "=== NHAP PHAN SO THU HAI ===" << endl;
    cin >> b;

    a.rutGon();
    b.rutGon();

    cout << "\nPhan so thu nhat: " << a;
    cout << "\nPhan so thu hai: " << b;

    cout << "\n\n=== KET QUA ===" << endl;

    cout << "\nCong: " << a + b;
    cout << "\nTru: " << a - b;
    cout << "\nNhan: " << a * b;
    cout << "\nChia: " << a / b;

    return 0;
}
