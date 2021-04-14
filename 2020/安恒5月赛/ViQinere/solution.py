def handle(c):
    if ord('a') <= ord(c) <= ord('z'):
        return ord(c) - ord('a')
    elif ord('A') <= ord(c) <= ord('Z'):
        return (ord(c) - ord('A')) + 128
    else:
        return c


output = "FQD{GfjuJ5UbLrWjZjpvErXkiAZzlvO0xTa!cwnLLAsy3B0iEvEy}"
flag = ""
alphabet1 = []
alphabet2 = []
box = "TaQini"
for i in range(ord('a'), ord('z') + 1):
    alphabet1.append(i)
alphabet1.reverse()
for i in range(ord('A'), ord('Z') + 1):
    alphabet2.append(i)
alphabet2.reverse()
# print(alphabet1)
v5 = 0
for i, c in enumerate(output):
    if ord('a') <= ord(c) <= ord('z'):
        index = -1
        for j in range(26):
            if alphabet1[j] == ord(c):
                index = j
                break
        tmp = handle(box[v5 & 5]) & 0x7f
        v5 += 1
        if index >= tmp:
            flag += chr(ord('a') + index - tmp)
        else:
            flag += chr(ord('a') + index - tmp + 26)

    elif ord('A') <= ord(c) <= ord('Z'):
        index = -1
        for j in range(26):
            if alphabet2[j] == ord(c):
                index = j
                break
        tmp = handle(box[v5 & 5]) & 0x7f
        v5 += 1
        if index > tmp:
            flag += chr(ord('A') + index - tmp)
        else:
            flag += chr(ord('A') + index - tmp + 26)
    else:
        flag += c

print(flag)
# BJD{ThisI5MyViQiNireCiPheRHaveY0uTr!edtOBRut3F0rCeIt}