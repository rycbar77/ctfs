#include <cmath>
#include <iostream>

double __fastcall sub_7FF60F391360(double a1, double a2) {
    double v2;
    double v3;

    v2 = a1;
    a1 = pow(a1, a2 - 1.0);
    v3 = a1 / exp(v2);
    return v3;
}

int c(__int64 v95) {
//    double v95 = 0;
    double v19 = (double) ((int) v95 / 12379) + 1.0;
    double v22 = (double) ((int) v95 % 12379) + 1.0;
    double v17 = 0;
    double v18 = 0;
    double v16 = 0;
    do {
        v17 = v17 + sub_7FF60F391360(v18, v19) * 0.001;
        v16 = v16 + sub_7FF60F391360(v18, v22) * 0.001;
        v18 = v18 + 0.001;
    } while (v18 <= 100.0);
    int v20 = (int) (v17 + v17 + 3.0);
    if (v20 == 0x13B03 && (int) (v16 + v16 + 3.0) == 0x5a2) {
        return 0;
    }
    return -1;
}

int main() {
//    std::cout << INT64_MAX << std::endl;
    for (__int64 i = 0; i < 10; i++)
        for (__int64 j = 0; j < 10; j++)
            if (c(i * 12379 + j) == 0) {
                std::cout << i << " " << j << " " << i * 12379 + j << std::endl;
            }

}