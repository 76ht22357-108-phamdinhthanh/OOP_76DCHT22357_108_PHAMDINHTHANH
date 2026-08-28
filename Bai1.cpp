#include <iostream>
using namespace std;

// Câu 1: Khai báo lớp MaTran với các thuộc tính: số hàng, số cột, các phần tử của ma trận
class MaTran {
private:
    int h, c;
    int a[100][100]; // Mảng 2 chiều lưu các phần tử (không dùng con trỏ)

public:
    // Câu 2: Xây dựng các phương thức nhập, xuất một đối tượng ma trận
    void nhap() {
        cout << "Nhap so hang: ";
        cin >> h;
        cout << "Nhap so cot: ";
        cin >> c;
        cout << "Nhap cac phan tu cua ma tran:\n";
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < c; j++) {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> a[i][j];
            }
        }
    }

    void xuat() const {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < c; j++) {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Câu 3: Dùng hàm bạn thực hiện cộng hai ma trận
    friend MaTran congMaTran(MaTran m1, MaTran m2) {
        MaTran res;
        res.h = m1.h;
        res.c = m1.c;
        for (int i = 0; i < m1.h; i++) {
            for (int j = 0; j < m1.c; j++) {
                res.a[i][j] = m1.a[i][j] + m2.a[i][j];
            }
        }
        return res;
    }
};

// Câu 3: Nhập vào 2 ma trận đồng cấp, dùng hàm bạn để cộng và in kết quả
int main() {
    MaTran m1, m2;

    cout << "=== NHAP MA TRAN 1 ===\n";
    m1.nhap();

    cout << "\n=== NHAP MA TRAN 2 (DONG CAP VOI MA TRAN 1) ===\n";
    m2.nhap();

    // Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn)
    MaTran tong = congMaTran(m1, m2);

    // In ra màn hình hai ma trận ban đầu và ma trận kết quả
    cout << "\n====================================\n";
    cout << "Ma tran ban dau 1:\n";
    m1.xuat();

    cout << "\nMa tran ban dau 2:\n";
    m2.xuat();

    cout << "\nMa tran ket qua (Tong):\n";
    tong.xuat();

    return 0;
}
