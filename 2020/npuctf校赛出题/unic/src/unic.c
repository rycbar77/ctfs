#include <unicorn/unicorn.h>
#include <memory.h>
#include <ctype.h>

#define ADDRESS 0x1000000
unsigned char r_ecx[149] = {0};
unsigned char r_edx[38] = {0};
unsigned char r_flag[50] = {0};
unsigned char r_result[50] = {0};
int compare(unsigned char a[], unsigned char b[], int len)
{
  for (int i = 0; i < len; i++)
  {
    if (a[i] != b[i])
    {
      return false;
    }
    else
    {
      continue;
    }
  }
  return true;
}
void init()
{
  r_ecx[0] = 233;
  r_ecx[1] = 155;
  r_ecx[2] = 168;
  r_ecx[3] = 9;
  r_ecx[4] = 182;
  r_ecx[5] = 159;
  r_ecx[6] = 91;
  r_ecx[7] = 143;
  r_ecx[8] = 89;
  r_ecx[9] = 90;
  r_ecx[10] = 39;
  r_ecx[11] = 137;
  r_ecx[12] = 30;
  r_ecx[13] = 35;
  r_ecx[14] = 239;
  r_ecx[15] = 92;
  r_ecx[16] = 139;
  r_ecx[17] = 34;
  r_ecx[18] = 23;
  r_ecx[19] = 237;
  r_ecx[20] = 40;
  r_ecx[21] = 220;
  r_ecx[22] = 79;
  r_ecx[23] = 3;
  r_ecx[24] = 163;
  r_ecx[25] = 87;
  r_ecx[26] = 56;
  r_ecx[27] = 158;
  r_ecx[28] = 168;
  r_ecx[29] = 89;
  r_ecx[30] = 143;
  r_ecx[31] = 80;
  r_ecx[32] = 91;
  r_ecx[33] = 95;
  r_ecx[34] = 106;
  r_ecx[35] = 14;
  r_ecx[36] = 27;
  r_ecx[37] = 181;
  r_ecx[38] = 97;
  r_ecx[39] = 2;
  r_ecx[40] = 112;
  r_ecx[41] = 200;
  r_ecx[42] = 183;
  r_ecx[43] = 85;
  r_ecx[44] = 174;
  r_ecx[45] = 138;
  r_ecx[46] = 46;
  r_ecx[47] = 182;
  r_ecx[48] = 60;
  r_ecx[49] = 17;
  r_ecx[50] = 250;
  r_ecx[51] = 116;
  r_ecx[52] = 129;
  r_ecx[53] = 25;
  r_ecx[54] = 223;
  r_ecx[55] = 104;
  r_ecx[56] = 4;
  r_ecx[57] = 101;
  r_ecx[58] = 58;
  r_ecx[59] = 115;
  r_ecx[60] = 118;
  r_ecx[61] = 193;
  r_ecx[62] = 156;
  r_ecx[63] = 125;
  r_ecx[64] = 35;
  r_ecx[65] = 70;
  r_ecx[66] = 100;
  r_ecx[67] = 69;
  r_ecx[68] = 226;
  r_ecx[69] = 248;
  r_ecx[70] = 49;
  r_ecx[71] = 254;
  r_ecx[72] = 111;
  r_ecx[73] = 248;
  r_ecx[74] = 186;
  r_ecx[75] = 219;
  r_ecx[76] = 249;
  r_ecx[77] = 95;
  r_ecx[78] = 151;
  r_ecx[79] = 24;
  r_ecx[80] = 232;
  r_ecx[81] = 131;
  r_ecx[82] = 106;
  r_ecx[83] = 195;
  r_ecx[84] = 120;
  r_ecx[85] = 188;
  r_ecx[86] = 113;
  r_ecx[87] = 156;
  r_ecx[88] = 52;
  r_ecx[89] = 5;
  r_ecx[90] = 64;
  r_ecx[91] = 215;
  r_ecx[92] = 130;
  r_ecx[93] = 66;
  r_ecx[94] = 105;
  r_ecx[95] = 239;
  r_ecx[96] = 65;
  r_ecx[97] = 190;
  r_ecx[98] = 18;
  r_ecx[99] = 166;
  r_ecx[100] = 91;
  r_ecx[101] = 134;
  r_ecx[102] = 10;
  r_ecx[103] = 16;
  r_ecx[104] = 175;
  r_ecx[105] = 150;
  r_ecx[106] = 63;
  r_ecx[107] = 108;
  r_ecx[108] = 133;
  r_ecx[109] = 229;
  r_ecx[110] = 18;
  r_ecx[111] = 242;
  r_ecx[112] = 45;
  r_ecx[113] = 83;
  r_ecx[114] = 141;
  r_ecx[115] = 69;
  r_ecx[116] = 222;
  r_ecx[117] = 234;
  r_ecx[118] = 70;
  r_ecx[119] = 249;
  r_ecx[120] = 188;
  r_ecx[121] = 221;
  r_ecx[122] = 208;
  r_ecx[123] = 207;
  r_ecx[124] = 214;
  r_ecx[125] = 77;
  r_ecx[126] = 255;
  r_ecx[127] = 214;
  r_ecx[128] = 133;
  r_ecx[129] = 228;
  r_ecx[130] = 95;
  r_ecx[131] = 12;
  r_ecx[132] = 135;
  r_ecx[133] = 78;
  r_ecx[134] = 63;
  r_ecx[135] = 97;
  r_ecx[136] = 138;
  r_ecx[137] = 244;
  r_ecx[138] = 193;
  r_ecx[139] = 140;
  r_ecx[140] = 53;
  r_ecx[141] = 37;
  r_ecx[142] = 146;
  r_ecx[143] = 3;
  r_ecx[144] = 33;
  r_ecx[145] = 139;
  r_ecx[146] = 197;
  r_ecx[147] = 164;
  r_edx[0] = 143;
  r_edx[1] = 218;
  r_edx[2] = 56;
  r_edx[3] = 121;
  r_edx[4] = 240;
  r_edx[5] = 93;
  r_edx[6] = 205;
  r_edx[7] = 153;
  r_edx[8] = 56;
  r_edx[9] = 43;
  r_edx[10] = 2;
  r_edx[11] = 224;
  r_edx[12] = 99;
  r_edx[13] = 200;
  r_edx[14] = 49;
  r_edx[15] = 41;
  r_edx[16] = 83;
  r_edx[17] = 210;
  r_edx[18] = 24;
  r_edx[19] = 156;
  r_edx[20] = 154;
  r_edx[21] = 79;
  r_edx[22] = 65;
  r_edx[23] = 238;
  r_edx[24] = 30;
  r_edx[25] = 27;
  r_edx[26] = 193;
  r_edx[27] = 225;
  r_edx[28] = 114;
  r_edx[29] = 139;
  r_edx[30] = 207;
  r_edx[31] = 179;
  r_edx[32] = 178;
  r_edx[33] = 242;
  r_edx[34] = 187;
  r_edx[35] = 20;
  r_edx[36] = 92;
}
typedef struct
{
  unsigned int count[2];
  unsigned int state[4];
  unsigned char buffer[64];
} MD5_CTX;

