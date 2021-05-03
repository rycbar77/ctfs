#include <cstdio>
#include <cstdint>

void encipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {
    unsigned int i;
    uint32_t v0=v[0], v1=v[1], sum=0, delta=0x12345678;
    for (i=0; i < num_rounds; i++) {
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
        sum += delta;
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);
    }
    v[0]=v0; v[1]=v1;
}

void decipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {
    unsigned int i;
    uint32_t v0=v[0], v1=v[1], delta=0x12345678, sum=delta*num_rounds;
    for (i=0; i < num_rounds; i++) {
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);
        sum -= delta;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
    }
    v[0]=v0; v[1]=v1;
}


int main() {
//    0x0EC311F0 ,0x45C79AF3,0xEDF5D910,0x542702CB
    uint32_t v[2] = {0x0EC311F0 ,0x45C79AF3};
    uint32_t const k[4] = {0x00010203, 0x04050607, 0x08090A0B, 0x0C0D0E0F};
    unsigned int r=32;
//    printf("加密前原始数据：%x %x\n", v[0], v[1]);
//    encipher(r, v, k);
//    printf("加密后的数据：%x %x\n",v[0],v[1]);
    decipher(r, v, k);
    uint32_t v2[2] = {0xEDF5D910,0x542702CB};
    printf("%x%x",v[0],v[1]);
    decipher(r, v2, k);
    printf("%x%x\n",v2[0],v2[1]);
    return 0;
}