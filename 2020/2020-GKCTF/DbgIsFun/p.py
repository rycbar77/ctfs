s=b'\x01\x02\x03'
s1=b''
for i in s:
    s1+=bytes([i^0x8a])
    print(hex(i^0x8a))
print(s1)