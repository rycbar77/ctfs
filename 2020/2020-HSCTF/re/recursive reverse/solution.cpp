#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
static int num = 0;
int n[13] = {0};

int pickNum(int i) {

    for (int x = 0; x <= i; x++)
        num += x;

    if (num % 2 == 0)
        return num;
    else
        num = pickNum(num);

    return num;
}


int main() {
    string s = "I$N]=6YiVwC";
    for (int i = 0; i < 12; i++) {
        num = 1;
        n[i] = pickNum(i + 1);
    }
//    for (int i = 0; i < 12; i++) {
//        cout << n[i] << " ";
//    }
    reverse(s.begin(), s.end());
    int f[13] = {0};
    for (int i = 0; i < 12; i++) {
        int tmp = ((s[i] + 127 * 10000000 - n[i]) % 127);
        if (tmp < 0) {
            tmp += 127;
        }
        printf("%d", tmp);
    }

    return 0;
}