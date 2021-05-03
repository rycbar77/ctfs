from math import gcd
from functools import reduce
from fractions import Fraction as Frac


N = 6

def read_num(prompt):
    try:
        num = int(input(prompt))
    except:
        return 0
    return num if num > 0 else 0


print(f"Please give me {N} pairs of positive integers (x,y,z) "
      f"satisfying the equation `x/(y+z) + y/(z+x) + z/(x+y) = {N}`\n")
anss = []
mark = 0
for i in range(N):
    x = read_num("[>] x: ")
    y = read_num("[>] y: ")
    z = read_num("[>] z: ")
    if x * y * z == 0: # positive integer
        mark = 1
        print("This is not what i want!\n")
        break
    if reduce(gcd, [x, y, z]) != 1: # (kx, ky, kz)
        mark = 1
        print("This is not what i want!\n")
        break
    if Frac(x, y+z) + Frac(y, z+x) + Frac(z, x+y) != N:
        mark = 1
        print("This is not what i want!\n")
        break
    ans = tuple(sorted([x, y, z])) # (y, x, z)
    if ans in anss:
        mark = 1
        print("This is not what i want!\n")
        break
    else:
        print("You are right!\n")
        anss.append(ans)
if mark == 0:
    flag = open('/flag', 'r').read()
    print("flag is: " + flag + "\n")
else:
    print("Something wrong!\n")
