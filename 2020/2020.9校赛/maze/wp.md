### maze

简单的花指令加迷宫题，好心的出题人在每个花指令的地方都`patch`了很多个`nop`，~~虽然这么做毫无意义~~

把简单的花指令`patch`掉

```c++
__int64 __fastcall main(__int64 a1, char **a2, char **a3)
{
  __int64 *v3; // rbx
  char v4; // al
  bool v5; // zf
  __int64 v6; // rax

  v3 = (__int64 *)malloc(0x188uLL);
  *v3 = 234545231LL;
  v3[1] = 344556530LL;
  qword_202020 = (__int64)v3;
  v3[7] = 1423431LL;
  v3[2] = 453523423550LL;
  v3[8] = 54535240LL;
  v3[3] = 46563455531LL;
  v3[9] = 234242550LL;
  v3[4] = 34524345344661LL;
  v3[12] = 123422421LL;
  v3[5] = 34533453453451LL;
  v3[13] = 2342420LL;
  v3[6] = 2343423124234420LL;
  v3[14] = 23414141LL;
  v3[10] = 23424242441LL;
  v3[15] = 23424420LL;
  v3[11] = 2345355345430LL;
  v3[16] = 13535231LL;
  v3[18] = 23423414240LL;
  v3[17] = 2341LL;
  v3[20] = 53366745350LL;
  v3[19] = 1234422441LL;
  v3[27] = 3453326640LL;
  v3[21] = 253244531LL;
  v3[28] = 245332535325535341LL;
  v3[22] = 45463320LL;
  v3[29] = 7568546234640LL;
  v3[23] = 24532661LL;
  v3[30] = 23445576731LL;
  v3[24] = 23433430LL;
  v3[25] = 23453660LL;
  v3[26] = 3453661LL;
  v3[31] = 234534460LL;
  v3[33] = 34455344551LL;
  v3[35] = 2354657721451LL;
  v3[32] = 234364561LL;
  v3[36] = 23464664430LL;
  v3[34] = 2345670LL;
  v3[39] = 23643643334561LL;
  v3[37] = 245646441LL;
  v3[40] = 2346463450LL;
  v3[38] = 234644640LL;
  v3[41] = 2343345620LL;
  v3[42] = 3444651LL;
  v3[43] = 23451LL;
  v3[44] = 67541LL;
  v3[45] = 34575860LL;
  v3[46] = 67856741LL;
  v3[47] = 567678671LL;
  v3[48] = 567565671LL;
  puts("Input your flag:");
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          do
            v4 = _IO_getc(stdin);
          while ( v4 == 10 );
          if ( v4 == 10 )
            JUMPOUT(*(_QWORD *)&byte_96B);
          if ( v4 != 104 )
            break;
          if ( ((signed __int64)v3 - qword_202020) >> 3 != 7
                                                         * (((signed __int64)((unsigned __int128)(5270498306774157605LL
                                                                                                * (signed __int128)(((signed __int64)v3 - qword_202020) >> 3)) >> 64) >> 1)
                                                          - (((signed __int64)v3 - qword_202020) >> 63)) )
          {
            --v3;
            v5 = v3 == 0LL;
            goto LABEL_13;
          }
        }
        if ( v4 != 106 )
          break;
        if ( (unsigned __int64)v3 - qword_202020 > 0x30 )
        {
          v3 -= 7;
          v5 = v3 == 0LL;
          goto LABEL_13;
        }
      }
      if ( v4 == 107 )
        break;
      if ( v4 == 108 && (((signed __int64)v3 - qword_202020) >> 3) % 7 != 6 )
      {
        v5 = v3 + 1 == 0LL;
        ++v3;
        goto LABEL_13;
      }
    }
    if ( (unsigned __int64)((char *)v3 - qword_202020 - 329) > 0x37 )
    {
      v5 = v3 + 7 == 0LL;
      v3 += 7;
LABEL_13:
      v6 = *v3;
      if ( v5 )
        JUMPOUT(*(_QWORD *)&byte_9F2);
      if ( v6 == 567565671 )
      {
        puts("Congratulations!");
        puts("The flag is: flag{ YOUR INPUT }");
        exit(0);
      }
      if ( v6 == 567565671 )
        JUMPOUT(*(_QWORD *)&byte_A01);
      if ( !(v6 & 1) )
        break;
    }
  }
  puts("You Failed!");
  return 0LL;
}
```

很显然这是一个7*7的迷宫，虽然数都很大很复杂，但是只比较奇偶，所以只要看最后一位就行了，就是一个很简单的迷宫

```
flag{kkkkkklljjjjljjllkkkkhkklll}
```



