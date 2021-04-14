flag = "flag{h0w_m4ny_arms_d0_y0u_h4ve}"

p = ""
for i in range(len(flag)):
    if i & 1 is 1:
        p += chr(ord(flag[i])  ^ 66)
    else:
        p += flag[i]

print(p.encode('hex'))
