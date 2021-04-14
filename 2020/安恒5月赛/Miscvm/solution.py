opcode = [4, 1, 7, 9, 10, 9, 4, 1, 7, 9, 10, 9, 4, 1, 7, 9, 10, 9, 4, 1, 7, 9, 10, 9, 4, 1, 7, 9, 10, 9, 4,
          1, 7, 9, 10, 9, 4, 1, 7, 9, 10, 9, 4, 1, 7, 9, 10, 9]
v15 = [0x00000042, 0x0000004A, 0x00000044, 0x0000007B, 0x00000033, 0x00000370, 0x00000046, 0x000000D4, 0x0000003C,
       0x00000610, 0x0000004F, 0x000000C8, 0x0000006C, 0x00000320, 0x0000001E, 0x00000190, 0x0000006F, 0x00000630,
       0x00000046, 0x00000190, 0x0000003B, 0x00000610, 0x0000001D, 0x000000C4, 0x0000003E, 0x00000660, 0x0000004B,
       0x000000D0, 0x0000006C, 0x00000310, 0x00000046, 0x00000188, 0x00000033, 0x00000370, 0x0000004C, 0x000000CC,
       0x0000007D, 0x00000000]
v10 = 0
v9 = 4
v11 = 128
v12 = 37
v13 = 9999
while v10 < len(opcode):
    v3 = opcode[v10]
    if v3 == 1:
        v15[v9] //= 16
        v9 += 1
        v10 += 1
        continue
    if v3 == 2:
        v15[v9] -= 128
        v15[v9] //= v9
        v11 += 1
        v10 += 1
        continue
    if v3 == 3:
        v15[v9] //= 10
        v9 -= 1
        v10 += 1
        continue
    if v3 == 4:
        v15[v9] ^= 0xA
        v9 += 1
        v12 -= 1
        v10 += 1
        continue
    if v3 == 5:
        v10 += 1
        continue
    if v3 == 6:
        v9 += 1
        v15[v9] *= 10
        v10 += 1
        continue
    if v3 == 7:
        v15[v9] -= 128
        v15[v9] = ~v15[v9]
        v10 += 1
        continue
    if v3 == 8:
        v15[v9] += 1
        v15[v9] -= v13
        v9 += 1
        v10 += 1
        v13 = v13 % 1234 - 2019
        continue
    if v3 == 9:
        v9 += 1
        v10 += 1
        continue
    if v3 == 0xA:
        v10 += 1
        v15[v9] //= 4
        continue
    if v3 == 0xB:
        v10 += 1
        continue
    if v3 == 0xC:
        v9 += 1
        v10 += 1
        v15[v9] += 32
        v15[v9] ^= 0x22
    v10 += 1

# print(''.join([chr(i) for i in v15]))
indexs1 = [1, 2, 3, 4, 19, 31, 25, 14, 23, 33, 13, 9, 24, 6, 26, 34, 17, 10, 8, 29, 12, 15, 22, 11, 18, 16, 32, 28, 21,
           36, 20, 7, 5, 27, 30, 35, 37]
indexs2 = [1, 2, 3, 4, 31, 29, 7, 35, 14, 21, 9, 16, 27, 18, 25, 10, 20, 15, 17, 22, 28, 26, 36, 33, 32, 5, 8, 12, 23,
           34, 13, 30, 24, 11, 19, 6, 37]
for i in range(37):
    indexs1[i] -= 1
    indexs2[i] -= 1

tmp = [0 for i in range(37)]
flag = [0 for i in range(37)]
for i, c in enumerate(indexs2):
    tmp[c] = v15[i]
for i, c in enumerate(indexs1):
    flag[c] = tmp[i]
flag = ''.join([chr(i) for i in flag])
# print(flag)
flag = flag[:4] + flag[20:36] + flag[4:20] + flag[-1]
print(flag)
# BJD{7f099c11e53fd2bb1643429a74da9af9}
