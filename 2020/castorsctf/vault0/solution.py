target="636173746f72734354467b72317854795f6d316e757433735f67745f73317874795f6d316e757433737d"
flag=""
for i in range(0,len(target),2):
    tmp=target[i:i+2]
    o=int(tmp,16)
    flag+=chr(o)
print(flag)