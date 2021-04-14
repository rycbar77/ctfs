### threads

首先通过字符串找到关键函数

```c++
int sub_4185B0()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  HANDLE v5; // [esp+D0h] [ebp-14h]
  HANDLE hObject; // [esp+DCh] [ebp-8h]

  sub_41142E(&unk_429032);
  v0 = sub_411352(std::cout, "Hello there, welcome to npuctf2020!");
  std::basic_ostream<char,std::char_traits<char>>::operator<<(v0, sub_411492);
  sub_411442();
  sub_41167C();
  v1 = sub_411352(std::cout, "input your flag:");
  std::basic_ostream<char,std::char_traits<char>>::operator<<(v1, sub_411492);
  sub_411442();
  sub_4110E6(std::cin, &unk_4265D0);
  if ( sub_411113(&unk_4265D0) != 45 )
  {
    v2 = sub_411352(std::cout, "Failed!");
    std::basic_ostream<char,std::char_traits<char>>::operator<<(v2, sub_411492);
    sub_411442();
    exit(0);
  }
  CreateThread(0, 0, StartAddress, 0, 0, 0);
  hObject = (HANDLE)sub_411442();
  CreateThread(0, 0, sub_4111E5, 0, 0, 0);
  v5 = (HANDLE)sub_411442();
  while ( dword_426000 )
    ;
  CloseHandle(::hObject);
  sub_411442();
  CloseHandle(hObject);
  sub_411442();
  CloseHandle(v5);
  sub_411442();
  if ( (unsigned __int8)sub_4116B3(&dword_426508, &unk_426008, 45) )
    v3 = sub_411352(std::cout, "Congratulations?");
  else
    v3 = sub_411352(std::cout, "Failed?");
  std::basic_ostream<char,std::char_traits<char>>::operator<<(v3, sub_411492);
  sub_411442();
  sub_41162C();
  return sub_411442();
}
```

可以看到创建了两个线程

```c++
CreateThread(0, 0, StartAddress, 0, 0, 0);
hObject = (HANDLE)sub_411442();
CreateThread(0, 0, sub_4111E5, 0, 0, 0);
v5 = (HANDLE)sub_411442();
```

分别看看这两个函数

```c++
void __stdcall sub_417860(int a1)
{
  sub_41142E(&unk_429032);
  while ( 1 )
  {
    WaitForSingleObject(hObject, 0xFFFFFFFF);
    sub_411442();
    if ( dword_426000 )
    {
      --dword_426000;
      sub_41106E();
      Sleep(0xAu);
      sub_411442();
    }
    ReleaseMutex(hObject);
    sub_411442();
  }
}

void __stdcall sub_417930(int a1)
{
  sub_41142E(&unk_429032);
  while ( 1 )
  {
    WaitForSingleObject(hObject, 0xFFFFFFFF);
    sub_411442();
    if ( dword_426000 )
    {
      --dword_426000;
      sub_411014();
      Sleep(0xAu);
      sub_411442();
    }
    ReleaseMutex(hObject);
    sub_411442();
  }
}
```

这个样子的题目应该有不少，利用互斥锁使这两个函数交替执行，从而使输入的奇偶位执行不同的操作，然后看看这两个操作

```c++
int sub_418E70()
{
  int v0; // ecx

  sub_41142E((int)&unk_429032);
  v0 = (dword_426000 + 2) * (dword_426000 + (dword_426000 ^ *(char *)sub_411488(&unk_4265D0, dword_426000)));
  dword_426508[dword_426000] = v0;
  return sub_411442(v0);
}

int sub_418F00()
{
  int v0; // ecx

  sub_41142E((int)&unk_429032);
  v0 = dword_426000 * dword_426000 * *(char *)sub_411488(&unk_4265D0, dword_426000);
  dword_426508[dword_426000] = v0;
  return sub_411442(v0);
}
```

`dword_426000`是索引值，这部分很好理解，处理完之后和已知的数据进行对比，所以很好解

**但是从这里开始解并没有什么意义**，因为你会解出来

```
npuctf{D0_you_r34l1y_th1nk_th1s_i5_7he_fl4g?}
```

看到内容就知道这是假flag

实际上后面还有操作，通过`addvectoredexception`来实现，下一步的处理在这里（需要恢复一下堆栈平衡才能`F5`）

