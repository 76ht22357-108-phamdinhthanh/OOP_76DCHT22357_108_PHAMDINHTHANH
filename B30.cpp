#include <iostream>
#include <cmath>
using namespace std;

class SP1
{
protected:
    float thuc, ao;

public:
    // Ham tao khong doi
    SP1()
    {
        thuc = 0;
        ao = 0;
    }

    // Ham tao co doi
    SP1(float t, float a)
    {
        thuc = t;
        ao = a;
    }

    // Nhap so phuc
    void nhap()
    {
        cout << "Nhap phan thuc: ";
        cin >> thuc;

        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    // In so phuc
    void in()
    {
        cout << thuc;

        if (ao >= 0)
            cout << " + " << ao << "i";
        else
            cout << " - " << -ao << "i";
    }

    // Tinh module
    float module()
    {
        return sqrt(thuc * thuc + ao * ao);
    }
};

class SP2 : public SP1
{
public:
    // Nap chong toan tu =
    SP2& operator=(const SP2& p)
    {
        thuc = p.thuc;
        ao = p.ao;
        return *this;
    }

    // Nap chong toan tu >
    // So sanh theo module
    bool operator>(const SP2& p)
    {
        return module() > p.module();
    }
};

int main()
{
    SP2 a[10];
    int n;

    cout << "Nhap so luong so phuc: ";
    cin >> n;

    if (n > 10)
        n = 10;

    // Nhap danh sach
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap so phuc thu " << i + 1 << ":\n";
        a[i].nhap();
    }

    // Sap xep giam dan theo module
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                SP2 tg;
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }

    // In ket qua
    cout << "\nDanh sach so phuc giam dan theo module:\n";

    for (int i = 0; i < n; i++)
    {
        a[i].in();
        cout << "   | Module = " << a[i].module() << endl;
    }

    return 0;
}
