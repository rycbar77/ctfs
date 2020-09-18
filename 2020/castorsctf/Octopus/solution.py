import base64
s = ""
with open('./obfus') as f:
    s = f.read()
d = base64.b64decode(s)

with open('./decrypted', 'wb') as f:
    f.write(d)
