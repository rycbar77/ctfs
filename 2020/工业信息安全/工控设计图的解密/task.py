
#python3.7
from random import randrange
from Crypto.Util.number import bytes_to_long
from secret import exp

def encrypt(exp, num):
	msg = bin(num)[2:]
	C, i = 0, 1
	for b in msg:
		C += int(b) * (exp**i + (-1)**i)
		i += 1
	try:
		enc = bytes.fromhex(hex(C)[2:].rstrip('L'))
	except:
		enc = bytes.fromhex('0'+hex(C)[2:].rstrip('L'))
	return enc

with open("flag.pic", "rb") as f:
	f = list(f.read())
lenf = len(f)
key = [randrange(1,255) for i in range(0x20)]
for i in range(lenf):
	f[i] = f[i] ^ key[i%0x20]
msg = bytes_to_long(bytes(f))
res = encrypt(exp, msg)
with open("flag.enc", "wb") as f:
	f.write(res)