#define F(x, y, z) ((x & y) | (~x & z))
#define G(x, y, z) ((x & z) | (y & ~z))
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))
#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n)))
#define FF(a, b, c, d, x, s, ac) \
  {                              \
    a += F(b, c, d) + x + ac;    \
    a = ROTATE_LEFT(a, s);       \
    a += b;                      \
  }
#define GG(a, b, c, d, x, s, ac) \
  {                              \
    a += G(b, c, d) + x + ac;    \
    a = ROTATE_LEFT(a, s);       \
    a += b;                      \
  }
#define HH(a, b, c, d, x, s, ac) \
  {                              \
    a += H(b, c, d) + x + ac;    \
    a = ROTATE_LEFT(a, s);       \
    a += b;                      \
  }
#define II(a, b, c, d, x, s, ac) \
  {                              \
    a += I(b, c, d) + x + ac;    \
    a = ROTATE_LEFT(a, s);       \
    a += b;                      \
  }
unsigned char PADDING[] = {0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void MD5Init(MD5_CTX *context)
{
  context->count[0] = 0;
  context->count[1] = 0;
  context->state[0] = 0x67452301;
  context->state[1] = 0xEFCDAB89;
  context->state[2] = 0x98BADCFE;
  context->state[3] = 0x10325476;
}
void MD5Update(MD5_CTX *context, unsigned char *input, unsigned int inputlen)
{
  unsigned int i = 0, index = 0, partlen = 0;
  index = (context->count[0] >> 3) & 0x3F;
  partlen = 64 - index;
  context->count[0] += inputlen << 3;
  if (context->count[0] < (inputlen << 3))
    context->count[1]++;
  context->count[1] += inputlen >> 29;

  if (inputlen >= partlen)
  {
    memcpy(&context->buffer[index], input, partlen);
    MD5Transform(context->state, context->buffer);
    for (i = partlen; i + 64 <= inputlen; i += 64)
      MD5Transform(context->state, &input[i]);
    index = 0;
  }
  else
  {
    i = 0;
  }
  memcpy(&context->buffer[index], &input[i], inputlen - i);
}
void MD5Final(MD5_CTX *context, unsigned char digest[16])
{
  unsigned int index = 0, padlen = 0;
  unsigned char bits[8];
  index = (context->count[0] >> 3) & 0x3F;
  padlen = (index < 56) ? (56 - index) : (120 - index);
  MD5Encode(bits, context->count, 8);
  MD5Update(context, PADDING, padlen);
  MD5Update(context, bits, 8);
  MD5Encode(digest, context->state, 16);
}
void MD5Encode(unsigned char *output, unsigned int *input, unsigned int len)
{
  unsigned int i = 0, j = 0;
  while (j < len)
  {
    output[j] = input[i] & 0xFF;
    output[j + 1] = (input[i] >> 8) & 0xFF;
    output[j + 2] = (input[i] >> 16) & 0xFF;
    output[j + 3] = (input[i] >> 24) & 0xFF;
    i++;
    j += 4;
  }
}
void MD5Decode(unsigned int *output, unsigned char *input, unsigned int len)
{
  unsigned int i = 0, j = 0;
  while (j < len)
  {
    output[i] = (input[j]) |
                (input[j + 1] << 8) |
                (input[j + 2] << 16) |
                (input[j + 3] << 24);
    i++;
    j += 4;
  }
}
void MD5Transform(unsigned int state[4], unsigned char block[64])
{
  unsigned int a = state[0];
  unsigned int b = state[1];
  unsigned int c = state[2];
  unsigned int d = state[3];
  unsigned int x[64];
  MD5Decode(x, block, 64);
  FF(a, b, c, d, x[0], 7, 0xd76aa478);   /* 1 */
  FF(d, a, b, c, x[1], 12, 0xe8c7b756);  /* 2 */
  FF(c, d, a, b, x[2], 17, 0x242070db);  /* 3 */
  FF(b, c, d, a, x[3], 22, 0xc1bdceee);  /* 4 */
  FF(a, b, c, d, x[4], 7, 0xf57c0faf);   /* 5 */
  FF(d, a, b, c, x[5], 12, 0x4787c62a);  /* 6 */
  FF(c, d, a, b, x[6], 17, 0xa8304613);  /* 7 */
  FF(b, c, d, a, x[7], 22, 0xfd469501);  /* 8 */
  FF(a, b, c, d, x[8], 7, 0x698098d8);   /* 9 */
  FF(d, a, b, c, x[9], 12, 0x8b44f7af);  /* 10 */
  FF(c, d, a, b, x[10], 17, 0xffff5bb1); /* 11 */
  FF(b, c, d, a, x[11], 22, 0x895cd7be); /* 12 */
  FF(a, b, c, d, x[12], 7, 0x6b901122);  /* 13 */
  FF(d, a, b, c, x[13], 12, 0xfd987193); /* 14 */
  FF(c, d, a, b, x[14], 17, 0xa679438e); /* 15 */
  FF(b, c, d, a, x[15], 22, 0x49b40821); /* 16 */

  /* Round 2 */
  GG(a, b, c, d, x[1], 5, 0xf61e2562);   /* 17 */
  GG(d, a, b, c, x[6], 9, 0xc040b340);   /* 18 */
  GG(c, d, a, b, x[11], 14, 0x265e5a51); /* 19 */
  GG(b, c, d, a, x[0], 20, 0xe9b6c7aa);  /* 20 */
  GG(a, b, c, d, x[5], 5, 0xd62f105d);   /* 21 */
  GG(d, a, b, c, x[10], 9, 0x2441453);   /* 22 */
  GG(c, d, a, b, x[15], 14, 0xd8a1e681); /* 23 */
  GG(b, c, d, a, x[4], 20, 0xe7d3fbc8);  /* 24 */
  GG(a, b, c, d, x[9], 5, 0x21e1cde6);   /* 25 */
  GG(d, a, b, c, x[14], 9, 0xc33707d6);  /* 26 */
  GG(c, d, a, b, x[3], 14, 0xf4d50d87);  /* 27 */
  GG(b, c, d, a, x[8], 20, 0x455a14ed);  /* 28 */
  GG(a, b, c, d, x[13], 5, 0xa9e3e905);  /* 29 */
  GG(d, a, b, c, x[2], 9, 0xfcefa3f8);   /* 30 */
  GG(c, d, a, b, x[7], 14, 0x676f02d9);  /* 31 */
  GG(b, c, d, a, x[12], 20, 0x8d2a4c8a); /* 32 */

  /* Round 3 */
  HH(a, b, c, d, x[5], 4, 0xfffa3942);   /* 33 */
  HH(d, a, b, c, x[8], 11, 0x8771f681);  /* 34 */
  HH(c, d, a, b, x[11], 16, 0x6d9d6122); /* 35 */
  HH(b, c, d, a, x[14], 23, 0xfde5380c); /* 36 */
  HH(a, b, c, d, x[1], 4, 0xa4beea44);   /* 37 */
  HH(d, a, b, c, x[4], 11, 0x4bdecfa9);  /* 38 */
  HH(c, d, a, b, x[7], 16, 0xf6bb4b60);  /* 39 */
  HH(b, c, d, a, x[10], 23, 0xbebfbc70); /* 40 */
  HH(a, b, c, d, x[13], 4, 0x289b7ec6);  /* 41 */
  HH(d, a, b, c, x[0], 11, 0xeaa127fa);  /* 42 */
  HH(c, d, a, b, x[3], 16, 0xd4ef3085);  /* 43 */
  HH(b, c, d, a, x[6], 23, 0x4881d05);   /* 44 */
  HH(a, b, c, d, x[9], 4, 0xd9d4d039);   /* 45 */
  HH(d, a, b, c, x[12], 11, 0xe6db99e5); /* 46 */
  HH(c, d, a, b, x[15], 16, 0x1fa27cf8); /* 47 */
  HH(b, c, d, a, x[2], 23, 0xc4ac5665);  /* 48 */

  /* Round 4 */
  II(a, b, c, d, x[0], 6, 0xf4292244);   /* 49 */
  II(d, a, b, c, x[7], 10, 0x432aff97);  /* 50 */
  II(c, d, a, b, x[14], 15, 0xab9423a7); /* 51 */
  II(b, c, d, a, x[5], 21, 0xfc93a039);  /* 52 */
  II(a, b, c, d, x[12], 6, 0x655b59c3);  /* 53 */
  II(d, a, b, c, x[3], 10, 0x8f0ccc92);  /* 54 */
  II(c, d, a, b, x[10], 15, 0xffeff47d); /* 55 */
  II(b, c, d, a, x[1], 21, 0x85845dd1);  /* 56 */
  II(a, b, c, d, x[8], 6, 0x6fa87e4f);   /* 57 */
  II(d, a, b, c, x[15], 10, 0xfe2ce6e0); /* 58 */
  II(c, d, a, b, x[6], 15, 0xa3014314);  /* 59 */
  II(b, c, d, a, x[13], 21, 0x4e0811a1); /* 60 */
  II(a, b, c, d, x[4], 6, 0xf7537e82);   /* 61 */
  II(d, a, b, c, x[11], 10, 0xbd3af235); /* 62 */
  II(c, d, a, b, x[2], 15, 0x2ad7d2bb);  /* 63 */
  II(b, c, d, a, x[9], 21, 0xeb86d391);  /* 64 */
  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;
}

void md5(char *encrypt, char *en)
{
  MD5_CTX md5;
  MD5Init(&md5);
  MD5Update(&md5, encrypt, strlen((char *)encrypt));
  MD5Final(&md5, en);
}

int main(int argc, char **argv, char **envp)
{
  puts("I don't think you can solve this one.");
  puts("You can?");
  puts("Prove it to me!");
  puts("First input yout password!");
  unsigned char encrypt[5] = {0};
  read(0, encrypt, 4);
  while (1)
  {
    char tmp = getchar();
    if (tmp == '\n')
    {
      break;
    }
    else
    {
      continue;
    }
  }
  for (int i = 0; i < 4; i++)
  {
    if (encrypt[i] > 'A' && encrypt[i] < 'Z')
    {
      encrypt[i] = tolower(encrypt[i]);
    }
  }
  unsigned char en[16] = {0};
  unsigned char valid[] = {0x75, 0xE7, 0xD8, 0x30, 0xA3, 0x5C, 0xBD, 0x77, 0x26, 0x13, 0xCF, 0x90, 0x49, 0x87, 0x8D, 0x7A};
  md5(encrypt, en);
  if (!strncmp(en, valid, 16))
  {
    puts("Ok,you are qualified for this question.");
    puts("Now input your flag:");
    int i = 0;
    while (1)
    {
      char tmp = getchar();
      if (tmp == '\n')
      {
        break;
      }
      else
      {
        r_flag[i] = tmp;
        i++;
        continue;
      }
    }
    int opcode[4] = {0};
    for (int i = 0; i < 4; i++)
    {
      unsigned char tmp = encrypt[i];
      int tmp2 = 0;
      if (tmp >= '0' && tmp <= '9')
      {
        tmp2 = tmp - '0';
      }
      else
      {
        tmp2 = tmp - 'a' + 10;
      }
      opcode[i] = tmp2;
    }
    unsigned char op1 = (opcode[0] << 4) + opcode[1];
    unsigned char op2 = (opcode[2] << 4) + opcode[3];
    unsigned char op[3] = {op1, op2, '\0'};
    init();
    uc_engine *uc;

    uc_open(UC_ARCH_X86, UC_MODE_32, &uc);

    uc_mem_map(uc, ADDRESS, 2 * 1024 * 1024, UC_PROT_ALL);

    uc_mem_write(uc, ADDRESS, op, sizeof(op) - 1);
    for (int i = 0; i < sizeof(r_edx) / sizeof(r_edx[0]); i++)
    {
      uc_reg_write(uc, UC_X86_REG_ECX, &r_ecx[4 * i]);
      uc_reg_write(uc, UC_X86_REG_EDX, &r_flag[i]);

      uc_emu_start(uc, ADDRESS, ADDRESS + sizeof(op) - 1, 0, 0);

      uc_reg_read(uc, UC_X86_REG_ECX, &r_result[i]);
    }

    uc_close(uc);
    if (compare(r_edx, r_result, 37))
    {
      puts("Congratulations!");
    }
    else
    {
      puts("You failed!");
    }
  }
  else
  {
    puts("Go and learn!");
  }

  return 0;
}