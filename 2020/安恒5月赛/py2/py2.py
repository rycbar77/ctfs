# uncompyle6 version 3.7.0
# Python bytecode 2.7 (62211)
# Decompiled from: Python 3.8.2 (tags/v3.8.2:7b3ab59, Feb 25 2020, 22:45:29) [MSC v.1916 32 bit (Intel)]
# Embedded file name: byte.py
# Compiled at: 2020-04-23 16:22:50
import ctypes
from base64 import b64encode, b64decode

def decode():
    fd = open('./libc.so', 'rb')
    data = fd.read()
    fd.close()
    fd = open('./libc.so', 'wb')
    fd.write(b64decode(data))
    fd.close()


def check():
    if b64encode(pwd) == 'YmpkMw==':
        decode()
        dl = ctypes.cdll.LoadLibrary
        lib = dl('./libc.so')
        reply = lib.check
        reply(int(flag[:length // 2], 16), int(flag[length // 2:], 16), int(pwd.encode('hex'), 16))
        print 'your input is BJD{%s}' % flag.decode('hex')
    else:
        print 'your password is wrong!'


if __name__ == '__main__':
    print 'Please input your flag:'
    flag = raw_input()
    flag = flag.encode('hex')
    length = len(flag)
    print 'Please input your password:'
    pwd = raw_input()
    check()