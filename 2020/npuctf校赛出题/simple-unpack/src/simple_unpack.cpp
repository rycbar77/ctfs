#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    printf("Hello, give me your flag:");
    string s="flag{upx_i5_n0t_5imple_7o_unp4ck}";
    string input;
    cin>>input;
    if(input==s)
    {
        printf("Congratulations!");
    } else
    {
        printf("Wrong!");
    }
    return 0;
}