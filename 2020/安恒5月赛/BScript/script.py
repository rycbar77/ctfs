import os


def get_FileSize(filePath):
    fsize = os.path.getsize(filePath)
    return fsize

program = b""
script=b""
for i in range(804):
    if get_FileSize('%d.exe' % i) == 48643:
        with open('%d.exe'%i, 'rb') as f:
            f.read(0x1c40)
            ff = list(f.read(0x40))
            ff.reverse()
            program += bytes(ff)
    elif get_FileSize('%d.exe' % i) == 48625:
        with open('%d.exe'%i, 'rb') as f:
            f.read(0x1c20)
            ff = list(f.read(0x20))
            program += bytes(ff)
    else:
        print(get_FileSize('%d.exe' % i))
with open('easy.exe','wb+') as f:
    f.write(program)