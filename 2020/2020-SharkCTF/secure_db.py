target = "N3kviX7-vXEqvlp"
x = [0x1a, 0x07, 0x03, 0x41]
key = ""
for i, c in enumerate(target):
    key += chr(ord(c) ^ x[i % 4])
print(key)
# T4h7s_4ll_F0lks
