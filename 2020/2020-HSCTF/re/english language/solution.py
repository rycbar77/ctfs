
def process(target):
    xor = [4, 1, 3, 1, 2, 1, 3, 0, 1, 4, 3, 1, 2, 0, 1, 4, 1, 2, 3, 2, 1, 0, 3]
    transpose = [11, 18, 15, 19, 8, 17, 5, 2, 12, 6,
                 21, 0, 22, 7, 13, 14, 4, 16, 20, 1, 3, 10, 9]
    f = []
    for i, c in enumerate(target):
        f.append(ord(c) ^ xor[i])
    fl = [0 for i in range(23)]

    for i, c in enumerate(transpose):
        fl[c] = f[i]
    ret = "".join([chr(i) for i in fl])
    return ret


target = "1dd3|y_3tttb5g`q]^dhn3j"
for i in range(3):
    target = process(target)
print(target)
