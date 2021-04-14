#include "ida.h"
#include <iostream>

using namespace std;

int main() {
    unsigned __int64 data[8] = {0x08CD53D0EAE56FDE, 0xE0310C8244BA1FA3, 0x45B42002CE1B213D, 0x16FDC411224CB2DF,
                                0x2FD8108A59461BCC, 0x8F6990725EB01982, 0x9BA5ADE29A2A17D8, 0x4DEAA99F5D9F6605};
    for (int i = 0; i <= 63; ++i) {
        data[7] = ((data[7] ^ data[0]) >> 34) ^ ((data[7] ^ data[0]) << 30);
        data[6] = ((data[6] ^ data[7]) >> 40) ^ ((data[6] ^ data[7]) << 24);
        data[5] = ((data[5] ^ data[6]) >> 46) ^ ((data[5] ^ data[6]) << 18);
        data[4] = ((data[4] ^ data[5]) >> 52) ^ ((data[4] ^ data[5]) << 12);
        data[3] = ((data[3] ^ data[4]) >> 58) ^ ((data[3] ^ data[4]) << 6);
        data[2] = ((data[2] ^ data[3]) >> 16) ^ ((data[2] ^ data[3]) << 48);
        data[1] = ((data[1] ^ data[2]) >> 22) ^ ((data[1] ^ data[2]) << 42);
        data[0] = ((data[0] ^ data[1]) >> 28) ^ ((data[0] ^ data[1]) << 36);
    }
    for (const auto &datum : data) {
        cout << hex << datum << endl;
    }
    return 0;
// yourself or_fresh try_to_s love_it_ man_and_ easy_log orithm_f ical_alg

// BJD{easy_logical_algorithm_for_freshman_and_try_to_slove_it_yourself}
}