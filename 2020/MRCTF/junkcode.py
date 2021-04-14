target = '%BUEdVSHlmfWhpZn!oaWZ(aGBsZ@ZpZn!oaWZ(aGBsZ@ZpZn!oYGxnZm'#%w'
flag = ''
target1 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz)!@#$%^&*(+/'
i = 0
tmps = []
# print(chr(0x2e))
# print(len(target))
while i < len(target):
    index0 = target1.index(target[i])
    index1 = target1.index(target[i + 1])
    index2 = target1.index(target[i + 2])
    index3 = target1.index(target[i + 3])
    i += 4
    tmp1 = index0 * 4 + ((index1 & 0x30) >> 4)
    tmp2 = ((index1 & 0xf) << 4) + ((index2 & 0x3c) >> 2)
    tmp3 = ((index2 & 3) << 6) + index3
    tmps.append(tmp1)
    tmps.append(tmp2)
    tmps.append(tmp3)

for i in tmps:
    tmp = (((i & 0xf) << 4) & 0xff) + ((i & 0xf0) >> 4)
    flag += chr(tmp ^ 3)
print(flag+'}')
