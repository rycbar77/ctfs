### easyre

`main`函数很简单

```c++
__int64 __fastcall main(__int64 a1, char **a2, char **a3)
{
  void *v4; // [rsp+0h] [rbp-28h]
  unsigned __int64 v5; // [rsp+18h] [rbp-10h]

  v5 = __readfsqword(0x28u);
  sub_1340();
  sub_14B0((__int128 *)&v4);
  sub_1100((__int64)&v4);
  if ( (unsigned __int8)sub_11C0((_BYTE **)&v4) )
    std::__ostream_insert<char,std::char_traits<char>>(&std::cout, "Congratulations!", 16LL);
  else
    std::__ostream_insert<char,std::char_traits<char>>(&std::cout, "Wrong!", 6LL);
  std::endl<char,std::char_traits<char>>(&std::cout);
  if ( v4 )
    operator delete(v4);
  return 0LL;
}
```

可以看到使`if`判断为真就可以了

`sub_1340()`函数纯粹用来输出，可以不看，下面几个函数观察一下可以看的出来，`sub_14B0()`用来输入，`sub_1100()`用来对输入进行处理，`sub_11C0()`用来判断

> 每一个部分都很长，其实实现的功能很简单，是因为整型数组内存连续存放，所以被当作了很大的数据来处理了，看不明白的话建议动态调试

输入之后数据被存放到了`v4`里，然后进行处理

