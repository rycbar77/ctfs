#include <iostream>
#include <vector>

using namespace std;
int res[] = {48885, 35772, 41193, 29456, 55568, 41901, 52406, 19934, 13388, 15318, 26385, 34447, 7290, 33829, 27405,
             6988};
int s[] = {114688, 57344, 28672, 14336, 7168, 3584, 1792, 896, 448, 224, 112, 56, 28, 14, 7, 3};
int rr[] = {48885, 35772, 41193, 29456, 55568, 41901, 52406, 19934, 13388, 15318, 26385, 34447, 7290, 33829, 27405,
            6988};;

void cop() {
    int cnt = 0;
    for (auto &i:rr) {
        res[cnt] = i;
        cnt++;
    }
}

void opr(int x) {
    int x1 = x / 16;
    int x2 = x % 16;
    res[x1] ^= s[x2];
    if (x1 == 0)
        res[15] ^= (1 << (15 - x2)) & 0xffff;
    else
        res[x1 - 1] ^= (1 << (15 - x2)) & 0xffff;
    if (x1 < 0xf)
        res[x1 + 1] ^= (1 << (15 - x2)) & 0xffff;
}

void Combination(vector<int> &a, vector<int> &b, int l, int m, int M) {
    //b用于临时存储结果。len(b)==M；l为左侧游标，初始值取0；M是取出个数；m用于指示递归深度，初始值取M）
    int N = a.size();
    if (m == 0) {
        cop();
        for (auto i = b.rbegin(); i != b.rend(); i++) {
            opr(*i);
        }
        bool find = true;
        for (int re : res) {
            if (re != 0xffff) {
                find = false;
                break;
            }
        }
        if (find) {
            for (auto &i:b) {
                cout << i << ",";
            }
            cout << endl;
        }
        return;
    }
    for (int i = l; i < N; i++) {
        b[M - m] = a[i];
        Combination(a, b, i + 1, m - 1, M);
    }
}

int main() {
    int l = 0;
    int M = 107;
    int m = M;
    vector<int> a, b(107);
    for (int i = 0; i <= 0xff; i++)
        a.push_back(i);
    Combination(a, b, l, m, M);
    return 0;
}
