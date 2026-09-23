#include <iostream>
using namespace std;

class PS1
{
protected:
    int tu, mau;

public:
    // Nhap phan so
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

    // Toi gian phan so
    void toiGian()
    {
        int a = tu;
        int b = mau;

        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        tu = tu / a;
        mau = mau / a;

        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
    }

    // In phan so
    void in()
    {
        toiGian();

        if (mau == 1)
            cout << tu;
        else
            cout << tu << "/" << mau;
    }
};

class PS2 : public PS1
{
public:
    // Nap chong toan tu =
    PS2& operator=(const PS2& p)
    {
        tu = p.tu;
        mau = p.mau;
        return *this;
    }

    // Nap chong toan tu >
    bool operator>(const PS2& p)
    {
        return tu * p.mau > p.tu * mau;
    }
};

int main()
{
    PS2 a[10];
    int n;

    cout << "Nhap so luong phan so: ";
    cin >> n;

    if (n > 10)
        n = 10;

    // Nhap danh sach
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan so thu " << i + 1 << ":\n";
        a[i].nhap();
        a[i].toiGian();
    }

    // Sap xep giam dan
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                PS2 tg;
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }

    // In ket qua
    cout << "\nDanh sach phan so giam dan:\n";
    for (int i = 0; i < n; i++)
    {
        a[i].in();
        cout << "  ";
    }

    return 0;
}
