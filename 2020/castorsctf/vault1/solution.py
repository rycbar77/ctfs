import base64
encrypted = "ExMcGQAABzohNQ0TRQwtPidYAS8gXg4kAkcYISwOUQYS"
decrypted = base64.b64decode(encrypted)
xor = "promortyusvatofacidpromortyusvato"
flag = ""
for i, c in enumerate(decrypted):
    flag += chr(c ^ ord(xor[i]))
print(flag)
