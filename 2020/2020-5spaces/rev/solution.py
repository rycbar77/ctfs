target = [0x64, 0x25, 0x0F, 0x6C, 0x20, 0x23, 0x8A, 0xDE, 0x10, 0x0E, 0xA5, 0xE1, 0x43, 0x37, 0x11, 0x53]
for i, c in enumerate(target):
    c ^= i
    target[i] = c

# target = [100, 36, 13, 111, 36, 38, 140, 217, 24, 7, 175, 234, 79, 58, 31, 92]

for a in range(32, 128):
    for b in range(32, 128):
        for c in range(32, 128):
            for d in range(32, 128):
                x = (2 * a) ^ (2 * b) ^ b ^ c ^ d
                y = (2 * b) ^ (2 * c) ^ c ^ d ^ a
                z = (2 * c) ^ (2 * d) ^ d ^ a ^ b
                w = (2 * d) ^ (2 * a) ^ a ^ b ^ c
                if x == target[8] and y == target[9] and z == target[10] and w == target[11]:
                    print(a, b, c, d)
                    break

print(chr(114) + chr(104) + chr(95) + chr(103))
print(chr(111) + chr(97) + chr(105) + chr(48))
print(chr(112) + chr(105) + chr(115) + chr(48))
print(chr(99) + chr(110) + chr(95) + chr(100))
