#include "ida.h"
#include <iostream>

using namespace std;

int main() {
    unsigned long long v4; // [rsp+18h] [rbp-48h]
    unsigned long long v5; // [rsp+20h] [rbp-40h]
    unsigned long a2[4] = {0x626a6433,0x626a6433,0x626a6433,0x626a6433};
    v5 = 0xD760262509C2F6D0;
    v4 = 0xAF9D869B6947017D;

    unsigned long long delta = 0x9E3779B9;
    unsigned long long sum = 0;
    for (int i = 0; i < 32; i++) {
        sum += delta;
    }
    for (int i = 0; i < 32; i++) {
        v5 -= (v4 + sum) ^ ((v4 * 16) + a2[2]) ^ ((v4 >> 5) + a2[3]);
        v4 -= (v5 + sum) ^ ((v5 * 16) + a2[0]) ^ ((v5 >> 5) + a2[1]);
        sum -= delta;
        sum&=0xffffffffffffffff;
    }
    cout << hex << v4 << endl;
    cout << hex << v5 << endl;
    return 0;
}