```c++
unsigned __int64 __fastcall sub_1100(__int64 a1)
{
  char *v1; // rax
  char v2; // cl
  unsigned __int64 v3; // rsi
  int v4; // edx
  __int64 v5; // rcx
  _QWORD *v7; // rax
  unsigned __int64 v8; // [rsp+8h] [rbp-10h]

  v8 = __readfsqword(0x28u);
  v1 = *(char **)a1;
  if ( *(_QWORD *)(a1 + 8) != *(_QWORD *)a1 )
  {
    v2 = *v1;
    if ( *v1 == 10 )
    {
LABEL_7:
      v7 = (_QWORD *)__cxa_allocate_exception(8LL);
      *v7 = &unk_202CD0;
      __cxa_throw(v7, &`typeinfo for'std::exception, &std::exception::~exception);
    }
    v3 = 0LL;
    LOBYTE(v4) = 35;
    while ( 1 )
    {
      *v1 = v4 ^ v2;
      v5 = (unsigned __int8)v4 + v3++;
      v4 = v5 + ((unsigned __int64)(0x8080808080808081LL * (unsigned __int128)(unsigned __int64)v5 >> 64) >> 7);
      if ( v3 >= *(_QWORD *)(a1 + 8) - *(_QWORD *)a1 )
        break;
      v1 = (char *)(v3 + *(_QWORD *)a1);
      v2 = *v1;
      if ( *v1 == 10 )
        goto LABEL_7;
    }
  }
  return __readfsqword(0x28u) ^ v8;
}
```

只是进行了简单的异或，只不过是一遍生成一边和输入异或，不过这些数据和输入无关，可以先算出来，至于`v4 = v5 + ((unsigned __int64)(0x8080808080808081LL * (unsigned __int128)(unsigned __int64)v5 >> 64) >> 7);`这一步的计算，其实仔细看看就会发现根本没有意义

接下来进行判断

```c++
__int64 __fastcall sub_11C0(_BYTE **a1)
{
  __m128i *v1; // rbx
  _BYTE *v2; // rcx
  __m128i v3; // xmm0
  __m128i v4; // xmm1
  signed __int64 v5; // rsi
  unsigned int v6; // ebp
  struct _Unwind_Exception *v8; // rbp

  v1 = (__m128i *)operator new(0xE8uLL);
  v2 = *a1;
  v1[1] = _mm_load_si128((const __m128i *)&byte_1A10);
  v3 = _mm_load_si128((const __m128i *)&byte_1A20);
  v1[14].m128i_i64[0] = -2051389526429375416LL;
  v1[2] = v3;
  v1[3] = _mm_load_si128((const __m128i *)&byte_1A30);
  v1[4] = _mm_load_si128((const __m128i *)&byte_1A40);
  v1[5] = _mm_load_si128((const __m128i *)&byte_1A50);
  v1[6] = _mm_load_si128((const __m128i *)&byte_1A60);
  v1[7] = _mm_load_si128((const __m128i *)&byte_1A70);
  v1[8] = _mm_load_si128((const __m128i *)&byte_1A80);
  v1[9] = _mm_load_si128((const __m128i *)&byte_1A90);
  v1[10] = _mm_load_si128((const __m128i *)&byte_1AA0);
  v1[11] = _mm_load_si128((const __m128i *)&byte_1AB0);
  v4 = _mm_load_si128((const __m128i *)&byte_1A00);
  v1[12] = _mm_load_si128((const __m128i *)&byte_1AC0);
  *v1 = v4;
  v1[13] = _mm_load_si128((const __m128i *)&byte_1AD0);
  if ( a1[1] == v2 )
  {
    v5 = 0LL;
LABEL_11:
    v8 = (struct _Unwind_Exception *)std::__throw_out_of_range_fmt(
                                       "vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                                       v5,
                                       v5);
    operator delete(v1);
    _Unwind_Resume(v8);
  }
  if ( (_BYTE)byte_1A00 == *v2 )
  {
    v5 = 1LL;
    do
    {
      if ( v5 == a1[1] - v2 )
        goto LABEL_11;
      if ( *((_BYTE *)v1->m128i_i64 + 4 * v5) != v2[v5] )
        goto LABEL_9;
      ++v5;
    }
    while ( v5 != 58 );
    v6 = 1;
  }
  else
  {
LABEL_9:
    v6 = 0;
  }
  operator delete(v1);
  return v6;
}
```

关键其实只有一个相等的判断，不过两个数组每次索引值增加的不一样，每四位进行一次比较就好了

```python
target = [0x45, 0xE6, 0xD0, 0x4A, 0x4F, 0xC3, 0x7E, 0xAA, 0x45, 0xFC, 0x42, 0xB2, 0x41, 0xB5, 0x01, 0xB4, 0x52, 0x7D,
          0x39, 0x20, 0x1A, 0xC0, 0x4E, 0x13, 0x5A, 0x2F, 0x67, 0xAA, 0x5D, 0x79, 0x6B, 0xF5, 0x4D, 0x06, 0x41, 0x79,
          0x22, 0x35, 0xF9, 0xC8, 0x0F, 0xDE, 0x88, 0x51, 0x33, 0x4C, 0xF0, 0x81, 0x50, 0xF4, 0xEE, 0x14, 0x2E, 0xF1,
          0x25, 0xBD, 0x10, 0x7C, 0x62, 0x30, 0xE3, 0xF8, 0x80, 0x2B, 0xC4, 0x85, 0x2A, 0xF8, 0xCF, 0x5A, 0xAE, 0xCB,
          0x8C, 0x3A, 0xA2, 0xD0, 0xBB, 0xC5, 0x8C, 0x5D, 0x83, 0x34, 0x6B, 0xF9, 0x81, 0x72, 0x4B, 0x0E, 0x54, 0xC3,
          0x71, 0x53, 0x55, 0xE9, 0x07, 0xBB, 0x50, 0x1A, 0xE7, 0x07, 0x64, 0x1B, 0x75, 0x74, 0x5E, 0x8E, 0x5D, 0x2E,
          0xDC, 0xF6, 0x17, 0x3B, 0xEC, 0xED, 0xD7, 0xBD, 0xDF, 0xE9, 0x76, 0x63, 0x88, 0xE2, 0xEA, 0x89, 0x85, 0xD7,
          0x4F, 0x34, 0x67, 0x39, 0xD5, 0x58, 0x05, 0xD9, 0xD2, 0xD2, 0x34, 0x69, 0xF1, 0xBF, 0x49, 0x76, 0xE1, 0x9C,
          0xFE, 0x0D, 0x0C, 0xB3, 0xD2, 0x06, 0x48, 0xDA, 0xD1, 0xD5, 0x1E, 0xB8, 0x54, 0x94, 0x4C, 0x98, 0x06, 0x8A,
          0x68, 0xA8, 0x28, 0x5E, 0x64, 0xF9, 0xE6, 0x58, 0xF7, 0x02, 0xF2, 0x8D, 0x3B, 0x88, 0xBD, 0x14, 0xEC, 0x8F,
          0x31, 0x70, 0x0C, 0x0B, 0x41, 0x66, 0x22, 0x8E, 0x19, 0x58, 0x01, 0x2E, 0xD0, 0xDC, 0x4B, 0xC0, 0x88, 0xF4,
          0xDA, 0xE6, 0x9F, 0x73, 0x88, 0x7D, 0x7C, 0x91, 0x1F, 0x75, 0x25, 0x70, 0xD6, 0x0C, 0xBA, 0x09, 0x7C, 0xF2,
          0xD3, 0x4E, 0xA1, 0x09, 0x83, 0x51, 0x3C, 0xBA, 0x48, 0x64, 0x38, 0x2D, 0x18, 0x00, 0x88, 0xE3]

v = [35]
for i in range(58):
    v.append((v[i] + i) % 0xff)
flag = ""
for i in range(58):
    flag += chr(target[i * 4] ^ v[i])
print(flag)

```

直接输出flag

```
flag{7here_i5_no_d0ubt_th47_re_pr0b1em5_4re_e4sy_7o_s0lve}
```

