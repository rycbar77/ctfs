#include<iostream>
#include "ida.h"
using namespace std;

int main()
{
    signed int dword_40F040[33] =
            {
                    9,
                    10,
                    15,
                    23,
                    7,
                    24,
                    12,
                    6,
                    1,
                    16,
                    3,
                    17,
                    32,
                    29,
                    11,
                    30,
                    27,
                    22,
                    4,
                    13,
                    19,
                    20,
                    21,
                    2,
                    25,
                    5,
                    31,
                    8,
                    18,
                    26,
                    28,
                    14,
                    0
            };
    char target[33] =
            {
                    103,
                    121,
                    123,
                    127,
                    117,
                    43,
                    60,
                    82,
                    83,
                    121,
                    87,
                    94,
                    93,
                    66,
                    123,
                    45,
                    42,
                    102,
                    66,
                    126,
                    76,
                    87,
                    121,
                    65,
                    107,
                    126,
                    101,
                    60,
                    92,
                    69,
                    111,
                    98,
                    77
            };
    char tmp[33];
    char flag[33];
    for(int i=0;i<=32;i++)
    {
        tmp[i]=target[i]^LOBYTE(dword_40F040[i]);
        flag[dword_40F040[i]]=tmp[i];
    }
    cout<<flag<<endl;
    return 0;
}