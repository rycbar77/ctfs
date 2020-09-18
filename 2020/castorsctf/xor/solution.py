target = b"gh}w_{aPDSmk$ch&r+Ah-&F|\x14\x7a\x11\x50\x15\x10\x1d\x52\x1e"
flag = ""
for i, c in enumerate(target):
    tmp = c + 2
    flag += chr(tmp ^ (i + 10))
print(flag)
# castorsCTF{x0rr1n6_w17h_4_7w157}