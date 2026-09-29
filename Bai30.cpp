#include <iostream>
#include <cmath>
using namespace std;

// CÂU 1
class SP1
{
protected:
    float thuc;
    float ao;

public:
    SP1()
    {
        thuc = 0;
        ao = 0;
    }

    SP1(float t, float a)
    {
        thuc = t;
        ao = a;
    }

    void nhap()
    {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    void xuat()
    {
        cout << thuc;
        if (ao >= 0)
            cout << " + " << ao << "i";
        else
            cout << " - " << -ao << "i";
    }

    float module()
    {
        return sqrt(thuc * thuc + ao * ao);
    }
};

// CÂU 2
class SP2 : public SP1
{
public:
    SP2& operator=(const SP2& sp)
    {
        thuc = sp.thuc;
        ao = sp.ao;
        return *this;
    }

    bool operator>(const SP2& sp)
    {
        return module() > sp.module();
    }
};

// CÂU 3
int main()
{
    SP2 a[10];
    int n;

    cout << "Nhap so luong so phuc: ";
    cin >> n;

    if (n > 10)
        n = 10;

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap so phuc thu " << i + 1 << ":\n";
        a[i].nhap();
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                SP2 tam;
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

    cout << "\nDanh sach sau khi sap xep:\n";

    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
        cout << "   Module = " << a[i].module() << endl;
    }

    return 0;
}