```c++
int __stdcall sub_41D9D0(int a1)
{
  int v1; // ecx

  sub_41142E((int)&unk_429032);
  dword_426508[0] += 16;
  dword_426508[1] ^= 0x1Cu;
  dword_426508[2] = 888 - dword_426508[2];
  dword_426508[3] -= 36;
  dword_426508[4] ^= 0x1AAu;
  dword_426508[5] = 5450 - dword_426508[5];
  dword_426508[6] += 120;
  dword_426508[7] ^= 0x18D6u;
  dword_426508[8] = 1310 - dword_426508[8];
  dword_426508[9] += 3483;
  dword_426508[10] ^= 0x7Cu;
  dword_426508[11] = 19360 - dword_426508[11];
  dword_426508[12] += 532;
  dword_426508[13] ^= 0x1AF8u;
  dword_426508[14] = 4064 - dword_426508[14];
  dword_426508[15] -= 14175;
  dword_426508[16] ^= 0x3Eu;
  dword_426508[17] = 59245 - dword_426508[17];
  dword_426508[18] -= 1660;
  dword_426508[19] ^= 0xEC23u;
  dword_426508[20] = 4180 - dword_426508[20];
  dword_426508[21] += 28224;
  dword_426508[22] ^= 0xB0u;
  dword_426508[23] = 78821 - dword_426508[23];
  dword_426508[24] += 1222;
  dword_426508[25] ^= 0x1700Bu;
  dword_426508[26] = 5768 - dword_426508[26];
  dword_426508[27] += 3645;
  dword_426508[28] ^= 0x1F10u;
  dword_426508[29] = 137924 - dword_426508[29];
  dword_426508[30] += 1408;
  dword_426508[31] ^= 0x1FBAu;
  dword_426508[32] = 8738 - dword_426508[32];
  dword_426508[33] -= 50094;
  dword_426508[34] ^= 0x1170u;
  dword_426508[35] = 204575 - dword_426508[35];
  dword_426508[36] += 2166;
  dword_426508[37] ^= 0x2D9Cu;
  dword_426508[38] = 8760 - dword_426508[38];
  dword_426508[39] -= 12168;
  dword_426508[40] ^= 0x1BEEu;
  dword_426508[41] = 142885 - dword_426508[41];
  dword_426508[42] += 2464;
  dword_426508[43] ^= 0x1295Eu;
  dword_426508[44] = 11500 - dword_426508[44];
  if ( !(unsigned __int8)sub_4116B3((int)dword_426508, (int)&unk_426008, 45) )
    exit(0);
  return sub_411442(v1);
}
```

也同样很好逆，没什么好解释的

```python
dword_426508 = [0x000000DC, 0x00000070, 0x000001E4, 0x0000037B, 0x000002B8, 0x000009F6, 0x00000418, 0x00000D04,
                0x00000280,
                0x00001E0F, 0x000005DC, 0x00003477, 0x00000746, 0x00003EB7, 0x000008A0, 0x00002CD3, 0x000003A8,
                0x000079EC,
                0x00000424, 0x0000AAA1, 0x0000082A, 0x0000C7D4, 0x00000DE0, 0x00006541, 0x00000E6C, 0x0001053B,
                0x00000A64,
                0x00014A54, 0x000010E0, 0x0000A0F9, 0x00001160, 0x0001649F, 0x00000DF2, 0x0000E175, 0x0000165C,
                0x0001072F,
                0x000010A0, 0x00021C1D, 0x000018D8, 0x00025E06, 0x000011B8, 0x00015574, 0x00001474, 0x0001C707,
                0x00001676]
dword_426508[0] -= 16
dword_426508[1] ^= 0x1C
dword_426508[2] = 888 - dword_426508[2]
dword_426508[3] += 36
dword_426508[4] ^= 0x1AA
dword_426508[5] = 5450 - dword_426508[5]
dword_426508[6] -= 120
dword_426508[7] ^= 0x18D6
dword_426508[8] = 1310 - dword_426508[8]
dword_426508[9] -= 3483
dword_426508[10] ^= 0x7C
dword_426508[11] = 19360 - dword_426508[11]
dword_426508[12] -= 532
dword_426508[13] ^= 0x1AF8
dword_426508[14] = 4064 - dword_426508[14]
dword_426508[15] += 14175
dword_426508[16] ^= 0x3E
dword_426508[17] = 59245 - dword_426508[17]
dword_426508[18] += 1660
dword_426508[19] ^= 0xEC23
dword_426508[20] = 4180 - dword_426508[20]
dword_426508[21] -= 28224
dword_426508[22] ^= 0xB0
dword_426508[23] = 78821 - dword_426508[23]
dword_426508[24] -= 1222
dword_426508[25] ^= 0x1700B
dword_426508[26] = 5768 - dword_426508[26]
dword_426508[27] -= 3645
dword_426508[28] ^= 0x1F10
dword_426508[29] = 137924 - dword_426508[29]
dword_426508[30] -= 1408
dword_426508[31] ^= 0x1FBA
dword_426508[32] = 8738 - dword_426508[32]
dword_426508[33] += 50094
dword_426508[34] ^= 0x1170
dword_426508[35] = 204575 - dword_426508[35]
dword_426508[36] -= 2166
dword_426508[37] ^= 0x2D9C
dword_426508[38] = 8760 - dword_426508[38]
dword_426508[39] += 12168
dword_426508[40] ^= 0x1BEE
dword_426508[41] = 142885 - dword_426508[41]
dword_426508[42] -= 2464
dword_426508[43] ^= 0x1295E
dword_426508[44] = 11500 - dword_426508[44]
flag = ""
for i, j in enumerate(dword_426508):
    if i % 2 == 0:
        flag += chr((j // (i + 2) - i) ^ i)
    else:
        flag += chr(j // (i ** 2))

print(flag)
```

直接就可以输出**真正的**flag

```
flag{thr34d1_7hr3ad2_4nd_0Oops_eXc3p7i0n?!?!}
```

