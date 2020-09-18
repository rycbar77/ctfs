target = "inagzgkpm)Wl&Tg&io"
flag = ""
for i, c in enumerate(target):
    tmp = ord(c)
    if tmp > 100:
        tmp -= 3
    else:
        tmp -= 2
    tmp += i
    flag += chr(tmp)
print(flag)
