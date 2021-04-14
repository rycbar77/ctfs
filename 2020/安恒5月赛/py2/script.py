import base64

fd = open('./libc.so', 'rb+')
data = fd.read()
# print(data)
fd.close()
fd = open('./libc1.so', 'wb+')
fd.write(base64.b64decode(data))
fd.close()
