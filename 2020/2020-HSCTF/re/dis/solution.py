target = b"\xae\xc0\xa1\xab\xef\x15\xd8\xca\x18\xc6\xab\x17\x93\xa8\x11\xd7\x18\x15\xd7\x17\xbd\x9a\xc0\xe9\x93\x11\xa7\x04\xa1\x1c\x1c\xed"
flag = ""
for i, c in enumerate(target):
    flag += chr((((c+30)^5)+105)//3)
print(flag)