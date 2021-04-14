#include <iostream>
#include <string>
#include<iomanip>
int main()
{
    std::string flag = "flag{d0_y0u_know_x86-64_a5m?}";

        int p = 0;
        for (int i = 0; i < flag.length(); i++)
        {
            if ((i & 1) == 1)
            {
                p = flag[i] ^ 66;
                std::cout << std::hex << std::setw(2) << std::setfill('0') << p;
            }
            else
            {
                p = flag[i];
                std::cout << std::hex << std::setw(2) << std::setfill('0') << p;
            }
        }

        return 0;
}
