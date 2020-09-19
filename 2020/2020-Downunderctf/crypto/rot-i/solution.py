s="IAJBO{ndldie_al_aqk_jjrnsxee}"
tmp=5
for i in s:
    if 'a'<=i<='z':
        c=ord(i)-tmp
        if c<ord('a'):
            print(chr(ord('z')-(ord('a')-c)+1),end="")
        else:
            print(chr(c),end="")
    elif 'A'<=i<='Z':
        c=ord(i)-tmp
        if c<ord('A'):
            print(chr(ord('Z')-(ord('A')-c)+1),end="")
        else:
            print(chr(c),end="")
    else:
        print(i,end="")
    tmp=(tmp+1)%26
