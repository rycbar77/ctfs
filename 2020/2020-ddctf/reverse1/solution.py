from Crypto.Cipher import AES
from binascii import a2b_hex

_DELTA = 0x9E3779B9


def decrypt(str):
    if str == '': return str
    v = str
    k = [2, 2, 3, 4]
    n = len(v) - 1
    z = v[n]
    y = v[0]
    q = 6 + 52 // (n + 1)
    sum = (q * _DELTA) & 0xffffffff
    while (sum != 0):
        e = sum >> 2 & 3
        for p in range(n, 0, -1):
            z = v[p - 1]
            v[p] = (v[p] - ((z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (k[p & 3 ^ e] ^ z))) & 0xffffffff
            y = v[p]
        z = v[n]
        v[0] = (v[0] - ((z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (k[0 & 3 ^ e] ^ z))) & 0xffffffff
        y = v[0]
        sum = (sum - _DELTA) & 0xffffffff
    return v


t = [0x15ef75f4, 0xc4277b7a, 0xe7f4412d, 0x78e78345, 0xecf16de2, 0xd5d29477, 0x2169b3a0, 0x2a685baa]
target = decrypt(t)
s = ""
for i in target:
    tmp = hex(i)[2:].rjust(8, '0')
    s += tmp[-2:]
    s += tmp[-4:-2]
    s += tmp[-6:-4]
    s += tmp[-8:-6]
s = s.encode()


def decrypt(text):
    key = b"1234567890123456"
    # iv = b"\x9d\x25\xdd\xe0\xc1\x37\x86\x21\x32\xec\x0c\x32\x4c\xfb\xf0\x46"
    mode = AES.MODE_ECB
    cryptos = AES.new(key, mode)
    plain_text = cryptos.decrypt(a2b_hex(text))
    return plain_text


d = decrypt(s)
print("解密:", d)
