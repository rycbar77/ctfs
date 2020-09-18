import base64
custom_map = "ZYXFGABHOPCDEQRSTUVWIJKLMNabczyxjklmdefghinopqrstuvw5670123489+/_{}"
normal_map = "ABCDEFGHIJKLMNOPQRSTUVWZYXzyxabcdefghijklmnopqrstuvw0123456789+/_{}"
encoded = "eHpzdG9yc1hXQXtpYl80cjFuMmgxNDY1bl80MXloMF82Ml95MDQ0MHJfNGQxbl9iNXVyMn0="
decoded = base64.b64decode(encoded)
flag = ""
for i in decoded:
    index = custom_map.index(chr(i))
    flag += normal_map[index]
print(flag)
#castorsCTF{my_7r4n5l4710n_74bl3_15_b3773r_7h4n_y0ur5}